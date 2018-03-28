	.file	1 "ATOF_driver.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	lw	$2,%call16(atof_test)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,atof_test
1:	jalr	$25
	nop

	lw	$28,16($fp)
	mtc1	$2,$f0
	cvt.d.w	$f2,$f0
	li	$3,1			# 0x1
	lui	$2,%hi($LC0)
	ldc1	$f0,%lo($LC0)($2)
	c.eq.d	$fcc0,$f2,$f0
	bc1f	$fcc0,$L2
	nop

	move	$3,$0
$L2:
	andi	$2,$3,0x00ff
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.rdata
	.align	3
$LC0:
	.word	1076179763
	.word	858993459
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
