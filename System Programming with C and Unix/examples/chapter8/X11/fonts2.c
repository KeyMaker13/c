
    /* Demonstrate querying a list of fonts, and showing how each looks. */
	/* Must use -L/usr/X11R6/lib and -lX11 to compile */

	/* A good in-class exercise */

#include <stdio.h>
#include <X11/Xlib.h>

main(int argc, char *argv[])

{
Display			*Monitor;
Window			DrawWindow;
GC			WindowGC;
XWindowAttributes	Atts;
XGCValues		GCValues;
unsigned long		GCmask;
int			i,j,y;
XEvent			SomeEvent;
char			text[320],partial_name[320];
Font			NewFont;
char			**AvailableFonts;
int			font_count;


Monitor=XOpenDisplay(NULL);
if (Monitor == NULL)
  {
  printf("Unable to open graphics display\n");
  exit(1);
  }

DrawWindow=XCreateSimpleWindow(Monitor,RootWindow(Monitor,0),
	10,10,		/* x,y on screen */
	140,350,	/* width, height */
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
  printf("Font to query? ");
  scanf("%s",partial_name);
  if (strcmp(partial_name,"quit") == 0)
    break;

  sprintf(text,"*%s*",partial_name);
  AvailableFonts=XListFonts(Monitor,text,200,&font_count);
  for (i=0; i<font_count; i++)
    printf("%s\n",AvailableFonts[i]);
  fflush(stdout);

  XClearWindow(Monitor,DrawWindow);
  y=20;
  for (i=0; i<font_count; i++)
    {
    NewFont=XLoadFont(Monitor,AvailableFonts[i]);

    GCmask=GCForeground | GCFont;
    GCValues.foreground=0xFF0000;
    GCValues.font=NewFont;
    j=XChangeGC(Monitor,WindowGC,GCmask,&GCValues);
    if (j == 0)
      {
      printf("Unable to change GC values\n");
      exit(1);
      }

    strcpy(text,"Hello!");
    XDrawString(Monitor,DrawWindow,WindowGC,0,y,text,strlen(text));
    y+=20;
    XFlush(Monitor);

    XUnloadFont(Monitor,NewFont);
    }
  XFreeFontNames(AvailableFonts);
  }

XCloseDisplay(Monitor);
}

