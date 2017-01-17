// Michael Price
// Homework 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
/* we have to send on the same port the server is listening on */
#define PORT 20009
/* simple upd client */
void *sendMsg(void *);
void *recvMsg(void *);
int main(){
	struct timeval timer;
	pthread_t send_thread;
	pthread_t recv_thread;

	if(pthread_create(&send_thread, NULL, sendMsg, (void *)&timer)){
		perror("ERROR:Unable to create thread:Exiting\n");
		return(-1);
	}
	if(pthread_create(&recv_thread, NULL, recvMsg, (void *)&timer)){
		perror("ERROR:Unable to create thread:Exiting\n");
		return(-1);
	}

	pthread_join(send_thread,NULL);
	pthread_join(recv_thread,NULL);
	return(0);
}
void *sendMsg(void *ptr){
	struct timeval *timer;
	timer = (struct timeval *)ptr;
#ifdef WIN
      SOCKET sock;
#else
      int sock;
#endif
		
      int size;
      int nbytes, flags;
      int i, addrlen;
      char * cp;
      char buffer[100];
      char str_addr[20];        /* holds the chars of an IP address */
      struct sockaddr_in server, client;
/* create a socket to send on */
      sock = socket(PF_INET,SOCK_DGRAM,0);
       if(sock < 0) {
       printf("socket error = %d\n", sock);
       exit(-1);
       }
      /* we fill in the address family and port, but we do not know the destination IP address yet */
      server.sin_family = PF_INET;
      server.sin_port = htons(PORT);
      /* fill in my address and port */
      client.sin_family = PF_INET;
      client.sin_port = htons(0);
      client.sin_addr.s_addr = htonl(INADDR_ANY);
      i = bind(sock, (struct sockaddr *) &client, sizeof(client));
      if( i < 0) {
          printf("bind result: %d\n", i);
          exit(-1);
          }
      nbytes = 99;
      while(1){
            printf("Enter the target IP address: ");
            cp = fgets(str_addr,19,stdin);
            /* remove the \n */
            str_addr[strlen(str_addr)-1] = '\0';
            /* the inet_addr function converts a string form of IP address to a 32 binary integer */
            server.sin_addr.s_addr = inet_addr(&str_addr[0]);
            printf("Enter your message: ");
            cp = fgets(&buffer[9],99,stdin);
				time_t loc;
				int hour, min, sec;
				gettimeofday(timer, NULL);
				loc = timer->tv_sec;
				sec = loc % 60;
				loc = loc / 60;
				min = loc % 60;
				loc = loc / 60;
				hour = (loc - 5)%12;
				sprintf(buffer, "%02d:%02d:%02d",hour, min, sec);
				buffer[8] = ' ';
            /* get the string length so we send exactly this many characters */
            nbytes = strlen(buffer);
            flags = 0;
            size = sendto(sock, (char *) buffer, nbytes,flags,(struct sockaddr *)&server,sizeof(server));
				gettimeofday(timer, NULL);
				size = recvfrom(sock, buffer, nbytes, flags, (struct sockaddr *)&server,&addrlen);
			   printf("Echoed Message: %s\n", buffer);
            printf("Server IP Address: %s\n", inet_ntoa(server.sin_addr));
      }
}
void *recvMsg(void *ptr){

}
