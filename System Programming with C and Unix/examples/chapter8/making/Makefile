
# Command for building our test program

all:testprog libece222.a

testprog:testprog.c libece222.a ece222.h
	gcc -o testprog testprog.c -lece222 -L.

libece222.a:ece222.c two.c ece222.h
	gcc -c ece222.c
	gcc -c two.c
	ar r libece222.a ece222.o two.o

