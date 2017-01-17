# Makefile for programs in directory 10-Linear-Structures
# ***************************************************************

PROGRAMS = \
    array-qtest \
    list-qtest \

# ***************************************************************
# Parameters to control Makefile operation
# Note that the gccx command script must be defined

CC = gccx
CFLAGS = 

# ***************************************************************
# Entry to bring the package up to date

all: $(PROGRAMS)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy    -- eliminate unwanted files
#    scratch -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

# ***************************************************************
# C compilations

qarray.o: qarray.c queue.h
	$(CC) $(CFLAGS) -c qarray.c

qlist.o: qlist.c queue.h
	$(CC) $(CFLAGS) -c qlist.c

qtest.o: qtest.c queue.h scanadt.h
	$(CC) $(CFLAGS) -c qtest.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c


# ***************************************************************
# Executable programs

array-qtest: qtest.o scanadt.o qarray.o
	$(CC) $(CFLAGS) -o array-qtest qtest.o scanadt.o qarray.o

list-qtest: qtest.o scanadt.o qlist.o
	$(CC) $(CFLAGS) -o list-qtest qtest.o scanadt.o qlist.o
