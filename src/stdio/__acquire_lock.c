#include <stdio.h>

extern void atomic_equ(int *l, int val);

void __acquire_lock(FILE *f)
{
    /* wait for lock to be released */
    while (f->lock);

    atomic_equ(&f->lock, 1);
}
