#Made by Ori Talmor

CC = gcc
CFLAGS = -Wall -Iinclude -g -std=c99

test: makebin
	$(CC) $(CFLAGS) -o bin/runTests -Llib src/*.c 
    
makebin:
	mkdir -p bin
    
#run cppcheck
cppcheck:
	cppcheck --enable=all --language=c --std=c99 --inconclusive --suppress=missingInclude src/*.c -i ./include
    
doxy: Doxyfile
	doxygen

clean: 
	rm bin/*    
