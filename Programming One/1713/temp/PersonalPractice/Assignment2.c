#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFLEN 1
#define CHUNSZ 1



int getLength(char *string)
{
	int i=0;

	if(string)
		while(string[i] != '\0')
			i++;
	printf("The length of the string is: %d\n", i);
	return i;
}

char *combineStrings(char *first, char *second)
{
	char *out;
	int i=0, j=0;
	
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


char *getStrFromFile(FILE *fpin)
{
	char *out, *temp1, *temp2;
	int size = DEFLEN, i=0;
	

	out = malloc(size * sizeof(char));
	assert(out);
	
	if(fgets(out,size,fpin) == NULL)
		return NULL;
	printf("Out: %s\n",out);
	printf("Checkpoint. Length is: %d\n", getLength(out));

	while(1)
	{
		if(out[getLength(out)] == '\n'|| out[getLength(out)] == '\0')
			break;
		else
		{
			temp1 = malloc(size * sizeof(char));
			assert(temp1);
			temp1 = out;
			printf("Temp1: %s\n", temp1);
			free(out);

			size += CHUNSZ;
			temp2 = malloc(size * sizeof(char));
			assert(temp2);
			fgets(temp2,size,fpin);

			out = malloc(((size*2)-1) * sizeof(char));
			assert(out);
			out = combineStrings(temp1,temp2);
			free(temp1);
			free(temp2);
		}
	}
		


	return out;
}





int main(int nargs, char *argv[])
{
	char *inputString;
	FILE *fpin;

	if (nargs != 2)
	{
		fprintf(stderr, "USAGE: %s <file>\n", argv[0]);
		exit(1);
	}


	fpin = fopen(argv[1],"r");
	assert(fpin);
	while(1)
	{
		inputString = getStrFromFile(fpin);

		if(!inputString)
		{
			free(inputString);
			break;
		}

		printf("%s\n", inputString);
		free(inputString);
	}


	fclose(fpin);
	return 0;
}
