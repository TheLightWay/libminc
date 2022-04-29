#include <stdio.h>
#include <string.h>
#include <shared/syscalls.h>

int fputs(const char *str, FILE *f)
{
    int count;
    __acquire_lock(f);

    count = sys_write(f->fd, str, strlen(str));

    __release_lock(f);
    return count;
}
