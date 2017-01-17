#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include "primelib.h"
#include "restart.h"
#include "uici.h"

/*                                  
 *                       UICI Server
 *  Open a UICI port specified as a command-line argument
 *  and wait for a client request.  When a request arrives
 *  use the provided communication file descriptor to read
 *  from the UICI connection and echo to standard output
 *  until the connection is terminated.  Then resume
 *  waiting for another request.
 */

int main(int argc, char *argv[])
{
   u_port_t portnumber;
   int listenfd;
   int communfd;
   char client[MAX_CANON];
   int bytes_copied;
 

   int bytesread;
   int maxfd;
   int num;
   fd_set readset;  
   int totalbytes = 0;

   /* for prime */
   long long value = 0;
   int testbytes = 0;
   char buff[1024];



   if (argc != 2) {
      fprintf(stderr, "Usage: %s port\n", argv[0]);
      return 1;   
   }  
   portnumber = (u_port_t) atoi(argv[1]);
   if ((listenfd = u_open(portnumber)) < 0) {
      perror("Listen endpoint creation failed");
      return 1;
   }
   fprintf(stderr, "[%ld]: Waiting for the first connection on port %d\n",
                    (long)getpid(), (int)portnumber);
   for ( ; ;) {
      if ((communfd = u_accept(listenfd, client, MAX_CANON)) != -1) {
         fprintf(stderr, "A connection has been received from %s\n",client);

      if ((communfd < 0) || (communfd >= FD_SETSIZE))
         return 0;
         maxfd = communfd;                     /* find the biggest fd for select */

   for ( ; ; ) { 
      FD_ZERO(&readset);
      FD_SET(communfd, &readset);
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

         value = atoll(buff);       

         if (isPrimeLongLong(value)){
            bytesread = r_write(communfd, "1", 1);
         } else {
            bytesread = r_write(communfd, "0", 1);
         }
   
         if (bytesread <= 0){
            perror("Failure getting message from server"); return 1;
         }

         break;

      }
   }   


         close(communfd);
         
         break;


      }
      else
         perror("Accept failed");
   }
}
