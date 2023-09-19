CC=gcc
CFLAGS=-DCOMPILER=GCC -L.
DBG_FLAGS=-ggdb
AR=ar
GLOBALS=Makefile cdata.h
CDBMS_LIB=libcdbms.a

all: schema dbinit dbsize index invoice ${CDBMS_LIB}

clean:
	rm cbs schema cbs.c1 cbs.c2 cbs.c3 *.a

cbs.o: cbs.c cbs.c1 cbs.c2 cbs.c3 ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -o cbs cbs.c

cbs.c1: cbs.sch schema
	./schema -1 < cbs.sch > cbs.c1

cbs.c2: cbs.sch schema
	./schema -2 < cbs.sch > cbs.c2

cbs.c3: cbs.sch schema
	./schema -3 < cbs.sch > cbs.c3

${CDBMS_LIB}: btree.o clist.o database.o datafile.o dblist.o ellist.o screen.o sys.o
	${AR} -r ${CDBMS_LIB} btree.o clist.o database.o datafile.o dblist.o ellist.o screen.o sys.o

schema: schema.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -o schema schema.c

dbinit: dbinit.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -o dbinit dbinit.c cbs.c -lcdbms -lc -lncurses

dbsize: dbsize.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -o dbsize dbsize.c cbs.c -lcdbms -lc -lncurses

invoice: invoice.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -o invoice invoice.c cbs.c -lcdbms -lc -lncurses

btree.o:	btree.c btree.h ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c btree.c

clist.o:	clist.c clist.h ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c clist.c

database.o:	database.c database.h ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c database.c

datafile.o:	datafile.c datafile.h ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c datafile.c

dblist.o:	dblist.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c dblist.c

ellist.o:	ellist.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c ellist.c

screen.o:	screen.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c screen.c

sys.o:	sys.c ${GLOBALS}
	${CC} ${CFLAGS} ${DBG_FLAGS} -c sys.c

