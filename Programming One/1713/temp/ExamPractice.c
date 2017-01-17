#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* readFile(char *file, int *N)
{
	FILE *ifp;
	double *V;
	int i;

	ifp = fopen(file, "r");
	V = malloc(*N * sizeof(double));
	assert(V);

	for (i=0; i<*N; i++)
		assert(fscanf(ifp, "%lg", &V[i]) == 1);

	fclose(ifp);
	return V;
}

void printIt(double *A, int N)
{
	int i;
	for (i=0; i<N; i++)
		printf("%lg\n", A[i]);
}

int main(int argc, char *argv[])
{
	int N;
	double *A;
	int i;
	A = readFile(argv[1], &N);
	printIt(A, N);
	return 0;
}
