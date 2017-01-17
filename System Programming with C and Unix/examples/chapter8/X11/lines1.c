
	/* Demonstrate drawing lines. (pgs 280-281) */

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

main(int argc, char *argv[])

{
Display			*Monitor;
Window			DrawWindow;
GC			WindowGC;
XWindowAttributes	Atts;
int			x1,y1,x2,y2;


Monitor=XOpenDisplay(NULL);
if (Monitor == NULL)
  {
  printf("Unable to open graphics display\n");
  exit(0);
  }

DrawWindow=XCreateSimpleWindow(Monitor,RootWindow(Monitor,0),
	10,10,		/* x,y on screen */
	100,50,		/* width, height */
	2, 		/* border width */
	BlackPixel(Monitor,0),
	WhitePixel(Monitor,0));

WindowGC=XCreateGC(Monitor,DrawWindow,0,NULL);

XMapWindow(Monitor,DrawWindow);
XFlush(Monitor);
while(1)
  {
  XGetWindowAttributes(Monitor,DrawWindow,&Atts);
  if (Atts.map_state == IsViewable /* 2 */)
    break;
  }

while (1)
  {
  printf("Line coordinates? ");
  scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
  if (x1 == -1)
    break;
  XDrawLine(Monitor,DrawWindow,WindowGC,x1,y1,x2,y2);
  XFlush(Monitor);
  }

XCloseDisplay(Monitor);
}

