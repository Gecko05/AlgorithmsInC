all: main

%.o: %.c deck.h
	gcc -c -o $@ $< -I.

main: main.o deck.o
	gcc -Wall -o main main.o deck.o -g -lm

main.o: main.c
	gcc -Wall -c main.c

deck.o: deck.c
	gcc -Wall -c deck.c