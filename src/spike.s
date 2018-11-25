.section .stack,"aw",@nobits
stack:
.globl stack
    .skip 0x10000
.globl stack_end
.type stack_end,@object
stack_end:
.size stack, . - stack

.text
.section .text.init,"ax",@progbits
_start:
.globl _start
.type _start,@function
.p2align 2
    lui sp, %hi(stack_end)
    jal main
    jal exit
    j 0
.size _start, . - _start
