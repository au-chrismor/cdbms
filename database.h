#ifndef __DATABASE_H__INCLUDED

void build_b();			/* Builds a new B-tree				*/
RPTR locate();        	/* Searches a B-tree for a key      */
RPTR nextkey();        	/* Gets address of the next key     */
RPTR prevkey();        	/* Gets address of the previous key */
RPTR firstkey();      	/* Gets address of first key        */
RPTR lastkey();       	/* Gets address of last key         */
RPTR currkey();	    	/* Gets address of current key	  	*/
void file_close();      /* Closes a data file               */
RPTR new_record();      /* Adds a record to a file          */
void init_index();
void cls_index();
void del_indexes();

int db_opened = FALSE;	/* data base opened indicator       */
int curr_fd [MXFILS];	/* current file descriptor	    	*/
RPTR curr_a [MXFILS];	/* current record file address	    */
char *bfs [MXFILS];		/* file i/o buffers */
int bfd [MXFILS] [MXINDEX];
char dbpath [64];
int notice_posted = 0;
int prev_col = 0, prev_row = 0;

int curr_rcd(int f, int k, char *bf);
int del_rcd(int f);
int find_rcd(int f, int k, char *key, char *bf);
int first_rcd(int f, int k, char *bf);
int last_rcd(int f, int k, char *bf);
int next_rcd(int f, int k, char *bf);
int prev_rcd(int f, int k, char *bf);
int rtn_rcd(int f, char *bf);
int seqrcd(int f, RPTR *bf);
int verify_rcd(int f, int k, char *key);

#define __DATABASE_H__INCLUDED
#endif
