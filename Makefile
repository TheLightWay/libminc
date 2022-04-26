
CC=gcc
CFLAGS=-Wall -Werror -O3 -std=c89 -pedantic -nostdlib -nostdinc -I./include

all: libminc.so libminc.a

LIBRARY_FUNCTIONS=$(shell find "./src" -name "*.c")

libminc.so: $(LIBRARY_FUNCTIONS) src/syscalls.S
	$(CC) $(CFLAGS) -c -fpic $^
	$(CC) -shared -o $@ *.o

libminc.a: src/_start.S src/syscalls.S
	$(CC) $(CFLAGS) -c $^
	ld -relocatable _start.o syscalls.o -o $@

remove_objects:
	$(RM) *.o

clean:
	$(RM) *.a *.so *.o

install: all
	cp libminc.so libminc.a /usr/lib/
	cp -r include/ /usr/include/minc/

uninstall:
	$(RM) /usr/lib/libminc.so /usr/lib/libminc.a
	$(RM) -r /usr/include/minc/
