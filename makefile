all: list.o songlib.o main.o
	gcc -g list.o songlib.o main.o
list.o: list.c list.h
	gcc -g -c list.c
songlib.o: songlib.c songlib.h
	gcc -g -c songlib.c
main.o: main.c list.h songlib.h
	gcc -g -c main.c
clean:
	rm *.o
	rm *~
run: all
	./a.out
