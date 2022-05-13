#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

FILE *fopen(const char *path, const char *mode)
{
    FILE *f = malloc(sizeof(FILE));

    if (!strcmp(mode, "r"))
        f->fd = open(path, O_RDONLY);
    else if (!strcmp(mode, "w"))
        f->fd = open(path, O_WRONLY | O_CREAT);
    else if (!strcmp(mode, "r+"))
        f->fd = open(path, O_RDWR);

    f->lock = 0;

    return f;
}
