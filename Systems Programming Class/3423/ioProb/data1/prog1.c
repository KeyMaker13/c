#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFSZ 1024

int main(int argc, char *argv[]){
	int n, fdin;
	char buf[BUFSZ];

	fdin = open(argv[1], O_RDONLY);
	if(fdin < 0){
		perror("Error!!\n");
		exit(-1);
	}

	while ((n = read(fdin, buf, BUFSZ)) > 0){
		//fprintf(stdout, "%.*s", n, buf);

		write(STDOUT_FILENO, buf, n);
	}

	close(fdin);
	
	exit(0);
}

/* Maynard's Code 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSZ 1024

int main (int argc, char * argv[])
  {
     int n;
     int fd;
     char buf[BUFSZ];
  
     if ( argc != 2 ) {
       fprintf(stderr,"Usage: prog1 <file>\n");
       exit(-1);
     }
  
    if((fd = open(argv[1], O_RDONLY)) < 0 ) {
      perror(argv[1]);
      exit(-1);
    }
  
    while ( (n = read(fd, buf, BUFSZ)) > 0 ) {
      write(STDOUT_FILENO,buf,n);
    }
  
    if ( n < 0 ) {
      perror("I/O error");
      exit(-1);
    }
  
    exit(0);
  }


*/
