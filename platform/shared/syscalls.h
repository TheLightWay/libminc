#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "types.h"

ssize_t sys_read(int fd, void *buf, size_t count);
ssize_t sys_write(int fd, const void *buf, size_t count);

#define O_RDONLY    00
#define O_WRONLY    01
#define O_RDWR      02
#define O_CREAT     0100
int sys_open(const char *pathname, int flags, ...);

int sys_close(unsigned int fd);

#define PROT_NONE       0x0
#define PROT_READ       0x1
#define PROT_WRITE      0x2
#define PROT_EXEC       0x4
#define MAP_ANONYMOUS   0x20
#define MAP_SHARED      0x01
#define MAP_PRIVATE     0x02
void *sys_mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
void sys_munmap(void *addr, size_t length);

void sys_exit_group(int status) __attribute__((__noreturn__));

#endif /* SYSCALLS_H */
