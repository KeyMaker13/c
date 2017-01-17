#include <stdlib.h>
#include <stdio.h>
#include "pslibrary.h"

void part0(char *s1, char *s2){
   // set up strings
   char *sc1 = "RRwwwwwRRRRRRRRR";
   char *sc2 = "rrRRRRwwwwwwwwrrRRRRRRR";
	
   // copy first
   while (*sc1) {
      *s1 = *sc1;
      *s1++;
      *sc1++;
   }  *s1= '\0';
	
   // copy second
   while (*sc2) {
      *s2 = *sc2;
      *s2++;
      *sc2++;
   }  *s2 = '\0';	
	
   return;

}

void fcfsa(char *s1,char *s2,int x1,int y1,int z1,int x2,int y2,int z2){
   /* here we go first come first serve */
   /* so x1 , y1, x2, y2, z1, z2 */

   int tempv;
   int tempv2;
   int x1t = x1;
   int x2t = x2;
   int y1t = y1;
   int y2t = y2;
   int z1t = z1;
   int z2t = z2;

   while (x1t > 0 ) {
	*s1 = 'R';
	*s1++;
	
	*s2 = 'r';
	*s2++;
	x1t--;
   }

   while (x2t > 0 ) {
      if ( y1t > 0 ) {
         *s1 = 'w';
         *s1++;
         y1t--;
      }
      else if ( (y1t == 0) && (z1t > 0) ) {
         *s1 = 'r';
         *s1++;
      }
      *s2 = 'R';
      *s2++;
      x2t--;
   }

   while( y1t > 0 ){
      if ( y2t > 0   ) {
         *s2 = 'w';
         *s2++;
         y2t--;
      } else if ( ( y2t == 0 ) && ( z2t > 0 )   ) {
         *s2 = 'R';
         *s2++;
         z2t--;
         
      }
      *s1 = 'w';
      *s1++;
      y1t--;
   }
   
   while( y2t > 0 ){
      if ( y1t > 0  ) {
         *s1 = 'w';
         *s1++;
         y1t--;
      } else if  ( ( y1t == 0  ) && ( z1t > 0  )  ) {
         *s1 = 'R';
         *s1++;
         z1t--;
      }
      *s2 = 'w';
      *s2++;
      y2t--;
      
   }
 
   while (z1t > 0) {
      if ( y2t > 0 ) {
         *s2 = 'w';
         *s2++;
         y2t--;
      } else if ( ( y2t == 0)  &&  (z2t > 0 )   ) {
         *s2 = 'r';
         *s2++;
         //z2t--;
         
      }
      *s1 = 'R';
      *s1++;
      z1t--;
   }


   while (z2t > 0 ) {
      if ( y1t > 0 ) {
         *s1 = 'w';
         *s1++;
         y1t--;
      } else if (  (y1t == 0) && ( z1t > 0  )  ) {
         *s1 = 'r';
         *s1++;
         //z1t--;
      }

      *s2 = 'R';
      *s2++;
      z2t--;
   }

   *s1 = '\0';
   *s2 = '\0';
}


void display(char *heading, char *s1, char *s2){
   printf("\n");
   printf("%s",heading);
   printf("%s\n",s1);
   printf("%s\n",s2);
   
   //number of 'r' in first string
   int brs1 = 0;
   int brs2 = 0;
   int finallen = 0;
   float finalnum;
   float fn1 = 0.0;
   float fn2 = 0.0;
   float n1 = 0.0;
   float n2 = 0.0;	
   float num = (22.0/23.0);
   int rs1 = 0;
   int rs2 = 0;
   char *s1c = s1;
   char *s2c = s2;
   int s1l = 0; 
   int s2l = 0;

   while (*s1c != '\0'){
      if ( *s1c == 'r') {
         rs1++;
      }
      if ( *s1c == 'R') {
         brs1++;
      }
      *s1c++;
      s1l++;
   }

   //number of 'r' in second string
   while ( *s2c != '\0') {
      if ( *s2c == 'r') {
         rs2++;
      }
      if ( *s2c == 'R') {
         brs2++;
      }
      *s2c++;
      s2l++;
   }

   n1 += rs1;
   n2 += rs2;

   if (s1l > s2l){
      finallen = s1l;
   }
   else if ( s2l > s1l) {
      finallen = s2l;
   } else {
      finallen = s1l;
   }

   fn1 += brs1;
   fn2 += brs2;

   finalnum = ( fn1 + fn2  )/finallen;
   printf("%d %d %.1lf %.5f \n", rs1, rs2, (n1 + n2)/2.0, finalnum);
}


