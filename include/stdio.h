#ifndef __STDIO_H
#define __STDIO_H

/* types */
#include "types/size_t.h"
#include "types/FILE.h"
#include "types/fpos_t.h"

/* constants */
#include "constants/NULL.h"
#include "constants/EOF.h"

/* globals */
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

#define stdin stdin
#define stdout stdout
#define stderr stderr

/* print str to stdout */
int puts(const char *str);

/* print str to f */
int fputs(const char *str, FILE *f);

/* print c to stdout */
int putchar(int c);

/* print c to f */
int fputc(int c, FILE *f);

/* print c to f */
int putc(int c, FILE *f);

/* open file */
FILE *fopen(const char *path, const char *mode);

/* close file */
void fclose(FILE *f);

/* private */
void __acquire_lock(FILE *f);
void __release_lock(FILE *f);

#endif /* __STDIO_H */
