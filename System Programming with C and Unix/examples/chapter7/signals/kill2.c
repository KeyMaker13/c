
	/* Demonstrate sending a signal from the shell using the kill
	** system program (pg 235) */

#include <stdio.h>
#include <signal.h>

main()
{
void f(int),g(int);

signal(SIGUSR1,f);	/* install the handler */
signal(SIGUSR2,g);	/* install the handler */
while (1)
  sleep(1);
}

void f(int signum)
{
printf("Received a frog!\n");
}

void g(int signum)
{
printf("Received a giraffe!\n");
exit(SIGUSR2);
}

