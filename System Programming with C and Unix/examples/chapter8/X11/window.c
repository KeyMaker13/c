
	/* Demonstrates creating a window. (pgs 278-279) */
	/* To compile:  gcc -o window window.c -L/usr/X11R6/lib -lX11 */

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>	/* X library definitions */


main(int argc, char *argv[])

{
Display			*Monitor;	/* screen to display on */
Window			DrawWindow;	/* the window to be created */
GC			WindowGC;	/* graphics context */
XWindowAttributes	Atts;		/* window attributes */


	/* First, every X program must connect to a display */
Monitor=XOpenDisplay(NULL);
if (Monitor == NULL)
  {
  printf("Unable to open graphics display\n");
  exit(0);
  }

	/* Create a simple window - a regular window has more attributes */
DrawWindow=XCreateSimpleWindow(Monitor,RootWindow(Monitor,0),
	10,10,				/* x,y on screen */
	100,50,				/* width, height */
	2, 				/* border width */
	BlackPixel(Monitor,0),		/* foreground color */
	WhitePixel(Monitor,0));		/* background color */

	/* Create a default graphics context */
WindowGC=XCreateGC(Monitor,DrawWindow,0,NULL);

	/* Place the window onscreen, and wait until it actually appears */
XMapWindow(Monitor,DrawWindow);
XFlush(Monitor);
while(1)
  {
  XGetWindowAttributes(Monitor,DrawWindow,&Atts);
  if (Atts.map_state == IsViewable /* 2 */)
    break;
  }

	/* wait 2 seconds, then close X server connection and quit */
sleep(2);
XCloseDisplay(Monitor);
}

