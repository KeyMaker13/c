/*
Write a void function (a function that does not return a value) which will
allocate a new float array of the length passed in by the caller, and convey
that new array back to the caller. The function should only take two arguments.
The first element in the array should be initialized to 0.0, the second to 1.0,
and so on. Test your code by printing out the elements of the array that
is returned before freeing it. Take the length of array to be created as an 
optional a command-line argument to main, which defaults to 4.
*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void setAndMakeArray(int length, float *in)
{
	int i;

	in = malloc(length * sizeof(float));
	assert(in);
	
	for(i=0; i<length; i++)
	{
		in[i] =  i;
		printf("i = %.1f\n", in[i]);
	}
}


int main(int nargs, char *argv[])
{
	int length,i=0;
	float *array;


	if(nargs < 2)
		length = 4;
	else
		length = argv[1][0];

	setAndMakeArray(length, array);

	for(i=0; i<length; i++)
		printf("array[%d] = %.1f\n", i, array[i]);

	free(array);
	
	
	return 0;
}
