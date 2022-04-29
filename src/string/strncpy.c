#include <string.h>

char *strncpy(char *dest, const char *src, size_t n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        dest[i] = src[i];

        if (src[i] == 0)
            break;
    }

    for (; i < n; i++)
        dest[i] = 0;

    return NULL;
}
