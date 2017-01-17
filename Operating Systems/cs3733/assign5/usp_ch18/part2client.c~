#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "primelib.h"
#include "restart.h"
#include "uici.h"
#define MILLION 1000000L

int adder = 0;
long long increase = -1;
int mutex = 1;
int numtofind = 0;
long long primepassed = 0;
long long *primesfound;



static int *fd;

void *find_prime(void *arg){

int *ind = (int*)arg;
int index = *ind;
int maxfd;
long long catcher = 0;
int lengthcheck = 0;

char buffer[1024];
char buff[1];
int bytesread;
fd_set readset;

int totalbytes = 0;
int num;


while( numtofind > 0 ){

      maxfd = fd[index];
      wait(mutex);
      ++increase;   
      catcher = (primepassed + increase);
      sprintf(buffer, "%lld",catcher);
      lengthcheck = strlen(buffer);
      signal(mutex);   
        
     
   for ( ; ; ) { 

      
      if ( (bytesread = r_write(fd[index], buffer , lengthcheck )) == lengthcheck ){
 	continue;
      } else if ( (bytesread = r_read(fd[index],buff, 1)) == 1){
         printf("here : %c\n",buff[0]);

         if (buff[0] == '0' ){
            break;
         } else if (buff[0] == '1'){
            wait(mutex);   
            primesfound[adder] = (catcher);
            ++adder;
            --numtofind; 
            signal(mutex);
            break;
         }

      }else {
         continue;
      }
     
 
   }

}

   close(fd[index]);   

   pthread_exit((void*) arg);
}


int main(int argc, char *argv[]) {

/* reorganize */

   char buff[1024];
   int bytescopied;
   int bytesread;
   int flag = 0;    

   int i = 0;
   int i2 = 0;
   int lengthcheck = 0;
   int lengthcheck2 = 0;

   u_port_t portnumber;
 
   int maxfd;
   int num;
   fd_set readset;
   int totalbytes = 0;


   pthread_attr_t attr;
   int c;
   int d;
   int error;
   long long primeparameter;
   int numfind;
   int numthreads;	

   int lengthcheck3;
   void *status;
   long long t;  
   long timedif;
   double timedifout;
   struct timeval tpend;
   struct timeval tpstart;

  

   int hostremain = 0;

   if (argc < 5) {
      fprintf(stderr, "Usage: %s *prime* *number of primes to find* *port* *host,host,host*\n", argv[0]);
      return 1;
   }

   if ( strlen(argv[1]) > 25  ) {
      fprintf(stderr, " Please do not try to buffer overflow\n");
      return 1;
   }   

   if ( strlen(argv[2]) > 25 ) {
      fprintf(stderr, " Please do not try to buffer overflow\n");
      return 1;
   }

   if ( strlen(argv[3]) > 25 ){
      fprintf(stderr, " Please do not try to buffer overflow\n");
      return 1;
   }

   if ( strlen(argv[4]) > 25 ){
      fprintf(stderr, " Please do not try to buffer overflow\n");
      return 1;
   }

   int numhost = 0;

   if (argc > 5){
      hostremain = argc - 5;
      for (i = 0; i < hostremain; i++){
            if ( strlen(argv[(5 + i)]) > 25 ){
               fprintf(stderr, " Please do not try to buffer overflow\n");
            return 1;
         }

      }
         
   }
    
   numhost = hostremain + 1;
   
   lengthcheck = strlen(argv[1]);
   lengthcheck2 = strlen(argv[2]);

   for ( i = 0; i < lengthcheck; i++){
      if ( isalpha(argv[1][i]) ){
         fprintf(stderr, " Please only enter digits \n");
         return 1;         
      } else if ( isdigit(argv[1][i])  ) {
         
         
      } else {
         fprintf(stderr," Please only enter digits \n");
         return 1;
      }         
   }

   for ( i = 0; i < lengthcheck2; i++){
      if ( isalpha(argv[2][i]) ){
         fprintf(stderr, " Please only enter digits \n");
         return 1;         
      } else if ( isdigit(argv[2][i])  ) {
         
         
      } else {
         fprintf(stderr," Please only enter digits \n");
         return 1;
      }         
   }

   char *hostnames[numhost];


   /* Get host names */

      for (i = 0; i < numhost; i++){
         hostnames[i] = argv[(4 + i)];

         //printf("hostname :%s \n", hostnames[i]);
      }
    
   i2 = 0;

   fd = (int *) malloc(sizeof(int) * numhost * 4);

   /* fix here change the stuff around */
   portnumber = (u_port_t)atoi(argv[3]);
   for (i = 0; i < numhost*4; i++){
      if ( (i % 4 == 0) && (i > 0 ) ) {
	i2+= 1;

      } 
         if ( (fd[i] = u_connect(portnumber, argv[(4+i2)])) == -1 ) {
            perror("Failed to establish connection");
            return 1;
         }
      
      
   }

   int numhostthreads = (numhost) * 4;
   

   primeparameter = atoll(argv[1]);
   numfind = atoi(argv[2]);
   

   long long primegreater[numfind];
   primesfound = primegreater;
   
   pthread_t thread[numhostthreads];

   int threadfd[numhostthreads];


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

   //i2 = 0;
   /* call all threads */
   for (i = 0; i < numhostthreads; i++){
      threadfd[i] = i;
      if (error = pthread_create(&thread[i], &attr, find_prime, &threadfd[i])){
          fprintf(stderr, "Failed to create thread: %s\n", strerror(error));
      }

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


