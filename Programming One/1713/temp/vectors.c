/*
Write functions that take a single 1-D array
(AKA a vector), and its length (the number of
elements in the array), and returns (write a 
separate function for each of these operations):
(1) The summation of all elements
(2) The minimum value found in the elements
(3) The index of the minimum value found in the elements
	 -> If two indices have the same value, then 
		 return the larger one
(4) The maximum value found in the array.
(5) The index of the maximum value in the array.
(6) The product of all elements in the array.

For each of these functions, write a main routine
that tests them by passing vectors with known 
answers that you create to make sure they work.

**MODIFICATIONS**:
(1) Copy one of these functions, write a main routine
	 using a different loop type (eg., for -> while)
*/


#include <stdio.h>
#include <stdlib.h>


int sumAll(int c[], int i)
{
	int j,sum=0;
	for (j=0; j < i; j++)
		sum = sum + c[j];
	
	return sum;
}


int maxIndex(int c[], int i)
{
	int j,iMax = 0;
	for (j = 1; j < i; j++)
		if (c[j] > c[iMax])
			iMax = j;

	return iMax;
}




int minIndex(int c[], int i)
{
	int j, iMin=0;
	for (j = 1; j < i; j++)
		if (c[j] < c[iMin]) 
			iMin = j;
	return iMin;
}

int maxValue(int c[], int i)
{
	int j, iMax=c[0];
	for (j=1; j< i; j++)
		if (c[j] > iMax)
			iMax = c[j];
	return iMax;
}

int minValue(int c[], int i)
{
	int j,min = c[0];
	for (j=1; j<i; j++)
	{
		if (c[j] < min)
			min = c[j];
	}
	return min;
}

int productOfAll(int c[], int i)
{
	int product=c[0],j;
	for ( j=1; j<i; j++)
		product=product*c[j];
	
	return product;
}



int main(void)
{
	int j[] = {4,10,19,42,15,53,36}, capacity = 7;
	
	printf("The smallest value in the vector is: %d\n", minValue(j, capacity));
	printf("The product of all the values in the vector is: %d\n", productOfAll(j, capacity));
	printf("The maximum value in the vector is: %d\n", maxValue(j, capacity));
	printf("The index of the minimum value of the vector is: %d\n", minIndex(j, capacity));
	printf("The sum of the vectors is: %d\n", sumAll(j, capacity));
	printf("The max value index is: %d\n", maxIndex(j, capacity));
	


}




