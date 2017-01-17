// To compile: gcc c.c -o c
// To run: ./c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef WIN
#include <winsock.h>
#include <windows.h>
#endif
#ifndef WIN
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#endif
/* Here are some details of the sockaddr_in structure and the sockaddr structure
   These declarations are copied from winsock.h

   struct in_addr {       this struct holds a 32 bit IP address
        union {
                struct { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
                struct { u_short s_w1,s_w2; } S_un_w;
                u_long S_addr;
        } S_un;
#define s_addr  S_un.S_addr

    struct sockaddr_in {   notice this structure is 16 bytes long
            short       sin_family;
            u_short     sin_port;
            struct      in_addr sin_addr;
            char        sin_zero[8];
     };
        struct sockaddr {       this generic address structure is 16 bytes long, too!
            u_short sa_family;
            char        sa_data[14];
     };

*/
/* we have to send on the same port the server is listening on */
#define PORT 20009
/* simple upd client */
int main()
{

      int packetsSent = 0;        
      int packetsReceived = 0;   
#ifdef WIN
      SOCKET sock;
#else
      int sock;
#endif
      int size;
      int nbytes, flags;
      int i;
      char * cp;
#ifdef WIN
      WSADATA wsaData;
      int nCode;
#endif
      char buffer[100];
      char str_addr[20];        /* holds the chars of an IP address */
      struct sockaddr_in target_pc, me;

/* magic call to initialize the network I/O code - only Microsoft requires this */
#ifdef WIN
      if((nCode = WSAStartup(MAKEWORD(1,1), &wsaData)) != 0){
      printf("Opps! WSA error %d\n",nCode);
      return -1;
      }
#endif
/* create a socket to send on */
      sock = socket(PF_INET,SOCK_DGRAM,0);
       if(sock < 0) {
       printf("socket error = %d\n", sock);
       return -1;
       }
      /* we fill in the address family and port, but we do not know the destination IP address yet */
      target_pc.sin_family = PF_INET;
      target_pc.sin_port = htons(PORT);
      /* fill in my address and port */
      me.sin_family = PF_INET;
      me.sin_port = htons(0);
      me.sin_addr.s_addr = htonl(INADDR_ANY);
      i = bind(sock, (struct sockaddr *) &me, sizeof(me));
      if( i < 0) {
          printf("bind result: %d\n", i);
          return -1;
          }


      nbytes = 99;

	struct timeval  tv, tv1, tv2, tv3;
	tv.tv_sec = 1; // for 1 second timer
      tv.tv_usec = 0;
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval)); // set timer

     while(1){
	    printf("Packets sent: %d\n", packetsSent);
	    printf("Packets received: %d\n", packetsReceived);
	    printf("Packet loss: %d\n\n", packetsSent-packetsReceived);
            printf("Enter the target IP address: ");
            cp = fgets(str_addr,19,stdin);
            /* remove the \n */
            str_addr[strlen(str_addr)-1] = '\0';
            /* the inet_addr function converts a string form of IP address to a 32 binary integer */
            target_pc.sin_addr.s_addr = inet_addr(&str_addr[0]);
            printf("Enter your message: ");
            cp = fgets(buffer,99,stdin);
            /* get the string length so we send exactly this many characters */
            nbytes = strlen(buffer);
            flags = 0;

  		gettimeofday(&tv1, NULL); //sent time
            size = sendto(sock, (char *) buffer, nbytes,flags,(struct sockaddr *)&target_pc,sizeof(target_pc));
 		packetsSent++; // increment packetsSent
            printf("msg size = %d size = %d\n", nbytes, size);

            int addrlen = sizeof(target_pc);
            size = recvfrom(sock, buffer, nbytes, flags, (struct sockaddr *)&target_pc,&addrlen); // wait 1 second to receive
            if((size > 0) && (size < 99)){
 			gettimeofday(&tv2, NULL); // received time
		    printf ("RTT = %f seconds\n", (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec)); // print RTT
			packetsReceived++;
               buffer[size] = '\0';      //add the null byte so buffer now holds a string 
               i = puts((char *) buffer);    // write this string to the display 
            }


      }
#ifdef WIN
      system("PAUSE");
#endif
      return 0;
}
