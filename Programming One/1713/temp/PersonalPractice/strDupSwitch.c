#include <stdio.h>
#include <stdlib.h>






int getLength(char *in)
{
	int i=0;
	while(in[i])
		i++;
	return i;
}

char *strDup(char *in)
{
	char *out;
	int i=0, length = getLength(in);

	out = malloc(length * sizeof(char));
	while(in[i])
	{
		if (in[i] >= 97 && in[i] <= 122)
			out[i] = in[i] - 32;
		else if (in[i] >= 65 && in[i] <= 90)
			out[i] = in[i] + 32;
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
		printf("Incorrect number of arguments.");
		exit(1);
	}
	
	
	while(argv[i])
	{
		string = strDup(argv[i]);
		printf("Argv[%d]: %s\n", i, argv[i]);
		printf("String: %s\n", string);
		free(string);
		i++;
	}

	return 0;
}
