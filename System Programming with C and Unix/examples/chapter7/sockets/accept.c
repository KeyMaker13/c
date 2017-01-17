
	/* The server's fourth step in making a network connection:
	** accept an incoming connection (call) on the socket (pg 242) */

int			i,sock,sock_recv,addr_size;
struct sockaddr_in	recv_addr;

	/* ... socket created, bound and listening ... */

	/* incoming xion -- get new socket to receive data on */
addr_size=sizeof(recv_addr);
sock_recv=accept(sock, (struct sockaddr *) &recv_addr,&addr_size);

