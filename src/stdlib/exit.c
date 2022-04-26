#include <stdlib.h>
#include <assembly/syscalls.h>

void exit(int exit_status)
{
    sys_exit_group(exit_status);
}