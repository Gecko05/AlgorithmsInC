CC = gcc
CFLAGS = -g -Wall
OBJECTS = GRAPH.o DEQUE.o main.o
DEPS = GRAPH.h DEQUE.h Item.h

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o main

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o main