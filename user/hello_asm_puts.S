.text
.global main
main:
    addi sp, sp, -8
    sd ra, (sp)
    la a0, hello_str
    jal ra, puts
    ld ra, (sp)
    addi sp, sp, 8
    jalr zero, ra

.section .rodata
hello_str:
    .asciz "Hello, world!"
