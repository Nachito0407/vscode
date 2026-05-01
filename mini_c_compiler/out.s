.globl main
main:
    mov $4, %rax
    push %rax
    mov $3, %rax
    pop %rbx
    imul %rbx, %rax
    push %rax
    mov $2, %rax
    pop %rbx
    add %rbx, %rax
    ret
