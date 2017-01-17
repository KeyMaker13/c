
	/* Once the connection is established, both the server and client
	** can use the send() and recv() system calls to transmit data back
	** and forth (pgs 242-243) */

int	sock,bytes_sent;
char	text[80];

	/* ... socket has been created and connected ... */

	/* send some data */
printf("Send? ");
scanf("%s",text);
bytes_sent=send(sock,text,strlen(text),0);



int	sock_recv,bytes_received;
char	text[80];

	/* ... socket created, bound and accepted ... */

	/* receive some data */
bytes_received=recv(sock_recv,text,80,0);
text[bytes_received]=0;
printf("Received: %s\n",text);

