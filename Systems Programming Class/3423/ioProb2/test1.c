//Creating 2 processes that send messages to each other

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (void){
	pid_t mpid, opid;
	int fd0[2], fd1[2], fdin, fdout;

	
	if(pipe(fd0) || pipe(fd1)){
		perror("pipe error");
	}

	switch(fork()){
		case -1:
			perror("Fork error");

		case 0:
			close(fd0[1]);
			close(fd1[0]);
			fdin = fd0[0];
			fdout = fd1[1];
			break;

		default:
			close(fd0[0]);
			close(fd1[1]);
			fdin = fd1[0];
			fdout = fd0[1];
	}

	mpid = getpid();


	if((write(fdout, &mpid, sizeof(pid_t))) != sizeof(pid_t)) {
		perror("Write Error\n");
	}
	
	if((read(fdin, &opid, sizeof(pid_t))) != sizeof(pid_t)){
		perror("Read Error\n");
	}

	printf("My relative has pid %d\n", opid);

	exit(0);
}
