
CFLAGS=-Wall -g -O0 -std=c89 -pedantic \
	-nostdlib -nostdinc -nostartfiles \
	-I./include -I./platform

# must be the path to platform/OS/ARCH
PLATFORM=./platform/linux/amd64

LIBRARY_FUNCTIONS=$(shell find "./src" -name "*.c")
PLATFORM_WRAPPER=$(shell find $(PLATFORM)/wrapper/ -name "*.c")

all: $(PLATFORM) include/sys/syscall.h libminc.so mincrt1.o

include/sys/syscall.h: $(PLATFORM)/include/sys/syscall.h
	cp $^ $@

libminc.so: $(LIBRARY_FUNCTIONS) $(PLATFORM_WRAPPER)
	$(CC) $(CFLAGS) -c -fpic $^
	$(CC) -shared -o $@ *.o

mincrt1.o: $(PLATFORM)/_start.S $(PLATFORM)/syscall.S $(PLATFORM)/atomic.S
	$(CC) $(CFLAGS) -c $^
	ld -relocatable _start.o syscall.o atomic.o -o $@

clean:
	$(RM) *.a *.so *.o include/sys/syscall.h

install:
	cp libminc.so mincrt1.o /usr/lib/
	cp -r include/ /usr/include/minc

uninstall:
	$(RM) -r /usr/include/minc/ /usr/lib/libminc.so /usr/lib/mincrt1.o
