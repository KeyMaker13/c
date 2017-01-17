/*
Write a void function (a function that does not return
a value) that takes only two arguments (used for both 
input and output) and:
(1) Takes as input an integer array and its length
(2) Allocates a new array of the current length +
	 CHUNKSIZE, where CHUNKSIZE is a non-zero
	 positive value macro set by you to 2
(3) Copies the old array into the new, longer one
(4) Frees the old array
(5) Zeros any unused entries in the new array


Test this function by writing a main routine that starts
out with a malloced array of length 2, initialized to 
{0,1}, and then print out the new array you get back from
calling your two-argument void function. Don't forget to
use valgrind to ensure no memory leaks.
*/


#include <stdio.h>
#include <stdlib.h>

void setAndMakeArray(float *in1, float *in2)
{


}


int main(int nargs, char *argv[])
{


	return 0;
}
