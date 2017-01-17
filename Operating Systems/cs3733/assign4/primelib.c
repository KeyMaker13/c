#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isPrimeInt(int num){

   int i = 2;
   int root = (int) sqrt((double) num);

   for (i = 2; i <= root; i++){
      if ( num % i == 0   ){

         return false;
      }
   }
   return true;
}

bool isPrimeLongLong (long long num) {

   long long i = 2;
   long long root =  sqrtl(num);

   for (i = 2; i <= root; i++){
      
      if ( num % i == 0   ){

         return false;
      }
   }
   return true;
}

