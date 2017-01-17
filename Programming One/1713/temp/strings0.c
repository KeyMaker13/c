#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int countCharacters(char *array)
{

	int i=0;
	/*if(array)*/
	while (array[i] != '\0')
			i++;
	return i;
	
}


int main(int nargs, char *argv[])
{
	int i=0;
	for (i=0; i<nargs; i++)
	{
		printf("Argument #%d: %s\n",i+1, argv[i]);
		printf("String length: %d\n\n", countCharacters(argv[i]));
	}
	
	return 0;
}
