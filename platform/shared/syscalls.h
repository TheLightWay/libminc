#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "types.h"

/* read from object with file descriptor */
ssize_t sys_read(int fd, void *buf, size_t count);

/* write to object with file descriptor */
ssize_t sys_write(int fd, const void *buf, size_t count);

#define O_RDONLY    00
#define O_WRONLY    01
#define O_RDWR      02
#define O_CREAT     0100
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
/* allocate memory to the heap */
void *sys_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

/* deallocate memory allocated with sys_mmap */
void sys_munmap(void *addr, size_t length);

/* thread safe exit */
void sys_exit_group(int status) __attribute__((__noreturn__));

#endif /* SYSCALLS_H */
