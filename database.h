#ifndef __DATABASE_H__INCLUDED

int db_opened = FALSE;	/* data base opened indicator       */
int curr_fd [MXFILS];	/* current file descriptor	    	*/
RPTR curr_a [MXFILS];	/* current record file address	    */
char *bfs [MXFILS];		/* file i/o buffers */
int bfd [MXFILS] [MXINDEX];
char dbpath [64];
int notice_posted = 0;
int prev_col = 0, prev_row = 0;

int add_indexes(int f, char *bf, RPTR ad);
void clrrcd(char *bf, int *els);
void cls_index(int f);
int curr_rcd(int f, int k, char *bf);
int data_in(char *c);
void del_indexes(int f, RPTR ad);
int del_rcd(int f);
int find_rcd(int f, int k, char *key, char *bf);
int first_rcd(int f, int k, char *bf);
int getrcd(int f, RPTR ad, char *bf);
void init_index(char *path, int f);
void init_rcd(int f, char *bf);
int last_rcd(int f, int k, char *bf);
int next_rcd(int f, int k, char *bf);
int prev_rcd(int f, int k, char *bf);
int rel_rcd(int f, RPTR ad, int *bf);
int relate_rcd(int f, char *bf);
int rtn_rcd(int f, char *bf);
int seqrcd(int f, RPTR *bf);
int treeno(int f, int k);
int verify_rcd(int f, int k, char *key);

#define __DATABASE_H__INCLUDED
#endif
