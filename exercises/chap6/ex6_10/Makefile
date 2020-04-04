DEPS = Item.h sort.h
CC = gcc
OBJS = main.o sort.o
CFLAGS = -g -Wall

all: main

main: $(OBJS) $(DEPS)
	$(CC) $(OBJS) -o main

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm *.o main