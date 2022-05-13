#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fclose(FILE *f)
{
    close(f->fd);
    free(f);
}
