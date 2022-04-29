#include <stdlib.h>
#include <shared/syscalls.h>

void exit(int exit_status)
{
    sys_exit_group(exit_status);
}
