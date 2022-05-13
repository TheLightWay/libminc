
#include "../include/sys/syscall.h""

extern long syscall(long number, ...);

void exit(int exit_status)
{
    syscall(SYS_exit_group, exit_status);
}
