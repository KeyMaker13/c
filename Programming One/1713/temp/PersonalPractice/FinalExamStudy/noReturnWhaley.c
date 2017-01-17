#include <stdio.h>
#include <stdlib.h>

void SetInts(int *i1, int *i2)
{
	*i1 = 5;
	*i2 = 27;
}


int main(void)
{
	int i, j;
	SetInts(&i, &j);
	printf("i=%d, j=%d\n", i, j);
	return 0;
}
