#include <stdio.h>
#include <math.h>


int main(){

/* Part A */

double a,b,c,d; 

printf("Part A \n"); 

printf("Enter values for a,b,c,d\n"); 

printf("Enter a\n"); 

scanf("%lf",&a);

printf("Enter b\n");

scanf("%lf",&b);

printf("Enter c\n");

scanf("%lf",&c);

printf("Enter d\n");

scanf("%lf",&d);

double res = ((a+b)/(c-d)) + (sqrt(a+c)/(a-b)) + ((c+b)/(a+c));

printf("\nYour new result is %.3lf \n ",res);

/* Part B */

printf("\nPartB\n");

int x;

printf("Enter a number (integer) from the range [100-999]  and I will reverse it for you :-O\n ");

scanf("%d",&x);

int r1,r2,r3,rOutput;

r1 = x/100;
r2 = x%100/10;
r3 = x%10;

rOutput = r3*100 + r2*10 + r1;

printf("\nYour new reversed number is :-D %d \n",rOutput);

return 0;
}
