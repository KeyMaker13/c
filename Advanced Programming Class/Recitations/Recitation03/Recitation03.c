#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

//constants
//#define PI 

//prototypes
void UserInstructions(void);
static void GetCoefficients(double *a1, double *a2, double *b1, double *b2, double *c1, double *c2);
static void SolveIntersection(double a1, double a2, double b1, double b2, double c1, double c2, double *x0, double *y0); 
static void SolveAngle(double a1, double a2, double b1, double b2, double *angle);
void DisplayResult(double x0, double y0, double angle);

main(){
//Values
double A1, A2, B1, B2, C1, C2;

//Display
double X0,Y0,ANGLE;

UserInstructions();
GetCoefficients(&A1, &A2, &B1, &B2, &C1, &C2);
SolveIntersection(A1, A2, B1, B2, C1, C2, &X0, &Y0);
SolveAngle(A1,A2,B1,B2,&ANGLE);
DisplayResult(X0,Y0,ANGLE);
}

void UserInstructions(){
printf("I will ask you for the coefficients for two lines\n");
printf("coefficients for these two equations\n");
printf("A1x +B1y + C1 = 0 and A2x + B2y + C2 = 0\n");
printf("I will compute the intersection point in the form of x0 and y0 values\n");
printf("I will also determin the angle in terms of degrees\n");
}

void DisplayResult(double x0, double y0, double angle){
printf("x0 : %lf  y0 : %lf  angle : %lf ",x0,y0,angle);
}

static void GetCoefficients(double *a1, double *a2, double *b1, double *b2, double *c1, double *c2){
printf("Enter first equation\n");
printf("A1 : ");
*a1 = GetReal();
printf("B1 : ");
*b1 = GetReal();
printf("C1 : ");
*c1 = GetReal();

printf("\nEnter second equation\n");
printf("A2 : ");
*a2 = GetReal();
printf("B2 : ");
*b2 = GetReal();
printf("C2 : ");
*c2 = GetReal();
}

static void SolveIntersection(double a1, double a2, double b1, double b2, double c1, double c2, double *x0, double *y0){
if( ( (a1*b2) - (a2*b1) ) == 0 ){
printf("no intersection\n");
}
else if (a1 == 0 || b1 == 0 || a2 == 0 || b2 == 0){
printf("Ha your coefficients are zero's you fail this course\n");
}
else{
*x0 = ( ((b1*c2) - (b2*c1)) / ((a1*b2) - (a2*b1)) );
*y0 = ( ((c1*a2)-(c2*a1)) / ( (a1*b2)-(a2*b1) ));
}
} 

static void SolveAngle(double a1, double a2, double b1, double b2, double *angle){
*angle =( ( ( (a1*a2)-(b1*b2) ) / (sqrt(a1*a1 + b1*b1)*sqrt(a2*a2 + b2*b2)) ) * 180) / (double)(22/7) ;
}




