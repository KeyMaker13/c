#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct vector {
	float x;
	float y;
	float z;
}; 

struct particle {
	float mass;
	struct vector pos;
	struct vector vel;
	
};

int main (int argc, char *argv[]) {

	struct particle p;

	int fd,n,count = 1;

	if (argc < 2) {
		exit(0);
	}		
	*argv++;
	
	fd = open(*argv,O_RDONLY);
	if (fd < 0) {
		perror(*argv);
		exit(-1);
	}
		
	while ( ( n = read(fd,&p,sizeof(struct particle)) )  == sizeof(struct particle) ){
		printf("Particle \t%d\n",count);	
		printf("\tmass \t%lf\n",p.mass);	
		printf("\tpos \t(%lf,%lf,%lf)\n",p.pos.x, p.pos.y, p.pos.z);
		printf("\tvel \t(%lf,%lf,%lf)\n",p.vel.x, p.vel.y, p.vel.z);	
		
		count++;	
	}
	printf("\n");
	if (n < 0)
	{
		perror("read error\n"); exit(-1);
	}

	close(fd);	

	exit(0);
}
