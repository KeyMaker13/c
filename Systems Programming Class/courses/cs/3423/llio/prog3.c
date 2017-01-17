#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSZ 1024

int main (int argc, char *argv[]) {

	int n, fd;
	char buf[BUFSZ];
	char *nl;

	
	


	if (argc < 2) {
		fprintf(stderr,"Usage prog <file>\n");
	}

	*argv++;
	while (*argv){
		
		if (  (fd = open(*argv,O_RDONLY)) < 0 ) {
			perror(*argv);
			exit(-1);
		}

		while ( ( n = read (fd,buf,BUFSZ) ) > 0 ) {

			*nl = buf;	

				write(STDOUT_FILENO,buf,n);			
		}
	
		if ( n < 0 ) {
			perror("I\\O error");
		}
	
		*argv++;
	}



	exit(0);
}
