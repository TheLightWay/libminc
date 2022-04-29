#include <stdio.h>
#include <string.h>
#include <shared/syscalls.h>

int putc(int c, FILE *f)
{
    __acquire_lock(f);

    /* this might be a very little-endian implementation
     * little-endian: strlen(01 00 00 00) = 1
     * big-endian   : strlen(00 00 00 01) = 0
     * testing is required */
    sys_write(f->fd, &c, strlen((char*)&c));

    __release_lock(f);

    return c;
}
