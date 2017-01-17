
	/* The server's second step in making a network connection:
	** bind the socket so it can listen (pgs 240-241) */

int			i,sock;
struct sockaddr_in	my_addr;
unsigned short		listen_port=60000;

	/* ... socket has been created ... */

	/* make local address structure */
memset(&my_addr, 0, sizeof (my_addr)); /* clr structure */
my_addr.sin_family = AF_INET; /* address family */
my_addr.sin_addr.s_addr = htonl(INADDR_ANY); /* my IP */
my_addr.sin_port = htons(listen_port);

	/* bind socket to the local address */
i=bind(sock, (struct sockaddr *) &my_addr, sizeof (my_addr));
if (i < 0)
  printf("bind() failed\n");

