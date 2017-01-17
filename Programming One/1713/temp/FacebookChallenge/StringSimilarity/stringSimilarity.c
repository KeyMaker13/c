#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int nargs, char *argv[])
{
	FILE *ifp;
	int i,j,N;

	if(!(nargs > 1))
	{
		fprintf(stdout, "USAGE: %s <filename>\n", argv[0]);
		exit(1);
	}

	ifp = fopen(argv[1], "r");
	assert(ifp);

	while(1)
	{
		if(fscanf(ifp, "


	}




	return 0;
}
