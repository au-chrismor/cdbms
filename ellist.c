/* ----------------------- ellist.c ---------------------- */

/*
 *	Construct list of data element tokens from list of names
 *  such as might be entered on a command line.
 *  Return OK, or ERROR if one of the names is not in the
 *  dictionary.
 */

#include <stdio.h>
#if COMPILER==MICROSOFT
#if COMPILER==VMSC
#if COMPILER==GCC
#include <stdlib.h>
#include <string.h>
#endif
#endif
#endif
#include "cdata.h"

int ellist(int count, char *names[], int *list)
{
	char elname [31];
	int el, el1;
	extern void name_cvt();

	for (el = 0; el < count; el++)	{
		for (el1 = 0; ; el1++)	{
			if (denames [el1] == (char *) 0)	{
				fprintf(stderr,
					"\nNo such data element as %s", elname);
				return ERROR;
			}
			name_cvt(elname, names[el]);
			if (strcmp(elname, denames [el1]) == 0)
				break;
		}
		*list++ = el1 + 1;
	}
	*list = 0;
	return OK;
}
