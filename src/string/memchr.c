#include <string.h>

const void *memchr(const void *str, int c, size_t n)
{
    const char *buff = str;
    int i;

    for (i = 0; i < n; i++)
    {
        if (*buff == c)
            return buff;

        buff++;
    }

    return NULL;
}
