#include <stdlib.h>
#include <assembly/syscalls.h>

#include "htype.h"

void *malloc(size_t n)
{
    void *block;
    
    block = sys_mmap(NULL, n + HSIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    ((HTYPE*)block)[0] = n;

    block = (char *)block + HSIZE;

    return block;
}