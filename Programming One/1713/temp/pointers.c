#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 10



void pointerMethod(FILE *file, int *x)
{
	*x = 5;

}

void justPoint(int *x)
{
	*x = 0;

}

void copyArray(int *x, int *y)
{
	printf("Pointer y:\"%d\" is now pointer x \"%d\"\n", *y, *x);
	*y = *x;
}


double* readInFile(FILE *ifp,int *x)
{

}

int main(int args, char *argv[])
{
	int array1[] = {231,2345,23,63,23,73,1234,5454,363,1717};
	FILE *ifp;
	double *ifpN;
	int i, array2[N], array3[N], array4[N];
	int *A, *V;

	if (args != 3)
	{
		printf("Incorrect amount of arguments provided in commandline.\n");
		exit(1);
	}



	V = malloc(*A * sizeof(int));
	assert(V);
	

	ifp = fopen("outputFile","r");
	assert(ifp);
	
	fscanf(ifp,"%d\n", V);
	printf("%d\n", *V);


	

	





/*
Copy array1 and 2 data into separate arrays to show comparison
output.
*/

	for (i=0; i<N; i++)
	{
		copyArray(&array1[i], &array3[i]);
		copyArray(&array2[i], &array4[i]);
	}

	for(i=0; i<N; i++)
		printf("array1[%d] = %.7d%2c|%2carray3[%d] = %d\n",
					i, array1[i],' ',' ',i,array3[i]);
	printf("\n\n\n");


	for(i=0; i<N; i++)
		printf("array2[%d] = %.7d%2c|%2carray4[%d] = %d\n",
					i, array2[i],' ',' ',i, array4[i]);
	printf("\n\n\n");



/*
End that section
*/

	for (i=0; i<N; i++)
	{
		copyArray(&array1[i],&array2[i]);
		printf("array2[%d] = %d\n", i, array2[i]);
	}



	for (i=0; i<10; i++)
	{
		justPoint(&array1[i]);
		printf("array1[%d] = %d\n", i, array1[i]);
		pointerMethod(ifp, &array1[i]);
		printf("array1 after pointerMethod: array1[%d] = %d\n", i, array1[i]);
	}

	free(V);

	return 0;

}








