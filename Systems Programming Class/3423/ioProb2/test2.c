//Creating a ring of  processes that send messages to each other

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int num, i;
	int fdin, fdout, parent;
	int fd[2];

	num = atoi(argv[1]);

//	printf("\nnum = %d\n", num);
//	printf("argv[1] = %s\n", argv[1]);

	if (num <= 0){
		return(-1);
	}

	pipe(fd);

	fdin = fd[0];
	fdout = fd[1];

	for (i = 1; i<num; i++){
		pipe(fd);

		switch(parent = fork()){
			case -1:
				perror("fork error\n");
				exit(-1);

			case 0:
				close(fdin);
				fdin = fd[0];
				close(fd[1]);
		
			default:
				close(fdout);
				fdout = fd[1];
				close(fd[0]);
				printf("Process\n");
		}

		if(parent){
			break;
		}
	}
}
