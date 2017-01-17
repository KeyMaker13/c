
	/* Installing a signal handler using signal() (pg 230) */

#include <stdio.h>
#include <signal.h>

main()
{
void f(int);		/* prototype for signal handler function */
int i;

signal(SIGFPE,f);	/* install the handler */
for (i=-3; i<=3; i++)
  printf("%d\n",12/i);
}

void f(int signum)
{
printf("You can't divide by zero!\n");
exit(SIGFPE);
}

