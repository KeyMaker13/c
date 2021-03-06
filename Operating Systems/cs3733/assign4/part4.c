#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#define MILLION 1000000L

static int adder = 0;
static long long increase = -1;
static int mutex = 1;
static int numtofind = 0;
static long long primepassed = 0;
static long long *primesfound;

void *find_prime(void *arg){

   long long catcher = 0;   

   while(numtofind > 0){

      wait(mutex);
      ++increase;   
      catcher = (primepassed + increase);
      signal(mutex);
      
      if ( isPrimeLongLong( catcher )){
         wait(mutex);   
         primesfound[adder] = (catcher);
         ++adder;
         --numtofind; 
         signal(mutex);
      }
   }
   
   pthread_exit((void*) arg);
}

int main (int argc, char *argv[]){

   pthread_attr_t attr;
   int c;
   int d;
   int error;
   int fd;
   int i = 0;
   long long primeparameter;
   int numfind;
   int numthreads;	
   int lengthcheck;
   int lengthcheck2;
   int lengthcheck3;
   void *status;
   long long t;  
   long timedif;
   double timedifout;
   struct timeval tpend;
   struct timeval tpstart;

   if ( argc < 4  ){
      fprintf(stderr, " Please enter 3 integer parameter\n");
      exit(-1);
   } else if ( argc > 4 ){
      fprintf(stderr, " Please enter 3 integer parameter\n");
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

   if ( strlen(argv[3]) > 25){
      fprintf(stderr, " Please do not try to buffer overflow\n");
      exit(-1);
   }

   lengthcheck = strlen(argv[1]);
   lengthcheck2 = strlen(argv[2]);
   lengthcheck3 = strlen(argv[3]);

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

   for ( i = 0; i < lengthcheck3; i++){
      if ( isalpha(argv[3][i]) ){
         fprintf(stderr, " Please only enter digits \n");
         exit(-1);
      } else if ( isdigit(argv[3][i])  ) {


      } else {
         fprintf(stderr," Please only enter digits \n");
         exit(-1);
      }
   }

   fprintf(stderr, "This is part 4\n");
   fprintf(stderr, "Ivan Capistran\n");	   
   fprintf(stderr, "Parameter: %s %s %s \n" ,argv[1], argv[2], argv[3]);
   primeparameter = atoll(argv[1]);
   numfind = atoi(argv[2]);
   numthreads = atoi(argv[3]);	

   long long primegreater[numfind];
   primesfound = primegreater;
   
   pthread_t thread[numthreads];
   int threadfd[numthreads];
   
   primepassed = primeparameter;
   numtofind = numfind;
   
   /* Initialize and set thread detached attribute */
   pthread_attr_init(&attr);
   pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
   pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); 
   
   /* get time of day */
   if (gettimeofday(&tpstart, NULL)) {
      fprintf(stderr, "Failed to get start time\n");
      return 1;
   }

   /* call all threads */
   for (i = 0; i < numthreads; i++){
      if (error = pthread_create(&thread[i], &attr, find_prime, &threadfd[i]))
         fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
   }

   /* join the threads  */
   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
   for( i=0; i<numthreads; i++ ) {
      if ( error  = pthread_join(thread[i], &status) )
         fprintf(stderr, " Failed to join thread %s\n", strerror(error));   
   }

   if (gettimeofday(&tpend, NULL)) {
      fprintf(stderr, "Failed to get end time\n");
      return 1;
   }

   /* Sort the array */
   for (c = 1 ; c <= adder - 1; c++) {
      d = c;
 
      while ( d > 0 && primesfound[d] < primesfound[d-1]) {
      t          = primesfound[d];
      primesfound[d]   = primesfound[d-1];
      primesfound[d-1] = t;
 
      d--;
    }
  }


   /* standard output */
   printf("%lld\n", primeparameter);
   
   for (i = 0; i < numfind; i++){
      printf("%lld\n",primesfound[i]);
   }
   
   /* standard err  */
   fprintf(stderr,"%lld\n", primeparameter);
   for (i = 0; i < numfind; i++){
      fprintf(stderr,"%lld\n",primesfound[i]);
   }
   
   timedif = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
   timedifout = timedif/1000000.0;

   fprintf(stderr,"%.5lf\n", timedifout);
   
   pthread_exit(NULL);
   return 0;

}
