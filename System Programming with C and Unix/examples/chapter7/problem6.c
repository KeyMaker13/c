
	/* Code for problem 6 (pg 253) */

#include <stdio.h>
#include <signal.h>

main()
{
void 	f(int);
int 	i;
double 	*t,x[5];

signal(SIGSEGV,f);
x[0]=0.0;
t=0;
for (i=1; i<5; i++)
  {
  x[i]=(double)i+11.0;
  if (x[i-1] > 12.0)
    *t=42.3;
  printf("Ok\n");
  }
}

void f(int signum)
{
printf("Bad!\n");
exit(SIGSEGV);
}

