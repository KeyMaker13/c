#include <stdio.h>
#include <time.h>

void function_to_time(void);

int main(void) {
   time_t tend, tstart;  

   tstart = time(NULL);
   function_to_time();
   tend = time(NULL);

   

   printf("The time before was %s\n",
           ctime(&tstart));
   printf("The time after was %s",ctime(&tend));
   return 0;
}
