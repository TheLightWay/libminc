#include <stdio.h>
#include <string.h>
#include <assembly/syscalls.h>

int fputs(const char *str, FILE *f)
{
    int count = 0;
    __acquire_lock(f);

    count += sys_write(f->fd, str, strlen(str));

    __release_lock(f);
    return count;
}