#include <stdlib.h>
#include <string.h>

void *calloc(size_t count, size_t sz)
{
	void *memptr = malloc(count * sz);
	memset(memptr, 0x0, count * sz);

	return memptr;
}
