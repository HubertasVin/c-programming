	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"saved1.bin"
.LC1:
	.string	"saved2.bin"
.LC2:
	.string	"All good"
.LC3:
	.string	"Something's wrong"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$10, -148(%rbp)
	leaq	-144(%rbp), %rdx
	movl	-148(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fillArray
	leaq	-96(%rbp), %rdx
	movl	-148(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fillArray
	leaq	-48(%rbp), %rdx
	movl	-148(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	fillArray
	leaq	-144(%rbp), %rcx
	movl	-148(%rbp), %eax
	leaq	.LC0(%rip), %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	saveToFile@PLT
	leaq	-48(%rbp), %rcx
	movl	-148(%rbp), %eax
	leaq	.LC0(%rip), %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	saveToFile@PLT
	leaq	-144(%rbp), %rcx
	movl	-148(%rbp), %eax
	leaq	.LC0(%rip), %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	loadFromFile@PLT
	leaq	-96(%rbp), %rcx
	movl	-148(%rbp), %eax
	leaq	.LC1(%rip), %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	saveToFile@PLT
	leaq	-48(%rbp), %rcx
	movl	-148(%rbp), %eax
	leaq	.LC1(%rip), %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	loadFromFile@PLT
	leaq	-96(%rbp), %rcx
	movl	-148(%rbp), %eax
	leaq	.LC0(%rip), %rdx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	loadFromFile@PLT
	movl	saveCount(%rip), %eax
	cmpl	$3, %eax
	jne	.L2
	movl	loadCount(%rip), %eax
	cmpl	$3, %eax
	jne	.L2
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	jmp	.L3
.L2:
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L3:
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.globl	fillArray
	.type	fillArray, @function
fillArray:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -4(%rbp)
	jmp	.L7
.L8:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1374389535, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$5, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$100, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	addl	$1, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L8
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	fillArray, .-fillArray
	.section	.rodata
.LC4:
	.string	"array contents are:"
.LC5:
	.string	"%d "
	.text
	.globl	printArray
	.type	printArray, @function
printArray:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -4(%rbp)
	jmp	.L10
.L11:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L11
	movl	$10, %edi
	call	putchar@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	printArray, .-printArray
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
