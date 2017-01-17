
	/* Demonstrate events - look for button presses */
	/* (pg 284) */

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
unsigned long int	GCmask;
int			i;
XEvent			SomeEvent;
long int		event_mask;


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

	/* Tell X server which events should be passed to this application */
	/* see /usr/include/X11/X.h for complete list of masks */
event_mask=ButtonPressMask;
XSelectInput(Monitor,DrawWindow,event_mask);

while (1)
  {
  XNextEvent(Monitor,&SomeEvent);
	/* man XEvent, and its derivatives (e.g. XButtonEvent, XKeyEvent)
	** for complete lists of event types and contents */
  if (SomeEvent.type == ButtonPress)
    printf("Button pressed!\n");
  }

XCloseDisplay(Monitor);
}

