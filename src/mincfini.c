#include <stdio.h>

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

void mincfini()
{
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
}