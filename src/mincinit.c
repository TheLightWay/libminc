#include <stdio.h>

FILE *stdin;
FILE *stdout;
FILE *stderr;

void mincinit()
{
    stdin = fopen("/dev/stdin", "r");
    stdout = fopen("/dev/stdout", "w");
    stderr = fopen("/dev/stderr", "w");
}