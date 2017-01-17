#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define CAPACITY 30

/*
Make sure to use fprintf to output to a file.
*/

double RandomNumber()
{
	return ((double)rand() / RAND_MAX) * (100 - 1) + 1;
}


int main(void)
{
	int i;
	double N[CAPACITY];
	FILE *ofp;
	unsigned int iseed = (unsigned int)time(NULL);
	drand48(iseed);
	

	ofp = fopen("outputFile", "w");	

	for (i=0; i<CAPACITY; i++)
	{
		N[i] = RandomNumber();
		fprintf(ofp, "%.0f\n", N[i]);
	}

	return 0;
}
