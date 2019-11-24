all: main

%.o: %.c STACK.h
	gcc -c -o $@ $< -I.

main: main.o STACK.o
	gcc -Wall -o main main.o STACK.o -g -lm

main.o: main.c
	gcc -Wall -c main.c

STACK.o: STACK.c
	gcc -Wall -c STACK.c