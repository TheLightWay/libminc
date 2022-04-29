#ifndef __STRING_H
#define __STRING_H

/* types */
#include "types/size_t.h"

/* constants */
#include "constants/NULL.h"

/* find first occurence of c in str up to n */
const void *memchr(const void *str, int c, size_t n);

/* compares first n bytes of str1 and str2 */
int memcmp(const void *str1, const void *str2, size_t n);

/* copies first n bytes from src to dest */
void *memcpy(void *dest, const void *src, size_t n);

/* copies first n bytes from src to dest */
void *memmove(void *dest, const void *src, size_t n);

/* set n bytes of str to c */
void *memset(void *str, int c, size_t n);

/* append src to dest */
char *strcat(char *dest, const char *src);

/* find first occurence of c in str */
const char *strchr(const char *str, int c);

/* append src to dest up to n */
char *strncat(char *dest, const char *src, size_t n);

/* copy src to dest */
char *strcpy(char *dest, const char *src);

/* copy src to dest up to n */
char *strncpy(char *dest, const char *src, size_t n);

/* return the length of str */
size_t strlen(const char *str);

/* compare two strings */
int strcmp(const char *str1, const char *str2);

#endif /* __STRING_H */
