
	/* Demonstrate loading a font and drawing text. */
	/* Must use -L/usr/X11R6/lib and -lX11 to compile */
	/* (pgs 286-287) */

#include <stdio.h>
#include <X11/Xlib.h>

main(int argc, char *argv[])

{
Display			*Monitor;
Window			DrawWindow;
GC			WindowGC;
XWindowAttributes	Atts;
int			x1,y1;
XGCValues		GCValues;
unsigned long		GCmask;
int			i,WhichPoint;
XEvent			SomeEvent;
char			text[80];
Font			NewFont;


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

NewFont=XLoadFont(Monitor,"r14");

GCmask=GCForeground | GCFont;
GCValues.foreground=0xFF0000;
GCValues.font=NewFont;
i=XChangeGC(Monitor,WindowGC,GCmask,&GCValues);
if (i == 0)
  {
  printf("Unable to change GC values\n");
  exit(1);
  }

XSelectInput(Monitor,DrawWindow,ButtonPressMask);

while (1)
  {
  XNextEvent(Monitor,&SomeEvent);
  if (SomeEvent.type == ButtonPress)
    {
    x1=SomeEvent.xbutton.x;
    y1=SomeEvent.xbutton.y;
    strcpy(text,"Hello!");
    XDrawString(Monitor,DrawWindow,WindowGC,x1,y1,text,strlen(text));
    XFlush(Monitor);
    }
  }

XCloseDisplay(Monitor);
}

