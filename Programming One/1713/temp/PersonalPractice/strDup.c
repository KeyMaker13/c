#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


char *dupStr(char *in)
{
	char *dupStr;
	int i=0;
	dupStr = malloc(sizeof(*in));
	assert(dupStr);
	while(dupStr[i] = in[i])
		i++;
	return dupStr;
}


int main(int nargs, char *argv[])
{
	char *duplicate;
	if(nargs <= 1)
	{
		printf("USAGE: %s <string input>...", argv[0]);
		exit(1);
	}

	int i=0;
	while(argv[i])
	{
		duplicate = dupStr(argv[i]);
		printf("Duplicate String: %s\n", duplicate);
		i++;
		free(duplicate);
	}



	return 0;
}
