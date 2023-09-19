/* --------------- cdata.h ---------------------- */
#ifndef __CDATA_H__INCLUDED

#define AZTEC		1	/* Manx Aztec C86			*/
#define CI_C86 		2	/* Computer Innovations C86 */
#define DATALIGHT 	3	/* Datalight C				*/
#define ECOC 		4	/* Eco-C88					*/
#define LATTICE	 	5   /* Lattice C				*/
#define LETSC 		6	/* Mark Williams Let's C	*/
#define MICROSOFT	7	/* Microsoft C				*/
#define TURBOC      8	/* Turbo C					*/
#define WIZARD 	    9	/* Wizard C                 */
#define VMSC        10  /* OpenVMS C Compiler       */
#define GCC			11	/* GNU GCC					*/

#define ERROR -1
#define OK 0

#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#if COMPILER != LATTICE
#if COMPILER != LETSC
#if COMPILER != CI_C86
#include <errno.h>
#endif
#endif
#endif

#if COMPILER != LETSC
#if COMPILER != DATALIGHT
#if COMPILER != CI_C86
#include <fcntl.h>
#endif
#endif
#endif

#include <ctype.h>

#if COMPILER != VMSC
#if COMPILER != MICROSOFT
#if COMPILER != TURBOC
extern int errno;
#endif
#endif
#endif

#if COMPILER == VMSC
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define OPENMODE O_RDWR
#undef CMODE
#define CMODE S_IWRITE
#endif


#if COMPILER == MICROSOFT
#include <sys\types.h>
#include <sys\stat.h>
#include <string.h>
#include <stdlib.h>
#define OPENMODE O_RDWR+O_BINARY
#undef CMODE
#define CMODE S_IWRITE
#endif

#if COMPILER == TURBOC
#include <sys\stat.h>
#define OPENMODE O_RDWR+O_BINARY
#undef CMODE
#define CMODE S_IWRITE
#endif

#if COMPILER == CI_C86
#define void int
#define atol atoi
#undef CMODE
#define CMODE BUPDATE
#define OPENMODE BUPDATE
#endif

#if COMPILER == LETSC
#define CMODE 0
#define OPENMODE 2
#endif

#if COMPILER == DATALIGHT
#define CMODE 0
#define OPENMODE 2
#endif

#if COMPILER == WIZARD
#define CMODE 0x8080
#define OPENMODE O_RDWR+O_BINARY
#endif

#if COMPILER == LATTICE
#define OPENMODE O_RDWR
#define CMODE 0666
#endif

#if COMPILER == AZTEC
#define OPENMODE O_RDWR
#define CMODE 0666
#endif

#if COMPILER == ECOC
#define OPENMODE O_RDWR
#define CMODE 0
#endif

long lseek();

#define NODE 512     	/* length of a B-tree node      */
#define RPTR long		/* B-tree node and file address */

#define MXFILS   11	/* maximum files in a data base		*/
#define MXELE   100	/* maximum data elements in a file	*/
#define MXINDEX   5	/* maximum indexes per file			*/

/* ----------- dbms error codes for errno return ------ */
#define D_NF	  1	/* record not found					*/
#define D_PRIOR	  2	/* no prior record for this request	*/
#define D_EOF	  3	/* end of file			        	*/
#define D_BOF	  4	/* beginning of file			    */
#define D_DUPL	  5	/* primary key already exists		*/
#define D_OM	  6	/* out of memory			        */
#define D_INDXC   7 /* index corrupted					*/
#define D_IOERR	  8 /* i/o error						*/

#define MXKEYLEN 80	/* maximum key length for indexes */

#ifndef SCHEMA
/* --------- schema as built for the application --------- */
extern char *dbfiles [];		/* file names			*/
extern char *denames [];		/* data element names	*/
extern char *elmask  [];		/* data element masks	*/
extern char eltype [];			/* data element types	*/
extern int ellen [];			/* data element lengths	*/
extern int *file_ele [];		/* file data elements	*/
extern int **index_ele [];		/* index data elements	*/

void mov_mem();
void set_mem();
void fatal();
void cls_file();
void build_b();
void put_char();
void clear_screen();
void cursor();
void error_message();
void clear_notice();
void post_notice();
int rlen(int f);


/* ------------- data base function definitions ---------- */
int add_rcd(int f, char* bf);
void db_open(char *path, int *fl);
void db_cls(void);
void dberror(void);
void dblist(int fd, int inter, int f, int k, int *list);
int ellist(int count, char *names[], int *list);
void file_create(char *name, int len);
void init_rcd();
void clrrcd();
void rcd_fill();
void build_index();
static void index_m(int f, int *m);
int filename(char *fn);

/* ---------- screen driver function definitions --------- */
void init_screen(char* name, int* els, char* bfr);
void protect();
void edit();
void display_template();
void tally();
void put_field();
#else
static void de_dict(void);
static void defout(void);
static void depart(int n);
static void error(int n);
static void expect_comma(char **cp);
static void files(void);
static void get_line(void);
static char *get_word(char *cp);
static void keys(void);
static void lcase(char *s1, char *s2);
static void name_val(void);
static void numb_val(void);
static void schout(void);
static void skip_white(char **s);
static void strout(void);
#endif

/* ---------- file header --------------- */
typedef struct fhdr	{
	RPTR first_record;
	RPTR next_record;
	int record_length;
} FHEADER;
#define __CDATA_H__INCLUDED
#endif