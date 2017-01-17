
	/* An example program that links to multiple librarys. */
	/* Draw right triangles. Also demonstrates XDrawArc(). */
	/* An in-class exercise. */

#include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>
#include "tris.h"

#define WIDTH 140
#define HEIGHT WIDTH

main(int argc, char *argv[])

{
Display			*Monitor;
Window			DrawWindow;
GC			WindowGC;
XWindowAttributes	Atts;
int			x1,y1,x2,y2,x3,y3,radius,angle;
struct Triangle		triangle;
double			area,TriArea();


Monitor=XOpenDisplay(NULL);
if (Monitor == NULL)
  {
  printf("Unable to open graphics display\n");
  exit(0);
  }

DrawWindow=XCreateSimpleWindow(Monitor,RootWindow(Monitor,0),
	10,10,		/* x,y on screen */
	WIDTH,HEIGHT,	/* width, height */
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
  printf("Radius and angle? ");
  scanf("%d %d",&radius,&angle);
  if (radius == -1)
    break;
  x1=WIDTH/2;
  y1=HEIGHT/2;
  x2=x1+(int)(cos((double)angle*M_PI/180.0)*radius);
  y2=y1-(int)(sin((double)angle*M_PI/180.0)*radius);
  x3=x2;
  y3=y1;
  printf("%d,%d %d,%d %d,%d\n",x1,y1,x2,y2,x3,y3);
  XDrawLine(Monitor,DrawWindow,WindowGC,x1,y1,x2,y2);
  XDrawLine(Monitor,DrawWindow,WindowGC,x1,y1,x3,y3);
  XDrawLine(Monitor,DrawWindow,WindowGC,x3,y3,x2,y2);
  XDrawArc(Monitor,DrawWindow,WindowGC,x1-radius,y1-radius,radius*2,radius*2,0,angle*64);
  XFlush(Monitor);
  triangle.x=x1;
  triangle.y=y1;
  triangle.radius=radius;
  triangle.angle=angle;
  area=TriArea(triangle);
  printf("Area is %lf\n",area);
  }

XCloseDisplay(Monitor);
}

