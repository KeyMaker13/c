#include <stdio.h>
#define UL (unsigned long int)
int main(void)
{
	int i, iarr[4] = {0, 1, 2, 3};
	
	printf("%lu, %lu\n", UL iarr, UL &iarr[0]);
	printf("%lu, %lu\n", UL (iarr+1), UL (&iarr[i]));
	for (i=1; i < 4; i++)
		printf("dist iarr[%d] = %d\n", i, (int)((UL(&iarr[i])) - (UL iarr)));


	return 0;
}
