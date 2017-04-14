CC=g++
CFLAGS=-g

all: main help words
	$(CC) $(CFLAGS) help.o main.o words.o -o learn-it

main: help common.h
	$(CC) $(CFLAGS) -c main.c

help: help.c common.h
	$(CC) $(CFLAGS) -c help.c

words: words.c common.h
	$(CC) $(CFLAGS) -c words.c

clean:
	rm -f *.o
	rm -f learn-it
