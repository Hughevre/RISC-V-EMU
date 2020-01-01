syko.exe:
	gcc -c mem_abs.c -o mem_abs.o
	gcc -c main.c -o main.o
	gcc -c functions.c -o functions.o
	gcc mem_abs.o main.o -o functions.o syko.exe

clean:
	rm -f mem_abs.o
	rm -f main.o
	rm -f functions.o
	rm -f syko.exe

