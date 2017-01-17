#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int iValue[3];

	printf("Enter the three initial values to the sequence: ");
	scanf("%d%d%d", &iValue[0], &iValue[1], &iValue[2]);

	int n,i;
	printf("Enter the sequence number you wish to compute: ");
	scanf("%d",&n);

	if (n < 3)
	{
		printf("The entered value cannot be less than 3.\n");
		exit(1);
	}

	for(i=3; i <= n; i++)
		printf("S(%d) = %d\n", i, 10*iValue[0]*(i-3) - 5*iValue[1]*(i-2) + iValue[2]*(i-1));

	return 0;

}
