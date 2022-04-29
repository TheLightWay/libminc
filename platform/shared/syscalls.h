#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "types.h"

/* read from object with file descriptor */
ssize_t sys_read(int fd, void *buf, size_t count);

/* write to object with file descriptor */
ssize_t sys_write(int fd, const void *buf, size_t count);

#define O_RDONLY    0x0
#define O_WRONLY    0x1
#define O_RDWR      0x2
#define O_APPEND    0x400
#define O_ASYNC     0x2000
#define O_CLOEXEC   0x80000
#define O_CREAT     0x40
#define O_DIRECTORY 0x10000
#define O_DSYNC     0x1000
#define O_EXCL      0x80
#define O_NOCTTY    0x100
#define O_NOFOLLOW  0x20000
#define O_NONBLOCK  0x800
#define O_NDELAY    0x800
#define O_SYNC      0x101000
#define O_TRUNC     0x200

#define S_IRWXU     0x1c0
#define S_IRUSR     0x100
#define S_IWUSR     0x80
#define S_IXUSR     0x40
#define S_IRGRP     0x20
#define S_IWGRP     0x10
#define S_IXGRP     0x8
#define S_IRWXO     0x7
#define S_IROTH     0x4
#define S_IWOTH     0x2
#define S_IXOTH     0x1
#define S_ISUID     0x800
#define S_ISGID     0x400
#define S_ISVTX     0x200

/* open file */
int sys_open(const char *pathname, int flags, ...);

/* close file */
int sys_close(unsigned int fd);

#define PROT_NONE       0x0
#define PROT_READ       0x1
#define PROT_WRITE      0x2
#define PROT_EXEC       0x4
#define MAP_ANONYMOUS   0x20
#define MAP_SHARED      0x01
#define MAP_PRIVATE     0x02

/* allocate memory on the heap */
void *sys_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

/* deallocate memory allocated with sys_mmap */
void sys_munmap(void *addr, size_t length);

/* thread safe exit */
void sys_exit_group(int status) __attribute__((__noreturn__));

#endif /* SYSCALLS_H */
