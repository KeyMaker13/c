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
      return (1);
   } else if (argc > 8) {
      printf("Too many parameters\n");
      return(1);
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

   //printf("Running total is : %d\n",runningtotal);
   /*
   int t = 1;
   while ( t <= 3) {
      printf("number 1 is :%d\n",p[0][t-1]);
      printf("number 2 is :%d\n",p[1][t-1]);
      t++;
   }
   */

   int stringsize = runningtotal;

   char str1[stringsize];
   char str2[stringsize];
		
   //part0(str1,str2);
   //printf("here : %d\n",p[0][0]);
   //printf("here : %d\n",p[0][1]);
   //printf("here : %d\n",p[0][2]);
   //printf("here : %d\n",p[1][0]);
   //printf("here : %d\n",p[1][1]);
   //printf("here : %d\n",p[1][2]);

   fcfsa(str1,str2,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);

   display("Part 0\n",str1,str2);
   //display("Part 1\n",str1,str2);
	
   //printf("str1 = %s\n",str1);
   //printf("str2 = %s\n",str2);
   return 0;
}
