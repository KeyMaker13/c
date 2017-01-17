# Makefile for programs in directory 13-Trees
# ***************************************************************

PROGRAMS = \
    avltree \
    bsttest \
    introbst \
    symtest

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

avltree.o: avltree.c
	$(CC) $(CFLAGS) -c avltree.c

bst.o: bst.c bst.h cmpfn.h
	$(CC) $(CFLAGS) -c bst.c

bsttab.o: bsttab.c bst.h cmpfn.h symtab.h
	$(CC) $(CFLAGS) -c bsttab.c

bsttest.o: bsttest.c bst.h cmpfn.h scanadt.h
	$(CC) $(CFLAGS) -c bsttest.c

cmdscan.o: cmdscan.c cmdscan.h scanadt.h symtab.h
	$(CC) $(CFLAGS) -c cmdscan.c

cmpfn.o: cmpfn.c cmpfn.h
	$(CC) $(CFLAGS) -c cmpfn.c

introbst.o: introbst.c
	$(CC) $(CFLAGS) -c introbst.c

iterator.o: iterator.c iterator.h symtab.h
	$(CC) $(CFLAGS) -c iterator.c

scanadt.o: scanadt.c scanadt.h
	$(CC) $(CFLAGS) -c scanadt.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c

symtest.o: symtest.c cmdscan.h iterator.h scanadt.h symtab.h
	$(CC) $(CFLAGS) -c symtest.c


# ***************************************************************
# Executable programs

avltree: avltree.o
	$(CC) $(CFLAGS) -o avltree avltree.o

bsttest: bsttest.o bst.o cmpfn.o scanadt.o
	$(CC) $(CFLAGS) -o bsttest bsttest.o bst.o cmpfn.o scanadt.o

introbst: introbst.o
	$(CC) $(CFLAGS) -o introbst introbst.o

symtest: symtest.o cmdscan.o iterator.o scanadt.o symtab.o
	$(CC) $(CFLAGS) -o symtest symtest.o cmdscan.o iterator.o scanadt.o symtab.o

