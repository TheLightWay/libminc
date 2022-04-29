
    .global sys_read
sys_read:
    movq $0, %rax
    syscall
    ret

    .global sys_write
sys_write:
    movq $1, %rax
    syscall
    ret

    .global sys_open
sys_open:
    movq $2, %rax
    syscall
    ret

    .global sys_close
sys_close:
    movq $3, %rax
    syscall
    ret

    .global sys_mmap
sys_mmap:
    movq $9, %rax
    movq %rcx, %r10
    syscall
    ret

    .global sys_munmap
sys_munmap:
    movq $11, %rax
    syscall
    ret

    .global sys_exit_group
sys_exit_group:
    movq $231, %rax
    syscall
    ret
