#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
/* we have to send on the same port the server is listening on */
#define PORT 20009
/* simple upd client */
int main()
{
#ifdef WIN
      SOCKET sock, sock2;
#else
      int sock, sock2;
#endif
      int size;
      int nbytes, flags;
      int i;
      char * cp;
      char buffer[100];
		char rbuffer[100];
      char str_addr[20];        /* holds the chars of an IP address */
      struct sockaddr_in client, server;

/* create a socket to send on */
      sock = socket(PF_INET,SOCK_DGRAM,0);
       if(sock < 0) {
       printf("socket error = %d\n", sock);
       return -1;
       }

      server.sin_family = PF_INET;
      server.sin_port = htons(PORT);
      /* fill in my address and port */
      client.sin_family = PF_INET;
      client.sin_port = htons(0);

      client.sin_addr.s_addr = htonl(INADDR_ANY);
      i = bind(sock, (struct sockaddr *) &client, sizeof(client));
      if( i < 0) {
          printf("bind result: %d\n", i);
          return -1;
          }

      nbytes = 99;

      while(1){
            printf("Enter the target IP address: ");
            cp = fgets(str_addr,19,stdin);
            /* remove the \n */
            str_addr[strlen(str_addr)-1] = '\0';
            client.sin_addr.s_addr = inet_addr(&str_addr[0]);
            printf("Enter your message: ");
            cp = fgets(buffer,99,stdin);
            /* get the string length so we send exactly this many characters */
            nbytes = strlen(buffer);
            flags = 0;
				size = sendto(sock, (char *) buffer, nbytes,flags,(struct sockaddr *)&client,sizeof(client));
            printf("msg size = %d size = %d\n", nbytes, size);
      }
				/* This will allow the client to receive messages as well */
		
      return 0;
}

