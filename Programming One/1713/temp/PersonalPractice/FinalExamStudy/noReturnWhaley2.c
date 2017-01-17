#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void GetInitArray(int N, float **arr)
{
	float *fp;
	int i;
	fp = malloc(N*sizeof(float));
	assert(fp);
	for (i=0; i<N; i++)
	{
		fp[i] = i;
		printf("fp[%d] = %g\n",i, fp[i]);
	}
	*arr = fp;
}


int main(int nargs, char *argv[])
{
	int i, N;
	float *p;

	if(nargs > 1)
		N = atoi(argv[1]);
	else
		N = 4;
	assert(N > 0);
	GetInitArray(N, &p);
	printf("%d-length array:\n", N);
	for (i=0; i<N; i++)
		printf("	A[%d] = %g\n", i, p[i]);
	free(p);

	return 0;
}
