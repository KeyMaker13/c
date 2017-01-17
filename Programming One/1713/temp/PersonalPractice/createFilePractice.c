#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



void pointerTest(int *x, int *y)
{
	*x = 6;
	*y = 9;
}


int main(int args, char *argv[])
{
	int array[] = {0, 4, 3, 88, 123,124,43,76,68,3454}, i, *p;
	int array2[10], N = 10;

	array2 = malloc(array2 * sizeof(int));
	assert(array2);
	for (i=0; i<N; i++)
	{
		pointerTest(&array[i],&array2[i]);
		printf("array[%d] = %d\n", i, array[i]);
		printf("array2[%d] = %d\n", i, array2[i]);
	}


	free(array2);

	return 0;

}










