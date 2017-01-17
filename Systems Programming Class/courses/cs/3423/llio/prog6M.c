#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSZ 1024

int main (int argc, char * argv[]) {
  int fd, n;

  struct product {
    int prod;
    int quan;
  }p;

  char buf[1024];

  if ( argc != 2 ) {
    fprintf(stderr,"Usage: gen7 <file.in>\n");
    exit(-1);
  }

  if((fd = open(argv[1], O_RDONLY)) < 0 ) {
    perror(argv[1]);
    exit(-1);
  }

  while ( (n = read(fd,&p,sizeof(p))) == sizeof(p) ) {
    printf("Product\t%d\tQuantity\t%d\n",p.prod,p.quan);
    if ( read(fd,buf,p.quan*sizeof(int)) != p.quan*sizeof(int) ) {
      fprintf(stderr,"Partial Write or Write error\n");
      exit(-1);
    }
  }

  if ( n < 0 ) {
    perror("Write Error");
    exit(-1);
  }

  if ( n > 0 ) {
    fprintf(stderr,"Partial Read Error (n = %d)\n",n);
    exit(-1);
  }

  close(fd);
  exit(0);
}

