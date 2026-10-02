.intel_syntax noprefix

.equ STDOUT_FILENO, 1
.equ EXIT_SUCCESS, 0
.equ SYS_EXIT, 60
.equ SYS_WRITE, 1

.section .rodata
	msg:
		.asciz "Hello, world, by Dadivaldo!\n"
	len = . - msg

.text
.global _start
_start:

	mov rax, SYS_WRITE 
	mov rdi, STDOUT_FILENO
	lea rsi, msg
	mov rdx, len
	syscall

	mov rax, SYS_EXIT
	mov rsi, EXIT_SUCCESS
	syscall
