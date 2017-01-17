#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "prog5.h"

int main(int argc, char *argv[]){
	struct particle p;

	int fd;
	int n;
	int i = 0;
	
	if((fd = open(argv[1], O_RDONLY))<0){
		perror(argv[1]);
		exit(-1);
	}

	while((n = read(fd, &p, sizeof(p)))== sizeof(p)){

		printf("Particle\t%d\n", ++i);
		printf("\tmass\t%f\n", p.mass);
		printf("\tpos\t(%f,%f,%f)\n", p.pos.x, p.pos.y, p.pos.z);
		printf("\tvel\t(%f,%f,%f)\n", p.vel.x, p.vel.y, p.vel.z);

	}

	if ( n == -1 ) {
		perror("Write error\n");
		exit(-1);
	} else if ( n > 0 ) {
		printf("Error: Incomplete Record\n");
	}


	close(fd);
	exit(0);
}
