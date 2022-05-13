#include <stdio.h>
#include <string.h>
#include <unistd.h>

int putc(int c, FILE *f)
{
    __acquire_lock(f);

    write(f->fd, &c, sizeof(c));

    __release_lock(f);

    return c;
}
