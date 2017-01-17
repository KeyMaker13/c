
	/* First step in making a network connection:
	** create a socket (pg 240) */

#include <sys/types.h>	/* system type definitions */
#include <sys/socket.h>	/* network system functions */
#include <netinet/in.h>	/* protocol & struct definitions */

int sock;

sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
if (sock < 0)
  printf("socket() failed\n");

