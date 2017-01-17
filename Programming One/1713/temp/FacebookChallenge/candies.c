#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int nargs, char *argv[])
{
	FILE *ifp;
	int x,*students, i=0, j, candies=0,check=0;
	
	
	if(!(nargs > 1))
	{
		fprintf(stdout, "Usage: %s <filename> ", argv[0]);
		exit(1);
	}
	
	ifp = fopen(argv[1], "r");
	assert(ifp);

	while(1)
	{
		if(fscanf(ifp,"%d", &x) != 1)
			break;
		if(check == 0)
		{
			students = malloc(x * sizeof(int));
			assert(students);
			check++;
		}
		students[i] = x;
		i++;
		candies++;
		printf("Candies: %d\n", candies);
	}
	for(x=0, j=1; x<i-1 && j<i; x++, j++)
	{
		if(students[j] == students[x])
			continue;
		else if(students[j] > students[x])
			candies++;
		else if(students[x] > students[j])
			candies++;
		printf("Candies: %d\n", candies);
	}

	fprintf(stdout, "Number of Candies: %d\n", candies);

	return 0;
}
