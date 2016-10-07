	.file	"hwk4.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
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
	.file 1 "hwk4.c"
	.loc 1 18 0
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
	.loc 1 20 0
	cmpl	$2, -68(%rbp)
	jg	.L2
	.cfi_offset 3, -24
	.loc 1 21 0
	movl	$.LC0, %edi
	call	puts
	.loc 1 22 0
	movl	$1, %eax
	jmp	.L3
.L2:
	.loc 1 27 0
	movl	$.LC1, %ecx
	movq	-80(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	leaq	-56(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	.loc 1 30 0
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC2, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L4
	.loc 1 31 0
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
	.loc 1 33 0
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC4, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L6
	.loc 1 34 0
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
	.loc 1 36 0
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC5, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L7
	.loc 1 37 0
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
	.loc 1 39 0
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC6, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L8
	.loc 1 40 0
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
	.loc 1 42 0
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movl	$10, %edx
	movq	%rax, %rsi
	movl	$.LC7, %edi
	call	strncmp
	testl	%eax, %eax
	jne	.L9
.LBB2:
	.loc 1 44 0
	movq	-56(%rbp), %rax
	movq	%rax, -32(%rbp)
	.loc 1 46 0
	movl	$.LC1, %ecx
	movq	-80(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rax
	leaq	-64(%rbp), %rdx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_sscanf
	.loc 1 47 0
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
.LBE2:
	.loc 1 49 0
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
.LBB3:
	.loc 1 51 0
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
.LBB4:
	.loc 1 52 0
	movl	$0, -20(%rbp)
	jmp	.L11
.L12:
	.loc 1 53 0
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
	.loc 1 52 0
	addl	$1, -20(%rbp)
.L11:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-56(%rbp), %rax
	cmpq	%rax, %rdx
	jl	.L12
.LBE4:
	.loc 1 55 0
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
.LBE3:
	.loc 1 59 0
	movq	-80(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rdx
	movl	$.LC9, %eax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	.loc 1 60 0
	movl	$2, %eax
	jmp	.L3
.L5:
	movl	$0, %eax
.L3:
	.loc 1 62 0
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
.Letext0:
	.section	.debug_info
	.long	0x147
	.value	0x3
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF11
	.byte	0xc
	.long	.LASF12
	.long	.LASF13
	.quad	.Ltext0
	.quad	.Letext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x4
	.byte	0x8
	.long	0x6b
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF8
	.uleb128 0x5
	.byte	0x1
	.long	.LASF14
	.byte	0x1
	.byte	0x12
	.byte	0x1
	.long	0x57
	.quad	.LFB0
	.quad	.LFE0
	.byte	0x1
	.byte	0x9c
	.long	0x135
	.uleb128 0x6
	.long	.LASF9
	.byte	0x1
	.byte	0x12
	.long	0x57
	.byte	0x3
	.byte	0x91
	.sleb128 -84
	.uleb128 0x6
	.long	.LASF10
	.byte	0x1
	.byte	0x12
	.long	0x135
	.byte	0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x7
	.string	"n"
	.byte	0x1
	.byte	0x1a
	.long	0x5e
	.byte	0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x8
	.quad	.LBB2
	.quad	.LBE2
	.long	0xf6
	.uleb128 0x7
	.string	"x"
	.byte	0x1
	.byte	0x2c
	.long	0x5e
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x7
	.string	"y"
	.byte	0x1
	.byte	0x2d
	.long	0x5e
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.byte	0x0
	.uleb128 0x9
	.quad	.LBB3
	.quad	.LBE3
	.uleb128 0x7
	.string	"xs"
	.byte	0x1
	.byte	0x33
	.long	0x13b
	.byte	0x3
	.byte	0x91
	.sleb128 -56
	.byte	0x6
	.uleb128 0x9
	.quad	.LBB4
	.quad	.LBE4
	.uleb128 0x7
	.string	"i"
	.byte	0x1
	.byte	0x34
	.long	0x57
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.byte	0x8
	.long	0x65
	.uleb128 0xa
	.long	0x5e
	.uleb128 0xb
	.long	0x2d
	.byte	0x3
	.byte	0x91
	.sleb128 -64
	.byte	0x6
	.byte	0x0
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x17
	.value	0x2
	.long	.Ldebug_info0
	.long	0x14b
	.long	0x79
	.string	"main"
	.long	0x0
	.section	.debug_pubtypes,"",@progbits
	.long	0xe
	.value	0x2
	.long	.Ldebug_info0
	.long	0x14b
	.long	0x0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0x0
	.value	0x0
	.value	0x0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0x0
	.quad	0x0
	.section	.debug_str,"MS",@progbits,1
.LASF8:
	.string	"long long int"
.LASF3:
	.string	"unsigned int"
.LASF11:
	.string	"GNU C 4.4.7 20120313 (Red Hat 4.4.7-17)"
.LASF13:
	.string	"/home/jlilly3/cs367/homework4/h4handout"
.LASF0:
	.string	"long unsigned int"
.LASF1:
	.string	"unsigned char"
.LASF14:
	.string	"main"
.LASF6:
	.string	"long int"
.LASF9:
	.string	"argc"
.LASF2:
	.string	"short unsigned int"
.LASF4:
	.string	"signed char"
.LASF5:
	.string	"short int"
.LASF12:
	.string	"hwk4.c"
.LASF7:
	.string	"char"
.LASF10:
	.string	"argv"
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-17)"
	.section	.note.GNU-stack,"",@progbits
