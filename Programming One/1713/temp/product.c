#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	int begin,end;
	double product;

	printf("Enter two whole numbers, a beginning number and\
			\nan ending number to compute a final product\
			\ninvolving every fourth number between the entered\
			\nnumber: ");
	scanf("%d%d", &begin, &end);
	if ( (!(begin <= end)) || begin%4!=0 || end%4!=0)
	{
		printf("A product is unable to be computed using the\
				\nprovided whole numbers that were entered.");
		exit(EXIT_FAILURE);
	}

	product = begin;
	while (begin < end)
	{
		
		product = product*(begin+4);
		begin = begin + 4;
	}

	printf("The product computed is %.2f\n", product);

	return 0;
	

}
