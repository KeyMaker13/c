
	/* Demonstrate blocking in curses (pgs 269-270) */

#include <curses.h>

main()
{
int	i;

initscr();
nodelay(stdscr,TRUE);	/* turn off blocking */
for (i=0; i<5; i++)
  {
  getch();		/* wait for user input? */
  sleep(1);
  }
endwin();
}

