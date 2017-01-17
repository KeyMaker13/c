
	/* The client's second step in making a network connection:
	** connect (call) on the socket (pgs 241-242) */

int			i,sock;
struct sockaddr_in	addr_send;
char 			*server_ip="130.127.24.92";
unsigned short		server_port=60000;

	/* ... socket has been created ... */

	/* create socket address structure to connect to */
memset(&addr_send, 0, sizeof (addr_send)); /* clr structure */
addr_send.sin_family = AF_INET; /* address family */
addr_send.sin_addr.s_addr = inet_addr(server_ip);
addr_send.sin_port = htons(server_port);

	/* connect to the server */
i=connect(sock, (struct sockaddr *) &addr_send,sizeof (addr_send));
if (i < 0)
  printf("connect() failed\n");

