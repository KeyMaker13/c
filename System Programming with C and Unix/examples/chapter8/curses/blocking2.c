
	/* Demonstrate timed blocking in curses (pg 270) */

#include <curses.h>

main()
{
int	i;

initscr();
halfdelay(5);		/* blocking = 5/10 second */
for (i=0; i<5; i++)
  getch();		/* wait for user input */
endwin();
}

