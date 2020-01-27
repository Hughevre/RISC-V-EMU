/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function
    .option norelax

_start:
	lui x1, 0
	lui x2, 1
	lui x3, 524287
	lui x4, 524288
	lui x5, 1048574
	lui x6, 1048575
