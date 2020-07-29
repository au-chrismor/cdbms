#ifndef __BTREE_H__INCLUDED
#define MXTREES 20
#define ADR sizeof(RPTR)
#define KLEN bheader[trx].keylength
#define ENTLN (KLEN+ADR)

/* --------- the btree node structure -------------- */
typedef struct treenode	{
	int nonleaf;	/* 0 if leaf, 1 if non-leaf  		  */
	RPTR prntnode;	/* parent node 						  */
	RPTR lfsib;		/* left sibling node  				  */			  	
	RPTR rtsib;		/* right sibling node  				  */
	int keyct;		/* number of keys 					  */
	RPTR key0;		/* node # of keys < 1st key this node */
	char keyspace [NODE - ((sizeof(int) * 2) + (ADR * 4))];
	char spil [MXKEYLEN];  /* for insertion excess */
} BTREE;

/* ---- the structure of the btree header node --------- */
typedef struct treehdr	{
	RPTR rootnode;			/* root node number */
	int keylength;
	int m;					/* max keys/node  */
	RPTR rlsed_node;		/* next released node */
	RPTR endnode;			/* next unassigned node  */
	int locked;				/* if btree is locked  */
	RPTR leftmost;			/* left-most node */
	RPTR rightmost;			/* right-most node */
} HEADER;

HEADER bheader [MXTREES];
BTREE trnode;

int handle  	[MXTREES];	/* handle of each index in use */
RPTR currnode 	[MXTREES];	/* node number of current key  */
int currkno 	[MXTREES];	/* key number of current key   */
int trx;					/* current tree */

/* ------------------ low-level functions ---------------- */
static void adopt(RPTR *ad, int kct, RPTR newp);
static void bseek(RPTR nd);
int btree_init(char *ndx_name);
int btree_close(int tree);
static int btreescan(RPTR *t, char *k, char **a);
void build_b(char *name, int len);
static char *childptr(RPTR left, RPTR parent, BTREE *btp);
static int compare_keys(char *a, char *b);
RPTR currkey(int tree);
int deletekey(int tree, char *x, RPTR ad);
static RPTR fileaddr(RPTR t, char *a);
RPTR firstkey(int tree);
static void implode(BTREE *left, BTREE *right);
int insertkey(int tree, char *x, RPTR ad, int unique);
void keyval(int tree, char *ky);
RPTR lastkey(int tree);
static RPTR leaflevel(RPTR *t, char **a, int *p);
RPTR locate(int tree, char *k);
RPTR nextkey(int tree);
static RPTR nextnode(void);
static int nodescan(char *keyvalue, char **nodeadr);
RPTR prevkey(int tree);
static void read_node(RPTR nd, BTREE *bf);
static void redist(BTREE *left, BTREE *right);
static RPTR scannext(RPTR *p, char **a);
static RPTR scanprev(RPTR *p, char **a);
static void write_node(RPTR d, BTREE *bf);
#define __BTREE_H__INCLUDED
#endif
