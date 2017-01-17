
	/* Code for problem 2 (pgs 251-252) */

#include <stdio.h>
#include <unistd.h>

main()
{
int i,j,k;

k=0;
for (j=0; j<4; j++)
  k=k+j;
i=fork();
if (i == 0)
  for (i=3; i<k; i++)
    j=j-i;
else
  i=k%3;
printf("%d %d %d\n",i,j,k);
}

