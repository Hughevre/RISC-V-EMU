syko.exe:
	gcc -c mem_abs.c -o mem_abs.o
	gcc -c main.c -o main.o
	gcc -c instructions.c -o instructions.o
	gcc mem_abs.o main.o -o instructions.o syko.exe

clean:
	rm -f mem_abs.o
	rm -f main.o
	rm -f instructions.o
	rm -f syko.exe

