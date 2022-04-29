#include <string.h>

void *memmove(void *dest, const void *src, size_t n)
{
    /* TODO: implement an overlap safe move */
    return memcpy(dest, src, n);
}
