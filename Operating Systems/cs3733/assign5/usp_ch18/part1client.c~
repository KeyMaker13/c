#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "primelib.h"
#include "restart.h"
#include "uici.h"
 
int main(int argc, char *argv[]) {

   char buff[1024];
   int bytescopied;
   int bytesread;
   int communfd;
   int flag = 0;      

   int i = 0;
   int lengthcheck = 0;

   u_port_t portnumber;
 
   int maxfd;
   int num;
   fd_set readset;
   int totalbytes = 0;


   if (argc != 4) {
      fprintf(stderr, "Usage: %s prime host port\n", argv[0]);
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

   lengthcheck = strlen(argv[1]);
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

   /* Connection made */
   portnumber = (u_port_t)atoi(argv[3]);
   if ((communfd = u_connect(portnumber, argv[2])) == -1) {
      perror("Failed to establish connection");
      return 1;  
   }


   if ((communfd < 0) || (communfd >= FD_SETSIZE))
      return 0;

   maxfd = communfd;                     /* find the biggest fd for select */

   for ( ; ; ) { 

      FD_ZERO(&readset);
      FD_SET(communfd, &readset);

      if (!flag){
         if ( (bytesread =  r_write(communfd, argv[1] , lengthcheck )) != lengthcheck ){
            return 1;
         }
         flag = 1;
      }
      
      if (((num = select(maxfd+1, &readset, NULL, NULL, NULL)) == -1) &&
         (errno == EINTR)) 
         continue;
      if (num == -1) 
         return totalbytes;

      if (FD_ISSET(communfd, &readset)) {

         bytesread = r_read(communfd,buff, 1024);
         if (bytesread <= 0){
            perror("Failure getting message from server"); return 1;
         }

         if (buff[0] == '0' ){
            printf("Number is not Prime\n");
         } else if (buff[0] == '1'){
            printf("Number is Prime\n");
         }
 
         break;

      }
   }

   close(communfd);   

   return 0;
}
