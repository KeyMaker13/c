#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSZ 1024

int main (void) {

int n, fd;

char buf[BUFSZ];
fd = open("filea", O_RDONLY);	

	while (  (n = read(fd,buf,sizeof(buf))) > 0 ) {
		write(STDOUT_FILENO,buf,n);
	}

	close(fd);		
	return 0;
}
