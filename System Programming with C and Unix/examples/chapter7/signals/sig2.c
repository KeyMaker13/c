
	/* Ignoring a signal (pg 231) */

#include <stdio.h>
#include <signal.h>

main()
{
signal(SIGINT,SIG_IGN);		/* tell the O/S to ignore the signal */
printf("I'm running ...\n");
while (1)
  {
  printf("Still going ...\n");
  sleep(1);
  }
}

