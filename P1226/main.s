	.file	"main.cpp"
	.text
	.p2align 4
	.globl	_Z6binpowyyy
	.type	_Z6binpowyyy, @function
_Z6binpowyyy:
.LFB1812:
	.cfi_startproc
	endbr64
	movq	%rdx, %rcx
	movl	$1, %r8d
	testq	%rsi, %rsi
	je	.L2
	.p2align 4,,10
	.p2align 3
.L4:
	testb	$1, %sil
	je	.L3
	movq	%r8, %rax
	xorl	%edx, %edx
	imulq	%rdi, %rax
	divq	%rcx
	movq	%rdx, %r8
.L3:
	imulq	%rdi, %rdi
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rcx
	shrq	%rsi
	movq	%rdx, %rdi
	jne	.L4
.L2:
	movq	%r8, %rax
	xorl	%edx, %edx
	divq	%rcx
	movq	%rdx, %rax
	ret
	.cfi_endproc
.LFE1812:
	.size	_Z6binpowyyy, .-_Z6binpowyyy
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	" mod "
.LC1:
	.string	"="
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB1813:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	a(%rip), %rsi
	leaq	_ZSt3cin(%rip), %rdi
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	_ZNSi10_M_extractIyEERSiRT_@PLT
	leaq	b(%rip), %rsi
	movq	%rax, %rdi
	call	_ZNSi10_M_extractIyEERSiRT_@PLT
	leaq	p(%rip), %rsi
	movq	%rax, %rdi
	call	_ZNSi10_M_extractIyEERSiRT_@PLT
	movq	a(%rip), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIyEERSoT_@PLT
	movl	$1, %edx
	leaq	7(%rsp), %rsi
	movb	$94, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	b(%rip), %rsi
	movq	%rax, %rdi
	call	_ZNSo9_M_insertIyEERSoT_@PLT
	movl	$5, %edx
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	p(%rip), %rsi
	movq	%rbp, %rdi
	call	_ZNSo9_M_insertIyEERSoT_@PLT
	leaq	.LC1(%rip), %rsi
	movl	$1, %edx
	movq	%rax, %rdi
	movq	%rax, %rbp
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	b(%rip), %rsi
	movq	p(%rip), %r8
	movl	$1, %r9d
	movq	a(%rip), %rcx
	testq	%rsi, %rsi
	je	.L12
	.p2align 4,,10
	.p2align 3
.L14:
	testb	$1, %sil
	je	.L13
	movq	%r9, %rax
	xorl	%edx, %edx
	imulq	%rcx, %rax
	divq	%r8
	movq	%rdx, %r9
.L13:
	imulq	%rcx, %rcx
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r8
	shrq	%rsi
	movq	%rdx, %rcx
	jne	.L14
.L12:
	xorl	%edx, %edx
	movq	%r9, %rax
	movq	%rbp, %rdi
	divq	%r8
	movq	%rdx, %rsi
	call	_ZNSo9_M_insertIyEERSoT_@PLT
	movq	8(%rsp), %rax
	subq	%fs:40, %rax
	jne	.L22
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L22:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE1813:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z6binpowyyy, @function
_GLOBAL__sub_I__Z6binpowyyy:
.LFB2301:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	_ZStL8__ioinit(%rip), %rbp
	movq	%rbp, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	movq	%rbp, %rsi
	popq	%rbp
	.cfi_def_cfa_offset 8
	leaq	__dso_handle(%rip), %rdx
	jmp	__cxa_atexit@PLT
	.cfi_endproc
.LFE2301:
	.size	_GLOBAL__sub_I__Z6binpowyyy, .-_GLOBAL__sub_I__Z6binpowyyy
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z6binpowyyy
	.globl	p
	.bss
	.align 8
	.type	p, @object
	.size	p, 8
p:
	.zero	8
	.globl	b
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.zero	8
	.globl	a
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.zero	8
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
