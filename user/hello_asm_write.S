#include "kernel/syscall.h"

.text
.global main
main:
    li a0, 1
    la a1, hello_str
    li a2, 14
    li a7, SYS_write
    ecall
    jalr zero, ra

.section .rodata
hello_str:
    .ascii "Hello, world!\n"
