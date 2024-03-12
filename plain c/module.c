#include <stdio.h>
#include <stdlib.h>

static const int number = 2;

typedef struct {
    int last_number;
} GameState;

void* module_main(void* saved_state) {
    GameState* game_state = saved_state;

    if (game_state == NULL){
        game_state = malloc(1, sizeof(*game_state));
        printf("Welcome to the number guessing game.\n");
    } else {
        printf("Welcome back!\nLast time the number was %d\n", game_state->last_number);
    }

    printf("Try and guess the forbidden number if you dare.\n");

    while(1) {
        printf("Guess the number (0-9): ");

        int c = getchar();
        printf("\n");
        unsigned n = c - '0';

        if (n == number) {
            printf("That number is forbidden. Enjoy your doom!\n");
            printf("Please change the hardcoded number in the code and recompile to play again.\n");
            printf("Press nearly any key to quit.\n");

            getchar();

            return game_state;
        } else if (n <= 9) {
            const char* hi_lo = (n < number ? "too low" : "too high");
            printf("You guessed the number %d, which is %s.\n", n, hi_lo);
        } else {
            printf("Is that a number? Please concentrate and try again.\n");
        }
    }

    return NULL;
}

