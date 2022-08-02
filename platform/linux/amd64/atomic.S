
    .global atomic_equ
    .type   atomic_equ, @function
atomic_equ:
    mov %esi, %eax
    xchgl (%rdi), %eax

    ret
    .size   atomic_equ, .-atomic_equ
