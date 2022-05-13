
#include "../include/sys/syscall.h""

extern long syscall(long number, ...);

typedef unsigned long size_t;
typedef long off_t;

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    return syscall(SYS_mmap, addr, length, prot, flags, fd, offset);
}

int munmap(void *addr, size_t length)
{
    return syscall(SYS_munmap, addr, length);
}
