# Platform
This is the platform specific code.

## shared
this directory contains code that is shared across operating systems.
Most Unix and Unix-like systems share the same syscall names, so it makes
sense to add them all to a single header file in `shared/syscalls.h`.

Each syscall in this directory acts pretty much the same as its equivalent
from `unistd.h`. The only exception is this straight up calls the syscall,
so there is no wrapper for it. (`unistd.h` likes to add error handling and such)
The syscalls are essentially less standard than what you get from `unistd.h`
but it is important to have access to the syscalls directly.

# How to add a platform
every platform has an OS directory, and then has an architecture folder.
ex: `linux/amd64` is the directory for x86_64 Linux platforms. In
this directory, there are 2 files: `_start.S` and `syscalls.S`.

`_start.S` will define \_start: the entry point of the program for each OS.
the entry point should run the init function, call main, run the fini function,
and exit the program using exit.

`syscalls.S` will define wrappers for every syscall in the operating system.

## what does a wrapper look like?
Lets take a look. It will have 3 parts. Lets look at an amd64 linux syscall
in steps:

1. put the id for the syscall into register `rax`.
2. move registers from the register c puts them into to the register the syscall
uses
3. run `syscall` to invoke the OS

Notes:
 - `rax` is used for Linux syscalls. It may be different for other operating systems.
 - Sometimes, the arguments already match up and step 2 is unecessary.
 - In x86, syscall is not an instruction, use `int $0x80` in Linux x86 for example
 - Don't forget to make it global! This makes it visible outside of the file it's in.

```x86asm
    .global sys_write
sys_write:
    mov $1, %rax
    syscall
    ret
```

You can tell from the notes alone that making a syscall may be very different
across operating systems and architectures. Be sure to read the docs on your platform.
