#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

#define PROCNUM 9
// msgsize 10 so it can work for up to 103 processes
#define MSGSIZE 10

int main(void) {

	//double charbuffersize;
	//charbuffersize = floor(log10((double)PROCNUM)) + SIZEOFPROCESS +1;

	// to check for whether your a parent
	int parent = 0;

	// pindex is for the pipe index	
	int pindex = 0;
	// index is for the index of the process
	int index = 0;
	
	// pi for pipe iterator
	int pi = 0;

	// these are the arrays of integers that will be used for piping
	int mypipefd[PROCNUM][2];

	// rng n num i j for rand 
	int rng,n,num,i,j;

	// pointer for writing index value
	//int *indexv;
	// need to pass char buf instead
	char buf[MSGSIZE];
	
	// you must create each pipe for each index
	for (pi = 0; pi < PROCNUM; pi++){
		if ( pipe(mypipefd[pi]) ){
			printf("pipe error\n");
			exit(-1);
		}
	}
	
	// create 9 processes
	for (index = 0; index < (PROCNUM - 1); index++) {
				
		if ( (parent = fork()) == -1 ) {
			perror("Fork error");			
			exit(-1);
		}

		if (parent) {
			break;
		}

	}

	// make sure each process only reads from its pipe
	// close all reads from all the other pipes
	for (pindex = 0; pindex < PROCNUM; pindex++) {	
		if (index == pindex) {
			close(mypipefd[pindex][1]);
		}
			
		else {
			close(mypipefd[pindex][0]);
		}
	}

	// each process will write a message 13 times randomly to every other process
	rng = RAND_MAX/PROCNUM;
	rng *= PROCNUM;
	srand(4120111*index);
	for ( n = 0; n < 13; n++) {
		do {
			num = rand();
			j = num%PROCNUM;
		}
		while ( num >= rng || index == j);
		//indexv = &index;
		// need to write "Process%d"
		//buf = "Process";
		//char p = (char)(((int)'0')+index);
		//buf = strcat(buf,p);
		snprintf(buf,MSGSIZE,"process%d",index);		
		//if ( (write(mypipefd[j][1],indexv,sizeof(int))) != sizeof(int) ){
		if ( write(mypipefd[j][1],buf,MSGSIZE) != MSGSIZE ){		
			perror("write error");
			exit(-1);
		}
	}

	int c;
	// already wrote to the pipes so need to close them
	for (c = 0; c < PROCNUM; c++) {
			close(mypipefd[c][1]);
	}

	// reading from current process pipe and writing to stdout
	int ri;
	char inbuf[MSGSIZE];
	//char buf[10];
	//char bufto[1024];
	// have to read in "Process%d"
	//while ( (read(mypipefd[index][0],&ri,sizeof(int))) == sizeof(int) ) {
	while (	(read(mypipefd[index][0],inbuf,MSGSIZE)) == MSGSIZE ) {
		//bufto = ("process%d has recieved a message from process%d",&index,buf);
		//if ( write(STDOUT_FILENO,bufto,sizeof(bufto)) < 0 ){
		//	perror("write error");
		//	exit(-1);
		//}
		
		//printf("process%d has recieved a message from process%d \n",index,ri);
		printf("process%d has recieved a message from %s \n",index,inbuf);	
	}
	
	// just close your own read pipe since all others were closed
	// since this could either be a parent or a child..it will just close its own read pipe
	close(mypipefd[index][0]);
		
	// must exit the program so that each child returns to its parent
	exit(0);		
}



		
