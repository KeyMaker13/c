
	/* The server's third step in making a network connection:
	** listen for calls on the socket (pg 241) */

int i,sock;

	/* ... socket has been created and bound ... */

	/* listen */
i=listen(sock,5);
if (i < 0)
  printf("listen() failed\n");

