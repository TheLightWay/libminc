#include <stdio.h>
#include <string.h>

int puts(const char *str)
{
    int count = 0;
    count += fputs(str, stdout);
    count += fputs("\n", stdout);

    return count;
}
