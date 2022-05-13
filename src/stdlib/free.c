#include <stdlib.h>
#include <sys/mman.h>

#include "htype.h"

void free(void *mem)
{
    char *memptr = mem;
    HTYPE size;

    memptr = memptr - HSIZE;

    size = ((HTYPE*)memptr)[0];

    munmap(memptr, size + HSIZE);
}
