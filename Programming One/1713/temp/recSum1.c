#include <stdio.h>
#include <stdlib.h>


int recursiveSum(int min, int max)
{
	if (min == max)
		return max+min;
	else
		return max + recursiveSum(min,max-1);
}



int main(int nargs, char *argv[])
{
	int min,max,check=0;

	printf("Enter a minimum value of your choice: ");
	scanf("%d", &min);

	printf("Enter a maximum value of your choice: ");
	scanf("%d", &max);

	if (!(min <= max))
	{
		printf("The min value is not less than or equal to the max value.\n");
		exit(1);
	}
	
	int i;
	for (i=min; i<=max; i++)
		check = check + i;
	
	if (check == recursiveSum(min,max))
	{
		printf("Final values do not match. Check recursive function.");
		exit(1);
	}
	else
		printf("The sum of the numbers is: %d\n", recursiveSum(min,max));




	return 0;
}
