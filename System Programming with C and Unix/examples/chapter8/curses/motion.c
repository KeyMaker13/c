
	/* Demonstrate moving text using the curses library (pg 271) */

#include <curses.h>

main()
{
int	i;

initscr();
clear();	/* clear screen */
for (i=0; i<30; i++)
  {
  move (10,i);
  addstr("Hello world");
  refresh(); 		  /* flush buffer */
  usleep(100000); 	  /* pause 0.1 seconds */
  move (10,i); 		  /* back to previous spot */
  addstr("           ");  /* draw empty space */
  }
getch();
endwin();
}

