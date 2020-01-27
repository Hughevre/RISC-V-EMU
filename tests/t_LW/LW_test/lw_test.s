/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
	lw x1, mdata0
	lw x2, mdata1
	lw x3, mdata2
	lw x4, mdata3
	lw x5, mdata4
	lw x6, mdata5
	lw x7, mdata6
	addi x8, zero, 1792
	lw x8, mdata0
	addi x9, zero, 1792
	lw x9, mdata1
	addi x10, zero, 1792
	lw x10, mdata2
	addi x11, zero, 1792
	lw x11, mdata3
	addi x12, zero, 1792
	lw x12, mdata4
	addi x13, zero, 1792
	lw x13, mdata5
	addi x14, zero, 1792
	lw x14, mdata6

/* dane aplikacji */
	.data
/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata0
	.align	2	/* alokacja co 2B */
	.type	mdata0, @object
	.size	mdata0, 8
mdata0:
	.dword  0

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata1
	.align	2	/* alokacja co 2B */
	.type	mdata1, @object
	.size	mdata1, 8
mdata1:
	.dword  1

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata2
	.align	2	/* alokacja co 2B */
	.type	mdata2, @object
	.size	mdata2, 8
mdata2:
	.dword  2046

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata3
	.align	2	/* alokacja co 2B */
	.type	mdata3, @object
	.size	mdata3, 8
mdata3:
	.dword  2047

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata4
	.align	2	/* alokacja co 2B */
	.type	mdata4, @object
	.size	mdata4, 8
mdata4:
	.dword  -1

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata5
	.align	2	/* alokacja co 2B */
	.type	mdata5, @object
	.size	mdata5, 8
mdata5:
	.dword  -2047

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata6
	.align	2	/* alokacja co 2B */
	.type	mdata6, @object
	.size	mdata6, 8
mdata6:
	.dword  -2048

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata7
	.align	2	/* alokacja co 2B */
	.type	mdata7, @object
	.size	mdata7, 8
mdata7:
	.dword  0

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata8
	.align	2	/* alokacja co 2B */
	.type	mdata8, @object
	.size	mdata8, 8
mdata8:
	.dword  1

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata9
	.align	2	/* alokacja co 2B */
	.type	mdata9, @object
	.size	mdata9, 8
mdata9:
	.dword  2046

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata10
	.align	2	/* alokacja co 2B */
	.type	mdata10, @object
	.size	mdata10, 8
mdata10:
	.dword  2047

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata11
	.align	2	/* alokacja co 2B */
	.type	mdata11, @object
	.size	mdata11, 8
mdata11:
	.dword  -1

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata12
	.align	2	/* alokacja co 2B */
	.type	mdata12, @object
	.size	mdata12, 8
mdata12:
	.dword  -2047

/* zmienna, wstepnie zadeklarowana typu long */
	.globl	mdata13
	.align	2	/* alokacja co 2B */
	.type	mdata13, @object
	.size	mdata13, 8
mdata13:
	.dword  -2048

