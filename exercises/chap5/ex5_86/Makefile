CC = gcc
CFLAGS = -g -Wall

all: main

main: main.o TREE.o
	$(CC) $(CFLAGS) main.o TREE.o -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

TREE.o: TREE.c
	$(CC) $(CFLAGS) -c TREE.c