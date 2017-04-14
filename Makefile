CC=gcc
CFLAGS=-g

all: main help
	$(CC) $(CFLAGS) help.o main.o -o learn-it

main: help common.h
	$(CC) $(CFLAGS) -c main.c

help: help.c common.h
	$(CC) $(CFLAGS) -c help.c

clean:
	rm -f *.o
	rm -f learn-it
