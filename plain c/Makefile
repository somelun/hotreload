all: module host

module: module.c
	$(CC) $^ -dynamiclib -o module.dylib

host: host.c
	$(CC) $^ -o $@

clean:
	rm host module.dylib
