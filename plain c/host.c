#include <stdlib.h>
#include <dlfcn.h>

typedef void* module_main_func(void* data);

int main(void){
    void* state = NULL;

    while(true) {
        // Load the library, and look up the module_main() function pointer.
        void* module = dlopen("module.dylib", RTLD_NOW);
        module_main_func* module_main = dlsym(module, "module_main");

        // Run the module's code, and save a reference to it's heap data.
        state = module_main(state);

        // Get ready to hot-load the module again by first closing the library.
        dlclose(module);
    }

    return EXIT_SUCCESS;
}

