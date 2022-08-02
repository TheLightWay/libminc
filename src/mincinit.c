#include <stdio.h>

FILE *stdin;
FILE *stdout;
FILE *stderr;

__thread int errno;

FILE __stdin = { 0, 0 };
FILE __stdout = { 1, 0 };
FILE __stderr = { 2, 0 };

void mincinit()
{
    errno = 0;

    stdin = &__stdin;
    stdout = &__stdout;
    stderr = &__stderr;
}
