#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]){

   int lengthcheck;
   int i = 0;
   int prime;
   long long primeparameter;

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


   fprintf(stderr, "This is part 1\n");
   fprintf(stderr, "Ivan Capistran\n");	   
   fprintf(stderr, "Parameter: %s\n" ,argv[1]);
   primeparameter = atoll(argv[1]);	

   prime = isPrimeLongLong(primeparameter);
   if (prime){
      printf("Is prime\n");
      fprintf(stderr, "The answer is prime\n");
   } else {
      printf("Is not prime\n");
      fprintf(stderr, "The answer is not prime\n");
   }
   
   return 0;
}
