
	/* Code for problem 4 (pg 252) */

#include <stdio.h>
#include <unistd.h>

main()
{
int i,j;

i=fork();
for (j=0; j<3; j++)
  {
  if (i == 0 && j == 0)
    {
    sleep(3);
    printf("Cats\n");
    }
  else if (i == 0)
    {
    sleep(2);
    printf("Dogs\n");
    }
  else
    {
    sleep(2);
    printf("Raining\n");
    }
  }
}

