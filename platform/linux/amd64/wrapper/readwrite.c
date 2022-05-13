
#include "../include/sys/syscall.h"

extern long syscall(long number, ...);

typedef unsigned long size_t;
typedef long ssize_t;

ssize_t read(int fd, void *buf, size_t count)
{
    return syscall(SYS_read, fd, buf, count);
}

ssize_t write(int fd, const void *buf, size_t count)
{
    return syscall(SYS_write, fd, buf, count);
}
