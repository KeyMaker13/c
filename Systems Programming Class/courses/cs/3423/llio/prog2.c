#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSZ 1024

int main (int argc, char *argv[]) {
	int n, fd;
	char buf[1024];
	if (argc < 2 ){
		fprintf(stderr,"Usage: prog1 <file> \n");
		exit(-1);
	}


	// well i can try this, will just loop through each arg
	// using pointer arithmetic
	*argv++;
	while(*argv) {
		
		if (  (fd = open(*argv,O_RDONLY)) < 0  ) {
			perror(*argv);
			exit(-1);
		}

		while ( (n = read(fd,buf,BUFSZ)) > 0    ) {	
			write(STDOUT_FILENO,buf,n);
		}

		if ( n < 0 ){
			perror("I\\O error\n");
			exit(-1);	
		}
		close(fd);
		*argv++;
	}	


	exit(0);
}
