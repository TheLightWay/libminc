#include <stdio.h>

FILE *stdin;
FILE *stdout;
FILE *stderr;

int errno;

void mincinit()
{
    errno = 0;

    stdin = fopen("/dev/stdin", "r");
    stdout = fopen("/dev/stdout", "w");
    stderr = fopen("/dev/stderr", "w");
}
