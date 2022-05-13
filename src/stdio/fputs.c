#include <stdio.h>
#include <string.h>
#include <unistd.h>

int fputs(const char *str, FILE *f)
{
    int count;
    __acquire_lock(f);

    count = write(f->fd, str, strlen(str));

    __release_lock(f);
    return count;
}
