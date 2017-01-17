#include <stdio.h>
#include <strings.h>
#include "pslibrary.h"

int main (int argc, char *argv[]){

int cstart = 0, p[2][3], runningtotal = 0, tempv;


/* checking for parameters */
	if (argc < 8 ){
		printf("Not enough parameters\n");
		return (-1);
	} else if (argc > 8) {
		printf("Too many parameters\n");
		return(-1);
	}

	printf("Assignment 1 program was written by I. Capistran\n");
/* here i am printing out what the user print in the cmd line arguments */
	*argv++;
	printf("inputs: ");
	while ( *argv ) {
		if (cstart >= 1) {
			tempv = atoi(*argv);
			runningtotal += tempv;
		
			/* first 3 numbers */
			if ( cstart <= 3 ){
				p[0][cstart-1] = tempv;

			/* rest of the numbers */
			} else {
				p[1][cstart-4] = tempv;
			}

		}
		 
		printf("%s ",*argv);	
		*argv++;
		cstart++;
	}
	printf("\n");

	printf("Running total is : %d\n",runningtotal);

	int stringsize = runningtotal;
	char str1[stringsize];
	char str2[stringsize];
	fcfsa(str1,str2,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);
	display("Part 1\n",str1,str2);
	return 0;
}
