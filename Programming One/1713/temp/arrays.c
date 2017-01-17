#include <stdio.h>
#include <stdlib.h>




void printContents(int N[], int size)
{
	int i;
	for (i=0; i<size; i++)
		printf("N[%d] = %d\n", i, N[i]);

}

int main(void)
{
	int N, i;
	
	printf("Enter a positive integer for the size of the array you would like.\
			\nIt must be no greater than 200: ");
	scanf("%d", &N);
	int array[N], arrayB[N], arrayC[N];
	
	for (i=0; i<N; i++)
		array[i] = i*100;


	printContents(array, N);


	for (i=0; i<N; i++)
	{
		if (i%2 == 0)
			arrayB[i] = 0;
		if (i%2 != 0)
			arrayB[i] = array[i];
	}


	for (i=0; i<N; i++)
	{
		if (i == 0)
			arrayC[i] = -array[i+1];
		if (i%2 != 0)
			arrayC[i] = array[i-1];
		if (i%2 == 0 && i != 0)
			arrayC[i] = -array[i+1];
	}

	printContents(arrayB, N);
	printf("\nPrinting contents for array C.\n\n");
	printContents(arrayC, N);

	return 0;

}
