# Platform
this is the platform specific code.

every platform has a directory, and then has an architecture folder.
example: `linux/amd64`. this is the directory for x86_64 linux platforms. in
this directory, there are 2 files. `_start.S` and `syscalls.S`.

`_start.S` will define _start. the entry point of the program for each OS.

`syscalls.S` will define wrappers for every syscall in the operating system.

## what does the wrapper look like?
lets take a look. it will have 3 parts. lets look at an amd64 linux syscall
in steps

1. put the id for the syscall into register `rax`.
2. move registers from the register c puts them into to the register the syscall
uses
3. run `syscall` to invoke the OS
