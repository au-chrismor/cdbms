CC=gcc
CFLAGS=-DCOMPILER=GCC -L.
AR=ar
GLOBALS=Makefile cdata.h
CDBMS_LIB=libcdbms.a

all: schema dbinit ${CDBMS_LIB}

clean:
	rm cbs schema cbs.c1 cbs.c2 cbs.c3 *.a

cbs.o: cbs.c cbs.c1 cbs.c2 cbs.c3 ${GLOBALS}
	${CC} ${CFLAGS} -o cbs cbs.c

cbs.c1: cbs.sch schema
	./schema -1 < cbs.sch > cbs.c1

cbs.c2: cbs.sch schema
	./schema -2 < cbs.sch > cbs.c2

cbs.c3: cbs.sch schema
	./schema -3 < cbs.sch > cbs.c3

${CDBMS_LIB}: btree.o clist.o database.o datafile.o
	${AR} -r ${CDBMS_LIB} btree.o clist.o database.o datafile.o

schema: schema.c ${GLOBALS}
	${CC} ${CFLAGS} -o schema schema.c

dbinit: dbinit.c ${GLOBALS}
	${CC} ${CFLAGS} -o dbinit dbinit.c -lcdbms

btree.o:	btree.c btree.h ${GLOBALS}
	${CC} ${CFLAGS} -c btree.c

clist.o:	clist.c clist.h ${GLOBALS}
	${CC} ${CFLAGS} -c clist.c

database.o:	database.c database.h ${GLOBALS}
	${CC} ${CFLAGS} -c database.c

datafile.o:	datafile.c datafile.h ${GLOBALS}
	${CC} ${CFLAGS} -c datafile.c

