CC=gcc
CFLAGS=-DCOMPILER=GCC
AR=ar
GLOBALS=Makefile cdata.h
CDBMS_LIB=libcdbms.a

all: schema ${CDBMS_LIB}

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

${CDBMS_LIB}: btree.o clist.o
	${AR} -r ${CDBMS_LIB} btree.o clist.o

schema: schema.c ${GLOBALS}
	${CC} ${CFLAGS} -o schema schema.c

btree.o:	btree.c btree.h ${GLOBALS}
	${CC} ${CFLAGS} -c btree.c

clist.o:	clist.c clist.h ${GLOBALS}
	${CC} ${CFLAGS} -c clist.c

