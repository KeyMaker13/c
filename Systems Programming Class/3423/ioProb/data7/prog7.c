#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	struct{
		int type;
		int number;
	}p;

	int fd;
	int no;
	int i;
	int n;

	unsigned int serial;
	
	fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		perror(argv[1]);
		exit(-1);
	}

	while(n = read(fd, &p, sizeof(p))){

		printf("Product\t%d\tQuantity\t%d\n", p.type, no = p.number);
		
		for(i = 1; i <= no; i++){
			read(fd, &serial, sizeof(serial));
			printf("\t%10i\n", (int)serial);
		}

		printf("\n");
	}

	close(fd);

	exit(0);
}
