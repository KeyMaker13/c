
	/* Multiple simultaneous clients; server will talk to several
	** clients at the same time (pgs 248-249) */

#include <stdio.h>
#include <sys/types.h>	/* system type defintions */
#include <sys/socket.h>	/* network system functions */
#include <netinet/in.h>	/* protocol & struct definitions */

#define BUF_SIZE	1024
#define LISTEN_PORT	60000

int main(int argc, char *argv[])

{
int			sock_recv;
struct sockaddr_in	my_addr;
int			i;
fd_set			readfds;
struct timeval		timeout={0,0};
int			incoming_len;
struct sockaddr_in	remote_addr;
int			recv_msg_size;
char			buf[BUF_SIZE];
int			select_ret;


        /* create socket for receiving */
sock_recv=socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
if (sock_recv < 0)
  {
  printf("socket() failed\n");
  exit(0);
  }
	/* make local address structure */
memset(&my_addr, 0, sizeof (my_addr));	/* zero out structure */
my_addr.sin_family = AF_INET;	/* address family */
my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* current machine IP */
my_addr.sin_port = htons((unsigned short)LISTEN_PORT);
	/* bind socket to the local address */
i=bind(sock_recv, (struct sockaddr *) &my_addr, sizeof (my_addr));
if (i < 0)
  {
  printf("bind() failed\n");
  exit(0);
  }

	/* listen ... */
while (1)
  {
  do 
    {
    FD_ZERO(&readfds);		/* zero out socket set */
    FD_SET(sock_recv,&readfds);	/* add socket to listen to */
    select_ret=select(sock_recv+1,&readfds,NULL,NULL,&timeout);
    if (select_ret > 0)		/* anything arrive on any socket? */
      {
      incoming_len=sizeof(remote_addr);	/* who sent to us? */
      recv_msg_size=recvfrom(sock_recv,buf,BUF_SIZE,0,
		(struct sockaddr *)&remote_addr,&incoming_len);
      if (recv_msg_size > 0)	/* what was sent? */
        {
        buf[recv_msg_size]='\0';
        printf("From %s received: %s\n",
		inet_ntoa(remote_addr.sin_addr),buf);
        }
      }
    }
  while (select_ret > 0);
  if (strcmp(buf,"shutdown") == 0)
    break;
  }

close(sock_recv);
}


