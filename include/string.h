#ifndef __STRING_H
#define __STRING_H

#include "types/size_t.h"

/* return the length of str */
size_t strlen(const char *str);

/* compare two strings */
int strcmp(const char *str1, const char *str2);

#endif /* __STRING_H */