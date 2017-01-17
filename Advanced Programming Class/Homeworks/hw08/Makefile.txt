# Makefile for programs in directory 09-Efficiency-and-ADTs
# ***************************************************************

PROGRAMS = \
    array-editor \
    stack-editor \
    list-editor

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

arraybuf.o: arraybuf.c buffer.h
	$(CC) $(CFLAGS) -c arraybuf.c

editor.o: editor.c buffer.h
	$(CC) $(CFLAGS) -c editor.c

listbuf.o: listbuf.c buffer.h
	$(CC) $(CFLAGS) -c listbuf.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

stackbuf.o: stackbuf.c buffer.h stack.h
	$(CC) $(CFLAGS) -c stackbuf.c


# ***************************************************************
# Executable programs

array-editor: editor.o arraybuf.o
	$(CC) $(CFLAGS) -o array-editor editor.o arraybuf.o

stack-editor: editor.o stackbuf.o stack.o
	$(CC) $(CFLAGS) -o stack-editor editor.o stackbuf.o stack.o

list-editor: editor.o listbuf.o
	$(CC) $(CFLAGS) -o list-editor editor.o listbuf.o

