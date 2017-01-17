
	/* Demonstrate polling the user for input while graphics are
	** moving (pg 273) */

#include <curses.h>

main()
{
int	i,row;
char	ch;

initscr();
clear();
nodelay(stdscr,TRUE);	/* turn off blocking */
row=10;

for (i=0; i<30; i++)
  {
  move (row,i);
  addstr("Hello world");
  refresh();
  usleep(100000);	/* pause for 100000 microseconds */
  move (row,i);
  addstr("           ");
  ch=getch();		/* poll for input */
  if (ch == 'z')	/* act on input */
    row++;
  }
getch();
endwin();
}

