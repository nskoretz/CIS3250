
CC          =	gcc
# Flags that are sent to the compiler  change the std if you wish

CFLAGS      =	-Wall -std=c99 -g
BIN_DIR = "./bin"

all:
	if [ ! -d $(BIN_DIR) ]; then \
		mkdir $(BIN_DIR);\
	fi
	$(CC) $(CFLAGS) src/*.c -Iinclude -o bin/calculator

clean:
	rm -rf bin/*