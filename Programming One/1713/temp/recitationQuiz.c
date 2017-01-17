#include <stdio.h>
#include <stdlib.h>


/*
Prompt the user to enter the number in the sequence
to compute, and the first three initial values. Then,
compute and print out all sequence values up to and 
including the requested sequence number
using the equation:
	S(i) = 10*S(i-3) - 5*S(i-2) + S(i-1)

If the sequence number entered is less than 3, issue an error
message and stop execution while signalling abnormal exit to the system.

(1) Write this code simply using an array, where it is known that 
	the sequence number is <= 100.
(2) Rewrite it to use malloc/free and to be able to handle any N.
(3) See if you can figure out a way to write it without using arrays.

*/





int main(void)
{
	int a,b,c,i,n;
	

	printf("Enter the three initial values to the sequence: ");
	scanf("%d%d%d", &a, &b, &c); 


	printf("Enter the sequence number you wish to compute: ");
	scanf("%d", &n);

	if (n < 3)
	{
		printf("The entered value cannot be less than 3.\n");
		exit(1);
	}



	for (i=3; i <=	n; i++)
		printf("S(%d) = %d\n", i, 10*(a)*(i-3) - 5*(b)*(i-2) + c*(i-1) );

	return 0;

}
