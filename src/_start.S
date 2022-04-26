    .text

/* ======== _START ======== */
    .global _start
    .type	_start, @function
_start:
    # initialization code, allocates stdin, stdout, stderr
    # initializes global variables
    call    mincinit

    # move argc  and argv onto registers and then call main
    mov     (%rsp),     %rdi
    lea     8(%rsp),    %rsi
    lea     16(%rsp),   %rdx
    call    main

    # reuse this position on the heap to store the return of main
    mov     %rax,       (%rsp)

    # finalize code
    call    mincfini

    # exit gracefully
    mov     (%rsp),     %rdi
    call    exit
    hlt
    .size	_start, .-_start
