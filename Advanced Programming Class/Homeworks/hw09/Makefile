# Makefile for programs in directory 13-Trees
# ***************************************************************

PROGRAMS = hw09 

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

hw09.o: hw09.c scanadt.h
	$(CC) $(CFLAGS) -g -c hw09.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c

# ***************************************************************
# Executable programs

hw09: hw09.o scanadt.o
	$(CC) $(CFLAGS) -o hw09 hw09.o scanadt.o
