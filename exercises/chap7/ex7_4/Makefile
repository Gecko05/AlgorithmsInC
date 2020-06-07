CC = gcc
OBJS = LIST.o main.o
CFLAGS = -Wall -g
DEPS = LIST.h Item.h

all: main

main: $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o main $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm main *.o