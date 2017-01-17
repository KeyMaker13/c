
	/* Demonstrate turning echo off in curses (pgs 268-269) */

#include <curses.h>

main()
{
int	i;

initscr();
noecho();	/* turn off echoing */
for (i=0; i<5; i++)
  getch();	/* wait for user input */
endwin();
}

