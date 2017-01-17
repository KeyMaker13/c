#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSZ 1024

int main(int argc, char *argv[]){
	int fd, nbytes;
	int i;
	char buf[BUFSZ];

	if(argc < 2){
		fprintf(stderr, "Usage: prog2 <file> or more\n");
		exit(-1);
	}

	for(i = 1; i<argc; i++){
		fd = open(argv[i], O_RDONLY);
		if(fd<0){
			perror(argv[i]);
			exit(-1);	
		}
		while(nbytes = read(fd, buf, BUFSZ)){
			write(STDOUT_FILENO, buf, nbytes);
		}
		
		close(fd);
	}


	exit(0);
}

/*

check maynard io 2 prog2
Correct Result - My solution follows: 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSZ 1024

int main (int argc, char * argv[])
  {
     int n,i;
     int fd;
     char buf[BUFSZ];
  
     if ( argc == 1 ) {
       fprintf(stderr,"Usage: prog2 <file list>\n");
       exit(-1);
     }
  
    for ( i=1; i<argc; i++ ) {
      if((fd = open(argv[i], O_RDONLY)) < 0 ) {
        perror(argv[i]);
        exit(-1);
      }
  
      while ( (n = read(fd, buf, BUFSZ)) > 0 ) {
        write(STDOUT_FILENO,buf,n);
      }
  
      if ( n < 0 ) {
        perror("I/O error");
        exit(-1);
      }

      close(fd);
    }
  
    exit(0);
  }
*/
