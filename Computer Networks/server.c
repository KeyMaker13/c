// Michael Price
// Homeowork 6
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define PORT 20009
int main()
{
#ifdef WIN
      SOCKET sock;   /* SOCKET is a typedef for a structure */
#else
      int sock;
#endif
      int size;
      int nbytes, flags;
#ifdef WIN
      int addrlen;
#else
      socklen_t addrlen;
#endif
      int i;
      /* char loopback[20]="127.0.0.1"; */
      int nCode;
      char buffer[100];
      struct sockaddr_in server;  
      struct sockaddr_in client; 
      /* create a socket called sock. It is a datagram socket */
      sock = socket(AF_INET,SOCK_DGRAM,0);
       if(sock < 0){
       printf("socket error = %d\n", sock);
       return -1;
       }
      server.sin_family = AF_INET;   /* initialize the server address family */
      server.sin_addr.s_addr = htonl(INADDR_ANY); /* notice this struct within a struct */
      /* printf("%x\n",server.sin_addr.s_addr); */
      server.sin_port = htons(PORT);
      /* associate the socket with the address structure - this is called binding */
      i = bind(sock, (struct sockaddr *) &server, sizeof(server));
      if( i < 0) {
          printf("bind result: %d\n", i);
          return -1;
          } else
          printf("Simple UDP server is ready!\n\n");
      nbytes = 99; /* receive packets up to 99 bytes long */
       flags = 0;  /* must be zero or this will not work! */
      while(1){
         addrlen = sizeof(client);
         size = recvfrom(sock, buffer, nbytes, flags, (struct sockaddr *)&client,&addrlen);
         if((size > 0) && (size < 99)){
         buffer[size] = '\0';      /* add the null byte so buffer now holds a string */
         i = puts((char *) buffer);    /* write this string to the display */
         }
         size = sendto(sock, (char *) buffer, nbytes, flags,(struct sockaddr *)&client,sizeof(client));
      }
      return 0;
}

