	.file	"hwk4.c"
	.section	.rodata
	.align 8
.LC0:
	.string	"error - not enough arguments.\n\n\tusage: hwk4 funcname arg1 arg2 arg3 ...\n"
.LC1:
	.string	"%ld"
.LC2:
	.string	"mul_20"
.LC3:
	.string	"%ld\n"
.LC4:
	.string	"longlog"
.LC5:
	.string	"collatz"
.LC6:
	.string	"prime"
.LC7:
	.string	"caller"
.LC8:
	.string	"sum_primes"
	.align 8
.LC9:
	.string	"error - unrecognized command '%s'.\n"
	.text
.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	cmpl	$2, -68(%rbp)
	jg	.L2
	.cfi_offset 3, -24
	movl	$.LC0, %edi
	call	puts
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	$.LC1, %ecx
	movq	-80(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	leaq	-56(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC2, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L4
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	mul_20
	movq	%rax, %rdx
	movl	$.LC3, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L4:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC4, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L6
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	longlog
	movq	%rax, %rdx
	movl	$.LC3, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L6:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC5, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L7
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	collatz
	movq	%rax, %rdx
	movl	$.LC3, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L7:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC6, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L8
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	prime
	movq	%rax, %rdx
	movl	$.LC3, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L8:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC7, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L9
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	movl	$.LC1, %ecx
	movq	-80(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rax
	leaq	-64(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	movq	-64(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	caller
	movq	%rax, %rdx
	movl	$.LC3, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	jmp	.L5
.L9:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC8, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L10
	movq	%rsp, %rax
	movq	%rax, %rbx
	movq	-56(%rbp), %rax
	leaq	-1(%rax), %rdx
	movq	%rdx, -48(%rbp)
	salq	$3, %rax
	addq	$15, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$15, %rax
	shrq	$4, %rax
	salq	$4, %rax
	movq	%rax, -40(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L11
.L12:
	movq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	leaq	(%rax,%rdx), %rdx
	movl	$.LC1, %ecx
	movl	-20(%rbp), %eax
	cltq
	addq	$3, %rax
	salq	$3, %rax
	addq	-80(%rbp), %rax
	movq	(%rax), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	addl	$1, -20(%rbp)
.L11:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-56(%rbp), %rax
	cmpq	%rax, %rdx
	jl	.L12
	movq	-40(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	sum_primes
	movq	%rax, %rdx
	movl	$.LC3, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movq	%rbx, %rsp
	jmp	.L5
.L10:
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	$.LC9, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	$2, %eax
	jmp	.L3
.L5:
	movl	$0, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-17)"
	.section	.note.GNU-stack,"",@progbits
