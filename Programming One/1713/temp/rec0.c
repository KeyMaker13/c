#include <stdio.h>

int recursiveSum(int n)
{
	if(n==1)
		return n;
	else
		return n+recursiveSum(n-1);

}



int main(int nargs, char *argv[])
{
	int value, check;
	printf("Enter an integer to sum all the numbers from 0\
			\n to your choice. ");
	scanf("%d", &value);

	
	check = value*(value+1)/2;
	if(check != recursiveSum(value))
		printf("The answers do not match. Check recursion function.\n");
	else
		printf("The sum of all the numbers inbetween is: %d\n", recursiveSum(value));


	return 0;
}
