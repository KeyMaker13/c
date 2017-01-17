
	/* Demonstrate buffering in curses (pg 268) */

#include <curses.h>

main()
{
initscr();	/* turn on curses */
nocbreak();	/* turn on line buffering */
		/* by default keyboard input is unbuffered */
getch();	/* wait for user input */
endwin();	/* turn off curses */
}

