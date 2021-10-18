all: list.o
	gcc -o list list.o

list.o: list.c
	gcc -c list.c

run:
	./list