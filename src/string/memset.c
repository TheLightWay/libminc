#include <string.h>

void *memset(void *str, int c, size_t n)
{
    int i;

    for (i = 0; i < n; i++)
        ((char*)str)[i] = (char)c;

    return str;
}
