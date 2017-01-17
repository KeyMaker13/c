#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc, char *argv[]){

   char *string; 
   int checkboard[8][8];
   int n;
   int *list;

   if (argc != 2) {	
      printf("Usage: ./assign4 n\n");
      return 0;
   }
   printf("part0\n");

   *argv++;
   n = atoi(*argv);
   
   list = malloc(sizeof(int)*n);
   string = malloc( (sizeof(char) * (n)) + (n*4) );
   //int sf = 64;
   //while(sf != 0){
   
   //   **checkboard = 3;
   //   *checkboard++;  
   //sf--; 
   //}

   //printf("checkboard : %d\n",**checkboard);
/*
   while(sf < 64){
      
      **checkboard
      
   }
*/
   int t = generate_n_queens_serial(10,1);
   printf("t is :%d\n",t);

   int t2 = next_permutation(list,n);
   get_array_string(list,n,string);
   printf("string is %s",string);

   //printf("%d  \n",list[0]);
   //printf("%d  \n",list[1]);
   //printf("%d  \n",list[2]);
   //printf("%d  \n",list[3]);
   //printf("%d  \n",list[4]);
   //printf("%d  \n",list[5]);
   return 0;
}
