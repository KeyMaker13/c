#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *ifp;
	double N[30];
	int i=0;

	ifp = fopen("outputFile", "r");
	
	while((fscanf(ifp, "%.0f", N[i])) != EOF)
	{
		printf("%.0f", N[i]);
		i++;
	}

	return 0;
}
