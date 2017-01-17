#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main ( int argc, char *argv[] ){
	printf("TEST\n");	
	char buf[1024];

	int rsz = atoi(argv[3]);

	int fin,fout,n,i;								
	printf("TEST2\n");	
	if ( (fin = open(argv[1],O_RDONLY)) < 0 ) {
		perror("OPEN FAILED");
		exit(-1);
	}
	printf("TEST3\n");	
	if ( (fout = open(argv[2],O_WRONLY | O_CREAT, 0644)) < 0 ) {
		perror("2");
		exit(-1);
	}
		printf("TEST");	
	// this will loop through the rest of 	
	for (i = 4; i < argc; i++){
		lseek (fin,(atoi(argv[i])*rsz),SEEK_SET);
		read(fin,buf,rsz-1);
		write(fout,buf,rsz-1);		
		//printf("buf = %s\n",buf);

	}	
	close(fin);
	close(fout);	
	return 0;
}
