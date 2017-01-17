/*
Student Name: Abel Atkinson
Assignment: Monte Carlo Simulation
Class: CS1713
*/




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159
#define RADIUS 140


/*
This function will be called twice to "throw a dart"
and return a random number between minval and maxval 
(inclusive).
*/

double RandNumInRange(double minval, double maxval)
{

	return ((double)rand()) / ((double) RAND_MAX) * (maxval - minval) + minval;

}


/*
This function determines if the "dart" hits on or within our shape
by calling this function. It shall return an int value of 1 if
it is on or within the shape, if not, then it will return 0.
*/

int dartHits(double x, double y)
{
	
	double distance = sqrt((x*x) + (y*y));

	if (distance <= RADIUS)
		return 1;
	else
		return 0;

}



/*
This is where the main method of the program begins. It will attempt to
determine the area of a shape given a certain quantity of virtual darts
and the percentage of times it hits the shape.
*/
int main(void)
{
	double xMin = (-200), xMax = 200, yMin = (-200), yMax = 200;
	double rectArea = (xMax - xMin) * (yMax - yMin);
	double circleArea = PI * (RADIUS * RADIUS); 
	double xDart, yDart;
	unsigned long int nDarts;
	unsigned int iseed = (unsigned int)time(NULL);

	srand (iseed);


	printf("Enter an integer greater than 0 for the amount of \
			\ndarts you wish to throw. If 0 is entered, the program will close: ");
	scanf("%lu", &nDarts);
	if (nDarts == 0)
	{
		printf("\nGoodbye!\n\n");
		exit(0);
	}
	
	
		
	

/*
The while statement below continues to send virtual darts to the
box built around the shape until the desired quantity has been
reached.
*/
	int	n = 0, nHits = 0;
	while(n < nDarts)
	{
		xDart = RandNumInRange(xMin, xMax);
		yDart = RandNumInRange(yMin, yMax);

		if (dartHits(xDart, yDart) != 0)
			nHits++;
		n++;
	}
	
/*
The following double variables were just used to make the
printf statements look cleaner when placing the result with their
conversion characters.
*/
	double computedArea = ((double)(((rectArea * nHits) / nDarts)));
	double temp = fabs(computedArea - circleArea);
	double absolute = (temp / circleArea) * 100;

/*
The following print statements are to show the results of the
Monte Carlo Integration performed on the circle.
*/
	printf("\nLength and width of rectangle = %.0f x %.0f\n\n",
			(xMax - xMin), (yMax - yMin));
	printf("Area of the enclosing rectangle = %.0f\n\n", rectArea);
	printf("Number of darts thrown = %lu\n\n", nDarts);
	printf("Number of darts that hit the shape = %d\n\n", nHits);
	printf("Percentage of darts that hit the shape =  %.2f%%\n\n",
			((double)(nHits * 100 / n)));
	printf("Computed area = %.2f\n\n", 
			((double)(((rectArea * nHits) / nDarts))));
	printf("Actual area = %.2f\n\n", circleArea);
	printf("Percent error = %.2f%%\n", absolute);


	return 0;

}
	
