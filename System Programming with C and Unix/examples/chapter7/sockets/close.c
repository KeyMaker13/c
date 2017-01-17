
	/* Closing a socket connection (pg 243) */

int	i,sock_recv;

	/* ... socket communication is finished ... */
i=close(sock_recv);
if (i < 0)
  printf("close() failed\n");

