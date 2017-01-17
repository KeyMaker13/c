
	/*
	** An example file of functions to be put into a library.
	*/

#include <stdio.h>

	/*
	** Compare two integers, return 1 if first is larger, 2
	** if second is larger, 0 if they are the same.
	*/

int Largest(int first, int second)

{
if (first > second)
  return(1);
else if (second > first)
  return(2);
else
  return(0);
}
