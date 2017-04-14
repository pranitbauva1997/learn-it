CC=gcc

all: main help
	$(CC) help.o main.o -o learn-it

main: help common.h
	$(CC) -c main.c

help: help.c common.h
	$(CC) -c help.c

clean:
	rm -f *.o
	rm -f learn-it
