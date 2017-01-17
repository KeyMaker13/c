
	/* Sending a signal using the kill() function (pgs 233-234) */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int running;

main()
{
void f(int);
int i,j;
char text[80];

i=fork();		/* parent & child process running now */
if (i == 0)
  {			/* child process */
  signal(SIGUSR1,f);	/* install the handler */
  printf("Child waiting...\n");
  running=1;
  while (running == 1)
    sleep(1);
  }
else
  {
  while (1)
    {
    sleep(1);
    printf("Command? ");
    scanf("%s",text);
    if (strcmp(text,"frog") == 0)
      kill(i,SIGUSR1);
    if (strcmp(text,"quit") == 0)
      break;
    }
  }
}

void f(int signum)
{
printf("Child received a frog!\n");
running=0;
}

