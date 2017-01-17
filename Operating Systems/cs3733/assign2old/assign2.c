#include <stdio.h>
#include <strings.h>
#include "pslibrary.h"

int main (int argc, char *argv[]){
   int cstart = 0;
   int p[2][3];
   int runningtotal = 0;
   int tempv;
                                              /* checking for parameters */
   if (argc < 8 ){
      printf("Not enough parameters\n");
      return (-1);
   } else if (argc > 8) {
      printf("Too many parameters\n");
      return(-1);
   }
   printf("Assignment 1 program was written by I. Capistran\n");
   /* here i am printing out what the user put in the cmd line arguments */
   int q = atoi(argv[1]);
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
   //part0(str1,str2);
   //fcfsa(str1,str2,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);	
   proto(str1,str2,q,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);
   display("FCFS \n",str1,str2);
   sjf(str1,str2,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);
   display("SJF \n", str1, str2);
   psjf(str1,str2,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);
   display("PSJF \n", str1, str2);
   rr(str1,str2,q,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);
   display("Round Robbin\n",str1,str2);
   return 0;
}
