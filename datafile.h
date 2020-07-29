#ifndef __DATAFILE_H__INCLUDED

#define flocate(r,l) ((long)(sizeof(FHEADER)+(((r)-1)*(l))))

static int handle [MXFILS];
FHEADER fh [MXFILS];

int delete_record(int fp, RPTR rcdno);
void file_close(int fp);
int file_open(char *name);
int get_record(int fp, RPTR rcdno, char *bf);
RPTR new_record(int fp, char *bf);
int put_record(int fp, RPTR rcdno, char *bf);

#define __DATAFILE_H__INCLUDED
#endif
