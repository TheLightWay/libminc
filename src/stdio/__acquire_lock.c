#include <stdio.h>

void __acquire_lock(FILE *f)
{
    /* wait for lock to be released */
    while (f->lock);
    f->lock = 1;
}