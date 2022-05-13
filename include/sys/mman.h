#ifndef __SYS_MMAN_H
#define __SYS_MMAN_H

#define PROT_NONE       0x0
#define PROT_READ       0x1
#define PROT_WRITE      0x2
#define PROT_EXEC       0x4
#define MAP_ANONYMOUS   0x20
#define MAP_SHARED      0x01
#define MAP_PRIVATE     0x02

typedef long off_t;

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int munmap(void *addr, size_t length);

#endif /* __SYS_MMAN_H */
