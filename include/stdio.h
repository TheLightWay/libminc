#ifndef __STDIO_H
#define __STDIO_H

/* types */
#include "types/size_t.h"
#include "types/FILE.h"

/* constants */
#include "constants/NULL.h"


/* globals */
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

/* print str to stdout */
int puts(const char *str);

/* print str to f */
int fputs(const char *str, FILE *f);

/* open file */
FILE *fopen(const char *path, const char *mode);

/* close file */
void fclose(FILE *f);

/* private */
void __acquire_lock(FILE *f);
void __release_lock(FILE *f);

#endif /* __STDIO_H */