#include <stdio.h>
#include <stdlib.h>






int fibonacciNumbers(int n)
{
	
	if (n==0)
		return sum;
	else
		return sum + fibonacciNumbers(n-1);
}


int main(int nargs, char *args[])
{

	printf("Fibonacci Sequence sum for 10: %d\n", fibonacciNumbers(10));
	printf("Fibonacci Sequence sum for 20: %d\n", fibonacciNumbers(20));
	printf("Fibonacci Sequence sum for 23: %d\n", fibonacciNumbers(23));
	return 0;

}
