#include <stdio.h>
#include <stdlib.h>





int recursiveSum(int n)
{
	if(n==0)
		return n;
	else
		return n+recursiveSum(n-1);
}


int main(int nargs, char *argv[])
{
	int i=0;

	if(!(nargs >= 2))
	{
		fprintf(stderr, "USAGE: %s <argument1> <argument2>...\n", argv[0]);
		exit(1);
	}

	while(argv[i])
	{
		printf("Sum of Argv[%d]: %d\n", i, recursiveSum((int)argv[i]));
		i++;
	}


	return 0;
}
