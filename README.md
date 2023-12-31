I know it says "Unix and Unix-like operating systems" but as of now it only supports Linux. pls don't hurt me.

# what this project is
This is my attempt at a C Standard Library that is meant to be easy to read and hack.
One thing I've noticed with most libraries is that they are incredibly hard to follow along with and require a lot of reading to figure out how it's actually structured.

## directory tree
```
include/        header files for the library
src/            source files for the library
platform/       platform specific code
```

### notes
`src/` contains every function in it's own `.c` file, contained in a folder named after the header file you import to use it. For example: `puts` is stored in [src/stdio/puts.c](src/stdio/puts.c).

# using this library
### To build the library, run
```console
$ make
```

### to install, run
```console
$ sudo make install
```
this library will not override glibc or whatever library you have currently installed on your system. so using it will require you to do some extra compilation trickery to disable the standard library and link with mine.

### to compile your project and use this library, run
```console
$ gcc -nostdlib -nostdinc -I /usr/include/minc [other arguments] [files] -lminc -l:libcrt1.o
```

#### how does this work?
```
-nostdlib               disable linking with glibc
-nostdinc               don't use any default include directories
-I /usr/include/minc    set /usr/include/minc as an include directory
-lminc                  dynamically link libminc with your program
-l:libminc.a            statically link libminc.a with your program, this includes _start
```

### and finally, to uninstall, run
```console
$ sudo make uninstall
```

### libminc doesn't support your platform?
If you want support for your platform:
 1. add support yourself, see `platform/CONTRIBUTING.md`
 2. request support (aprilkahny@gmail.com)

# I am not a professional
Do not think this is better code than glibc or any other implementation. I am stupid. This is an honest attempt, and it would take a long time before it becomes an honest replacement for any established library.
