CC = gcc
CFLAGS = -g -Wall

main: main.o DEQUE.o TREE.o
	$(CC) $(CFLAGS) -o main main.o DEQUE.o TREE.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

DEQUE.o: DEQUE.c
	$(CC) $(CFLAGS) -c DEQUE.c

TREE.o: TREE.c
	$(CC) $(CFLAGS) -c TREE.c

clean:
	rm main *.o