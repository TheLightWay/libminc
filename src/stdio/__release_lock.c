#include <stdio.h>

void __release_lock(FILE *f)
{
    f->lock = 0;
}