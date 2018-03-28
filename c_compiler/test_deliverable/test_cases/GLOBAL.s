	.file	1 "GLOBAL.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.globl	a
	.data
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.word	10
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
