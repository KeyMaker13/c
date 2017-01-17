
	/* Used to make library for tris in-class exercise */

#include <math.h>
#include "tris.h"

double TriArea(struct Triangle tri)

{
double area,height,width;

width=(double)tri.radius*cos((double)tri.angle*M_PI/180.0);
height=(double)tri.radius*sin((double)tri.angle*M_PI/180.0);
area=fabs(0.5*height*width);

return(area);
}

