
	/* Demonstrate using XListFonts to find font names */
	/* Should also demonstrate xlsfonts shell command */
	/* (pg 288) */

#include <stdio.h>
#include <X11/Xlib.h>

main()

{
char		text[80],partial[80];
char		**AvailableFonts;
int		font_count,i;
Display		*Monitor;

Monitor=XOpenDisplay(NULL);
printf("Enter a string to search: ");
scanf("%s",partial);
sprintf(text,"*%s*",partial);
AvailableFonts=XListFonts(Monitor,text,10,&font_count);
for (i=0; i<font_count; i++)
  printf("%s\n",AvailableFonts[i]);
XFreeFontNames(AvailableFonts);
XCloseDisplay(Monitor);
}

