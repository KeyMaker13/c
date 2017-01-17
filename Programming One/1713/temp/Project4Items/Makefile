CC = gcc
CCFLAGS = -Wall -ansi -g

xtst : tester.o items.o
	$(CC) $(CCFLAGS) -o xtst tester.o items.o
tester.o : items.h tester.c
	$(CC) $(CCFLAGS) -c tester.c
items.o : items.h  items.c
	$(CC) $(CCFLAGS) -c items.c
clean:
	rm tester.o items.o
kill: 
	rm tester.o items.o xtst
