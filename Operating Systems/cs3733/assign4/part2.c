#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define MILLION 1000000L
 

int main (int argc, char *argv[]){

   int lengthcheck;
   int loop = 1;
   int i = 0;
   long long increase = 0;
   long long primegreater;
   long long primeparameter;
   long timedif;
   double timedifout;
   struct timeval tpend;
   struct timeval tpstart;


   if ( argc < 2  ){
      fprintf(stderr, " Please enter 1 integer parameter\n");
      exit(-1);
   } else if ( argc > 2 ){
      fprintf(stderr, " Please enter 1 integer parameter\n");
      exit(-1);
   }
   
   if ( strlen(argv[1]) > 25  ) {
      fprintf(stderr, " Please do not try to buffer overflow\n");
      exit(-1);
   }   

   lengthcheck = strlen(argv[1]);
   
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

   fprintf(stderr, "This is part 2\n");
   fprintf(stderr, "Ivan Capistran\n");	   
   fprintf(stderr, "Parameter: %s\n" ,argv[1]);
   
   primeparameter = atoll(argv[1]);	
   

   if (gettimeofday(&tpstart, NULL)) {
      fprintf(stderr, "Failed to get start time\n");
      return 1;
   }

   while(1){
      if ( isPrimeLongLong( primeparameter + increase )){
         primegreater = (primeparameter + increase);
         break;
      }
      increase++;
   }

   if ( gettimeofday(&tpend, NULL) ) {
      fprintf(stderr, "Failed to get end time\n");
      return 1;
   }


                                      /* standard output */

   printf("%lld\n", primeparameter);
   printf("%lld\n", primegreater); 

                                        /* standard err  */
   fprintf(stderr,"%lld\n", primeparameter);
   fprintf(stderr,"%lld\n", primegreater);

   timedif = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
   timedifout = timedif/1000000.0;

   fprintf(stderr,"%.5lf\n", timedifout);
   return 0;
}
