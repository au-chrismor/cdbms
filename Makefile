CC=gcc
CFLAGS=-DCOMPILER=GCC
GLOBALS=Makefile cdata.h

all: schema

schema: schema.c

schema: schema.c ${GLOBALS}
	${CC} ${CFLAGS} -o schema schema.c

