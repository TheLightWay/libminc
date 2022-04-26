#include <stdlib.h>
#include <assembly/syscalls.h>

#include "htype.h"

void free(void *mem)
{
    char *memptr = mem;
    HTYPE size;

    memptr = memptr - HSIZE;

    size = ((HTYPE*)memptr)[0];

    sys_munmap(memptr, size);
}