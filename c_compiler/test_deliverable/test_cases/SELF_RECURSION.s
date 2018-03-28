	.file	1 "SELF_RECURSION.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	self_recursion
	.set	nomips16
	.set	nomicromips
	.ent	self_recursion
	.type	self_recursion, @function
self_recursion:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	sw	$4,32($fp)
	lw	$2,32($fp)
	bne	$2,$0,$L2
	nop

	lw	$2,32($fp)
	b	$L3
	nop

$L2:
	lw	$2,32($fp)
	addiu	$2,$2,-1
	move	$4,$2
	.option	pic0
	jal	self_recursion
	nop

	.option	pic2
$L3:
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	self_recursion
	.size	self_recursion, .-self_recursion
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
