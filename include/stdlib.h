#ifndef __STDLIB_H
#define __STDLIB_H

/* types */
#include "types/size_t.h"

/* constants */
#include "constants/NULL.h"

/* exit the program, return exit_status */
void exit(int exit_status);

/* return space on the stack of n size */
void *malloc(size_t n);

/* free memory allocated by malloc */
void free(void *m);

#endif /* __STDLIB_H */