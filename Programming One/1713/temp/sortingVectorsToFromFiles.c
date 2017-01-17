#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double *readVecFromFile (char *file, int *N)
{
	FILE *fp;
	double *V;
	int i;

	fp = fopen(file, "r");
	assert ( fp != NULL);

	assert(fscanf(fp, "%d", N) == 1);
	assert(*N > 0);

	V = malloc(*N * sizeof(double));
	assert(V);			/* same as assert(V != NULL) */

	for (i=0; i < *N; i++)
		assert(fscanf(fp, "%lg", &V[i]) == 1);

	fclose(fp);			/*	close the file once array is read in */
	return(V);
}


void writeVecToFile (char *file, int N, double *V)
{
	FILE *fpout;
	int i;

	fpout = fopen(file, "w");
	assert(fpout);
	fprintf(fpout, "%d\n", N);
	for (i=0; i < N; i++)
		fprintf(fpout, "%lg\n", V[i]);
	fclose(fpout);
}


void sortDoubles (int N, double *V)
{
	int i,j;
	for (i=0; i < N-1; i++)
		for (j=N-1; j > i; j--)
			if (V[j] < V[j-1])
			{
				double tmp=V[j];
				V[j] = V[j-1];
				V[j-1] = tmp;
			}
}

int main(int nargs, char *args[])
{
	int N;
	double *A;

	if (nargs != 3)
	{
		fprintf(stderr, "USAGE: %s <input file> <output/sorted file>\n", args[0]);
		return(1);
	}
	A = readVecFromFile(args[1], &N);
	sortDoubles(N, A);
	writeVecToFile(args[2], N, A);

	free(A);
	return(0);

}










