#include <stdio.h>

extern void atomic_equ(int *l, int val);

void __release_lock(FILE *f)
{
    atomic_equ(&f->lock, 0);
}
