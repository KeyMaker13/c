
	/* Demonstrate doing blocks of code at different rates within a
	** timed loop, using the modulus operator on the iteration count.
	** (pg 274) */

#include <curses.h>

main()
{
int	i;

initscr();
clear();

for (i=0; i<30; i++)
  {
  move (10,i);
  addstr("     ");
  move (10,i+1);
  addstr("Hello");
  if (i%2 == 0) 	/* every 2nd iteration */
    {
    move (12,i/2);
    addstr("     ");
    move (12,i/2+1);
    addstr("world");
    }
  move (LINES-1,0);
  refresh();
  usleep(100000);
  }
getch();
endwin();
}


