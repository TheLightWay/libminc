#include <stdio.h>
#include <string.h>
#include <shared/syscalls.h>

int fputc(int c, FILE *f)
{
    __acquire_lock(f);

    sys_write(f->fd, &c, sizeof(c));

    __release_lock(f);

    return c;
}
