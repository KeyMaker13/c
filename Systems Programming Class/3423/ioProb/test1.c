#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFSZ 1024

int main(int argc, char *argv[]){

	int n, fdin, fdout;
	char buf[BUFSZ];

	fdin = open(argv[1], O_RDONLY);
	if (fdin < 0){
		perror("File Does Not Exist");
		exit(-1);
	}

	fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fdout < 0){
		perror("File could not be created");
		exit(-1);
	}

	while(n = read(fdin, buf, BUFSZ)){
	//	write(fdout, buf, n);

		fprintf(stdout, "%.*s", n, buf);
	}

	close(fdin);
	close(fdout);
	
	exit(0);
}

