
#include "../include/sys/syscall.h"

extern long syscall(long number, ...);
typedef long mode_t;

int open(const char *pathname, int flags, mode_t mode)
{
    return syscall(SYS_open, pathname, flags, mode);
}

int close(int fd)
{
    return syscall(SYS_close, fd);
}
