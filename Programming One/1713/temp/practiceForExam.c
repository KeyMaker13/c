#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


double* readFile(char *file, int *N)
{
	FILE *ifp;
	double *V;
	int i;
	
	ifp = fopen(file, "r");
	assert(ifp != NULL);
	
	assert(fscanf(ifp,"%d", N) == 1);
	assert(*N > 0);
	
	V = malloc(*N * sizeof(double));
	assert(V);

	for (i=0; i<*N; i++)
		assert(fscanf(ifp, "%lg", &V[i]) == 1);	

	fclose(ifp);
	return(V);


}

void writeFile(char *file, int N, double *V)
{
	FILE *ofp;
	int i;

	ofp = fopen(file,"w");
	assert(ofp);
	
	fprintf(ofp, "%d\n", N);	
	for(i=0; i<N; i++)
		fprintf(ofp, "%lg\n", V[i]);
	fclose(ofp);

}

void sortVec(int N, double *V)
{
	int i,j;
	for (i=0; i<N-1; i++)
		for (j=N-1; j>i; j--)
			if (V[j] < V[j-1])
			{
				double temp = V[j];
				V[j] = V[j-1];
				V[j-1] = temp;
			}
}








int main(int argc, char *argv[])
{
	int N;
	double *A;

	if(argc != 3)
	{
		printf("USAGE: %s <input file> <output/sorted file>\n", argv[0]);
		exit(1);
	}

	A = readFile(argv[1], &N);
	sortVec(N, A);
	writeFile(argv[2], N, A);

	free(A);
	return 0;



}
























