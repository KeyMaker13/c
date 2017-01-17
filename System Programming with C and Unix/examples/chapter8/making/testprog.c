
#include <stdio.h>
#include "custom_lib.h"

	/* A simple program linking to our library. */

int main()

{
int	i,first,second;

printf("Enter a number: ");
scanf("%d",&first);
printf("Enter a second number: ");
scanf("%d",&second);
i=Largest(first,second);
if (i == 1)
  printf("First number is larger\n");
else if (i == 2)
  printf("Second number is larger\n");
else
  printf("Same number\n");
printf("%lf\n",SevenPointSeven());
HelloWorld();
HelloWorld();
}


