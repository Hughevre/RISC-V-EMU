/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function

_start:	
	lui	a4,11
	call	subroutine
	j	main

main:
	mv	a4,a0
	mv	a5,a0
	nop
petla1:
	lw	a5,-20(s0)
	jal 	a1,0x0
	beq	a1,a5,main
	addi	a5,a5,1
	sw	a5,-20(s0)
	j	petla1

subroutine:
	nop
	ret


/* dane aplikacji */
/* zmienna, wstepnie zadeklarowana typu char[] */
	.globl	mdata
	.data
	.align	2	/* alokacja co 2B */
	.type	mdata, @object
	.size	mdata, 14
mdata:
	.string	"Hello world!\n"

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata2
	.align	2	/* alokacja co 2B */
	.type	mdata2, @object
	.size	mdata2, 8
mdata2:
	.dword	305419896	/* co odpowiada 0x12345678 */

/* zmienna, wstepnie zadeklarowana typu char (8bitow) */
	.globl	mdata3
	.align	2	/* alokacja co 2B */
mdata3:
	.byte	0xFE

/* zmienna, wstepnie zadeklarowana typu short (16bitow) */
	.globl	mdata4
	.align	2	/* alokacja co 2B */
	.type	mdata4, @object
	.size	mdata4, 2
mdata4:
	.half	0xabcd

/* zmienna, wstepnie zadeklarowana typu char (8bitow) */
	.globl	mdata5
	.align	2	/* alokacja co 2B */
mdata5:
	.byte	0xEF

