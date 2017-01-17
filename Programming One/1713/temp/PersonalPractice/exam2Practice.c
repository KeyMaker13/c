#include <stdio.h>
#include <stdlib.h>
#include <assert.h>






int getLength(char *in)
{
	int i=0;
	while(in[i])
		i++;
	printf("The length is: %d\n", i);
	return i;
}

char *createString(char *argv)
{
	char *out;
	int i=0;
	out = malloc(getLength(argv) * sizeof(char));
	assert(out);
	while(out[i] = argv[i])
		i++;
	return out;
}

int main(int nargs, char *argv[])
{
	int i=0;
	char *inputString;

	if (nargs <= 1)
	{
		printf("USAGE: %s <input>etc \n", argv[0]);
		exit(1);
	}

	while(argv[i])
	{
		inputString = createString(argv[i]);
		printf("Argv[%d]: %s\n", i, argv[i]);
		printf("inputString: %s\n", inputString);
		free(inputString);
		i++;
	}




	return 0;
}
