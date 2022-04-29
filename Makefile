
CC=gcc
CFLAGS=-Wall -O2 -std=c89 -pedantic -nostdlib -nostdinc -I./include -I./platform
LIBRARY_FUNCTIONS=$(shell find "./src" -name "*.c")

# must be the path to ./platform/OS/ARCH
PLATFORM=./platform/linux/amd64

all: libminc.so libminc.a cleanc

libminc.so: $(LIBRARY_FUNCTIONS) $(PLATFORM)/_start.S $(PLATFORM)/syscalls.S
	$(CC) $(CFLAGS) -c -fpic $^
	$(CC) -shared -o $@ *.o

libminc.a: $(PLATFORM)/_start.S $(PLATFORM)/syscalls.S
	$(CC) $(CFLAGS) -c $^
	ld -relocatable _start.o syscalls.o -o $@

# the c means nothing, this is just to clean the .o files while also letting clean
# be for everything
cleanc:
	$(RM) *.o

clean:
	$(RM) *.a *.so *.o

install:
	cp libminc.so libminc.a /usr/lib/
	cp -r include/ /usr/include/minc/

uninstall:
	$(RM) /usr/lib/libminc.so /usr/lib/libminc.a
	$(RM) -r /usr/include/minc/
