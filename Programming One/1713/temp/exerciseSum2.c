#include <stdio.h>

int main(void)
{
	int i, start, end;
	double sum;

	printf("Enter a beginning whole number and ending whole number\
			\nto compute the sum of all integers between them: ");
	scanf("%d%d", &start, &end);
	

	sum = 0;

	for (i=start; i<=end; i++)
		sum = sum + i;
	printf("The sum of the numbers is %.0f\n", sum);
	
	return 0;
}
