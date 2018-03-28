	.file	1 "IF_F.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	if_f
	.set	nomips16
	.set	nomicromips
	.ent	if_f
	.type	if_f, @function
if_f:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	sw	$4,16($fp)
	sw	$5,20($fp)
	li	$2,2			# 0x2
	sw	$2,4($fp)
	lw	$3,16($fp)
	lw	$2,20($fp)
	bne	$3,$2,$L2
	nop

	li	$2,1			# 0x1
	sw	$2,4($fp)
$L2:
	lw	$2,4($fp)
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	if_f
	.size	if_f, .-if_f
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
