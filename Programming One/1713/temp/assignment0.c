#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	char *inf;
	FILE *fpin;
	int tot;

	char *GetFlags(int argc, char **argv);
	int sumfile(FILE *fpin);

	inf = GetFlags(argc, argv);
	fpin = fopen(inf, "r");
	assert(fpin);
	tot = 

}
