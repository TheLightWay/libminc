#include <stdio.h>
#include <stdlib.h>
#include <shared/syscalls.h>

void fclose(FILE *f)
{
    sys_close(f->fd);
    free(f);
}
