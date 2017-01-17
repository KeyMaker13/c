#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pslibrary.h"

int main (int argc, char *argv[]){
   
   char argvtemp[50];
   char **argvtemp2;
   int cstart = 0;
   int i = 0;
   int lengthtemp = 0;
   int p[2][3];
   int runningtotal = 0;
   int tempv;
      

   /* checking for parameters */
   if ( argc < 8 ){
      printf("Not enough parameters\n");
      return (1);
   } else if (argc > 8) {
      printf("Too many parameters\n");
      return(1);
   }
   
   /* this is checking to see if there is any characters in the cmd line parameters */
   argvtemp2 = argv;
   *argvtemp2++;
   while( *argvtemp2  ){
         
         lengthtemp = strlen(*argvtemp2);
         if (lengthtemp > 50) {
            printf("Please do not try to buffer overflow\n");
            return 0;
         }
         strcpy(argvtemp,*argvtemp2);
         

         for ( i = 0; i < lengthtemp; i++ ){
            if ( isalpha( argvtemp[i]) ) {
    	       printf("Please only enter digits\n");
               return 0;
	    } else if ( isdigit( argvtemp[i]) ) {
    	       

	    } else {
	       printf("Please only enter digits\n");
               return 0;
	    }
         } 
      *argvtemp2++;
   }



   /* This is checking to see if any of the input is too big */
   if ( atoi(argv[1]) > 50){
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
      return(1);
   }
   if ( atoi(argv[2]) > 50 ) {
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
      return(1);
   }
   if ( atoi(argv[3]) > 50 ) {
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
      return(1);
   }
   if ( atoi(argv[4]) > 50 ) {
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
      return(1);
   }
   if ( atoi(argv[5]) > 50 ) {
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
      return(1);
   }
   if ( atoi(argv[6]) > 50 ) {
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
      return(1);
   }
   if ( atoi(argv[7]) > 50 ) {
      printf("One of the number entered is too big\n");
      printf("Please enter a number that is less than or equal to 50\n");
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
   
   int stringsize = runningtotal;
   char str1[stringsize];
   char str2[stringsize];
   fcfsa(str1,str2,p[0][0],p[0][1],p[0][2],p[1][0],p[1][1],p[1][2]);
   display("Part 1\n",str1,str2);
   return 0;
}
