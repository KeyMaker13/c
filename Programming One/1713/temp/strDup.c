#include <stdio.h>
#include <stdlib.h>
/*
Write a function that takes one string as input, and returns a newly allocated
string that is a duplicate of the input string. Your main program should
test that the strings are of the same length, print out the same, and that
your function works with a variety of strings. Your main program should
free all the strings allocated by your function.
*/








char *dupString(char *inString)
{
	char *dupString;
	int i=0;
	while(inString[i])
		i++;
	dupString = malloc(i*sizeof(char));
	*dupString = *inString;
	
	return dupString;
	
}



int main(int nargs, char *argv[])
{
	int i;
	char *copiedString;

	for (i=0; i<nargs; i++)
	{
		copiedString = dupString(argv[i]);
		printf("\nArgv[%d]: %s\n", i, *argv);
		printf("CopiedString = %s", copiedString);
		free(copiedString);
	}

	return 0;
}
