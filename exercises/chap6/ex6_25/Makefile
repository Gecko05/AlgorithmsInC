CC = gcc
DEPS = Item.h sort.h verify_sort.h
OBJS = main.o sort.o verify_sort.o
CFLAGS = -Wall -g

all: main

main: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CLFAGS) -c $< -o $@

clean:
	rm main *.o