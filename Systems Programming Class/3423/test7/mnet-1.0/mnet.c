#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	int t=0;
	int fd[7][2];
	int i;
	int parent;

	//Creating the necessary pipes
	for(i=0;i<7 ;i++){
		if(pipe(fd[i])){
			printf("error pipe\n");
			exit(-1);
		}
	}

	//Creating the necessary processes
	for(i = 1; i < 7; i++)
	{
		switch(parent = fork()){
			case -1:
				perror("fork error"); exit (-1);
			case 0:
				t = i ;
				break;
		}
		if(parent) 
			break;
	}

	//Closing the appropriate pipes
	for(i = 0 ; i < 7; i++){
		if(i != t){
			close(fd[i][0]);
		}
		else{
			close (fd[i][1]);
		}
	}

	//Generating the random numbers
	int num;
	int j;
	int rng = RAND_MAX/7;
	rng*=7;
	srand(4120111*t);

	for(i = 0; i < 11; i++){
		do{
			num = rand();
			j = num%7;
		}
		while(num >= rng || t == j);

		//writing to the appropriate pipes
		char str[9];
		snprintf(str,9,"process%d", t);
		if(write(fd[j][1],str,sizeof(str)) <0 ){
			printf("error on write\n");
		}
	}

	//Closing the write pipes of the other processes excluding the current process
	for(i = 0; i < 7; i++)
		if(t != i){
			close(fd[i][1]);
	}

	//Reading from the current process' pipe and writing to stdout
	char buf[9];
	while(read(fd[t][0],buf,sizeof(buf))>0){
		printf("process%d has received a message from %s\n",t,buf);
	}

	//Closing the current process' read pipe
	close(fd[t][0]);

	return 0;
}
