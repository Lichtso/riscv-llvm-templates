.text
.section .text.init,"ax",@progbits
_start:
.globl _start
.type _start,@function
.p2align 2
    jal main
    jal exit
    j 0
.size _start, . - _start
