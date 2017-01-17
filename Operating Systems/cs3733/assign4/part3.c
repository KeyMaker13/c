#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define MILLION 1000000L


int main (int argc, char *argv[]){

   int adder = 0;
   long long catcher;
   int i = 0;
   long long increase = -1;
   int lengthcheck;
   int lengthcheck2;
   int loop = 1;
   int numfind = 0;   
   long long *primegreater;
   long long primeparameter;
   long timedif;
   double timedifout;
   struct timeval tpend;
   struct timeval tpstart;

   if ( argc < 3  ){
      fprintf(stderr, " Please enter 1 integer parameter\n");
      exit(-1);
   } else if ( argc > 3 ){
      fprintf(stderr, " Please enter 1 integer parameter\n");
      exit(-1);
   }
   
   if ( strlen(argv[1]) > 25  ) {
      fprintf(stderr, " Please do not try to buffer overflow\n");
      exit(-1);
   }   

   if ( strlen(argv[2]) > 25 ) {
      fprintf(stderr, " Please do not try to buffer overflow\n");
      exit(-1);
   }

   lengthcheck = strlen(argv[1]);
   lengthcheck2 = strlen(argv[2]);
   for ( i = 0; i < lengthcheck; i++){
      if ( isalpha(argv[1][i]) ){
         fprintf(stderr, " Please only enter digits \n");
         exit(-1);         
      } else if ( isdigit(argv[1][i])  ) {
         
         
      } else {
         fprintf(stderr," Please only enter digits \n");
         exit(-1);
      }         
      
   }   

   for ( i = 0; i < lengthcheck2; i++){
      if ( isalpha(argv[2][i]) ){
         fprintf(stderr, " Please only enter digits \n");
         exit(-1);         
      } else if ( isdigit(argv[2][i])  ) {
         
         
      } else {
         fprintf(stderr," Please only enter digits \n");
         exit(-1);
      }         
      
   }

   fprintf(stderr, "This is part 3\n");
   fprintf(stderr, "Ivan Capistran\n");	   
   fprintf(stderr, "Parameter: %s %s\n" ,argv[1], argv[2]);
   primeparameter = atoll(argv[1]);
   numfind = atoi(argv[2]);

   primegreater = (long long *)malloc(sizeof(long long) * numfind);

   if (gettimeofday(&tpstart, NULL)) {
      fprintf(stderr, "Failed to get start time\n");
      return 1;
   }
  
 
   while(numfind > 0){   
      ++increase;
      catcher = ( primeparameter + increase );   
      if ( isPrimeLongLong( catcher )){
         primegreater[adder] = (catcher);
         ++adder;
         --numfind;
      }      
   }

   if (gettimeofday(&tpend, NULL)) {
      fprintf(stderr, "Failed to get end time\n");
      return 1;
   }   
                                               /* standard output */

   printf("%lld\n", primeparameter);

   for (i = 0; i < (adder); i++){
      printf("%lld\n",primegreater[i]);
      
   }

                                                 /* standard err  */
   fprintf(stderr,"%lld\n", primeparameter);
   for (i = 0; i < (adder); i++){
      fprintf(stderr,"%lld\n",primegreater[i]);
      
   }

   timedif = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

   timedifout = timedif/1000000.0;
   fprintf(stderr,"%.5lf\n", timedifout);
   free(primegreater);
   return 0;
}

