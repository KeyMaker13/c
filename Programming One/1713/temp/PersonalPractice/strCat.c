#include <stdio.h>
#include <stdlib.h>



int getLength(char *in)
{
	int i=0;
	while(in[i])
		i++;
	return i;
}

char *concatonated(char *first, char *second)
{
	char *out;
	int length = (getLength(first) + getLength(second));
	int i=0, j=0;

	out = malloc(length * sizeof(char));

	while(out[j] = first[i])
	{
		i++;
		j++;
	}
	i=0;
	while(out[j] = second[i])
	{
		i++;
		j++;
	}

	return out;
}


int main(int nargs, char *argv[])
{
	int i=1;
	char *combined;
	
	if(nargs%2 != 0)
	{
		printf("Incorrect amount of arguments used.");
		exit(1);
	}
	
	printf("Main Checkpoint\n");	
	while(argv[i])
	{
		combined = concatonated(argv[i-1], argv[i]);
		printf("Argv[%d]: %s\n", i-1, argv[i-1]);
		printf("Argv[%d]: %s\n", i, argv[i]);
		printf("concatonated: %s\n", combined);
		i+=2;
		free(combined);
	}
	
	free(combined);


	return 0;
}
