
	/* Demonstrate accessing event properties (pgs 285-286) */

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
int			i,WhichPoint;
XEvent			SomeEvent;


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

GCmask=GCForeground;
GCValues.foreground=0xFF00FF;
i=XChangeGC(Monitor,WindowGC,GCmask,&GCValues);
if (i == 0)
  {
  printf("Unable to change GC values\n");
  exit(1);
  }

XSelectInput(Monitor,DrawWindow,ButtonPressMask);

WhichPoint=0;	/* 0=>first point, 1=>second point */
while (1)
  {
  XNextEvent(Monitor,&SomeEvent);
  if (SomeEvent.type == ButtonPress)
    {
    printf("Button pressed!\n");
    if (WhichPoint == 0)
      {
      x1=SomeEvent.xbutton.x;
      y1=SomeEvent.xbutton.y;
      WhichPoint=1;
      }
    else
      {
      x2=SomeEvent.xbutton.x;
      y2=SomeEvent.xbutton.y;
      WhichPoint=0;
      if (x1 == x2  &&  y1 == y2)
        break;
      XDrawLine(Monitor,DrawWindow,WindowGC,x1,y1,x2,y2);
      XFlush(Monitor);
      }
    }
  }

XCloseDisplay(Monitor);
}

