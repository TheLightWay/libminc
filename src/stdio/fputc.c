#include <stdio.h>
#include <shared/syscalls.h>

int fputc(int c, FILE *f)
{
    __acquire_lock(f);

    sys_write(f->fd, &c, 1);

    __release_lock(f);

    return c;
}
