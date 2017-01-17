#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void changeValues(int *x, int *y)
{
	*x = 5;
	*y = 27;
}

int main(int nargs, char *argv[])
{
	int *x, *y;
	
	x = malloc(sizeof(int));
	y = malloc(sizeof(int));
	assert(x);
	assert(y);

	printf("Enter an integer for x: ");
	scanf("%d", x);
	printf("\nEnter an integer for y: ");
	scanf("%d", y);
	printf("x: %d\ny: %d\n", *x, *y);
	
	changeValues(x, y);
	printf("x: %d\ny: %d\n", *x, *y);


	return 0;
}
