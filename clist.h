#ifndef __CLIST_H__INCLUDED

#define SCRNLINES 20
#define PRNTLINES 55

int lct = 99;
int clip;

void clist(FILE *fd, int inter, int *fl, int *pl, char *bf, char *fn);
void test_eop(FILE *fd, char *fn, int *pl);
void oflow(FILE *fd, int inter, char *fn, int *pl);
static int hdlen(int el);

#define __CLIST_H__INCLUDED
#endif

