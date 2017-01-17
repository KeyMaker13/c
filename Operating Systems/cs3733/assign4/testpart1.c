#include <stdio.h>

int isPrimeLongLong(long long n);

#define START 12345678901234LL
#define NUM 5000

int main() {
   long long n;
   
   for (n=START; n<START+NUM; n++)
      if (isPrimeLongLong(n))
         printf("%lld\n",n);
   return 0;
}
