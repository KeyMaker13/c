
	/* Demonstrate changing graphics context - properties of lines. */
	/* (pgs 282-283) */

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
XGCValues		GCValues;
unsigned long		GCmask;
int			i;


Monitor=XOpenDisplay(NULL);
if (Monitor == NULL)
  {
  printf("Unable to open graphics display\n");
  exit(1);
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

	/* change the foreground color to blue */
GCmask=GCForeground;
GCValues.foreground=0x0000FF;	/* red is 0xFF0000 .... why? */
	/* man XChangeGC to see all properties you can change in the GC */
i=XChangeGC(Monitor,WindowGC,GCmask,&GCValues);
if (i == 0)
  {
  printf("Unable to change GC values\n");
  exit(1);
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

