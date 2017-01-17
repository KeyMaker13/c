
	/* Re-installing the default signal handler (pg 232) */

#include <stdio.h>
#include <signal.h>

main()
{
int i;

signal(SIGINT,SIG_IGN);		/* ignore the signal */
printf("I'm running ...\n");
for (i=1; i<10; i++)
  {
  printf("Still going ...\n");
  sleep(1);
  if (i == 3)
    signal(SIGINT,SIG_DFL);	/* re-install default handler */
  }
}

