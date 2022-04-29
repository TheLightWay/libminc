# Platform
This is the platform specific code.

every platform has an OS directory, and then has an architecture folder.
ex: `linux/amd64` is the directory for x86_64 Linux platforms. In
this directory, there are 2 files: `_start.S` and `syscalls.S`.

`_start.S` will define \_start: the entry point of the program for each OS.
the entry point should run the init function, call main, run the fini function,
and exit the program using exit.

`syscalls.S` will define wrappers for every syscall in the operating system.

## what does the wrapper look like?
Lets take a look. It will have 3 parts. Lets look at an amd64 linux syscall
in steps:

1. put the id for the syscall into register `rax`.
2. move registers from the register c puts them into to the register the syscall
uses
3. run `syscall` to invoke the OS

Note that sometimes you won't need to move any arguments. Sometimes, they already match up.
```x86asm
sys_write:
    mov $1, %rax
    syscall
    ret
```
