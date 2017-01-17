#include <stdio.h>
#include <stdlib.h>
#include <assert.h>




char *outString(char *in)
{
	int i=0;
	char *out;
	out = malloc(sizeof(*in));
	while(in[i])
	{
		if (in[i] >= 97 && in[i] <= 122)
			out[i] = (in[i] - 32);
		else
			out[i] = in[i];
		i++;	
	}
	return out;
}

int main(int nargs, char *argv[])
{
	char *string;
	int i=0;
	
	if (nargs <= 1)
	{
		printf("Not enough arguments.\n");
		exit(1);
	}
	
	while(argv[i])
	{
		string = outString(argv[i]);
		printf("Argv[%d]: %s\n", i, argv[i]);
		printf("Duplicate: %s\n", string);
		free(string);
		i++;
	}

	return 0;
}
