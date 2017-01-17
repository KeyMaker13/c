#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// for testing purposes
//#include <stdio.h>

#define BUFSZ 1024

int main (int argc, char *argv[]) {
	
	int n, fdin1, fdin2, fdout;
	char buf[BUFSZ];
	

	int f1,f2,f3;
	
	if (argc == 3){
		if (strlen(argv[1]) == 1 && argv[1][0] == '-') {
			f1 = 1;
			
		}
		else {
			f1 = 0;
		}
		if (strlen(argv[2]) == 1 && argv[2][0] == '-'){
			
			f2 = 1;
		}
		else {
			f2 = 0;
		}

		if ((f1 + f2) == 2){
			//printf("incorrect format\n");
			exit(-1);
		}
		else {

			if (!f1) {
				fdin1 = open(argv[1], O_RDONLY);
				if (fdin1 < 0){
					perror(argv[1]);
					exit(-1);
				}
				while ( ( n = read(fdin1, buf , sizeof(buf) ) ) > 0 ) {
					write(STDOUT_FILENO,buf,n);
				}
				close(fdin1);
			}
		
			if (!f2) {
				fdin2 = open(argv[2], O_RDONLY);
				if (fdin2 < 0 ){
					perror(argv[2]);
					exit(-1);
				}
				while ( ( n = read(fdin2, buf, sizeof(buf) ) ) > 0 ) {
					write(STDOUT_FILENO,buf,n);
				}
				close(fdin2);
			}
		}
	
	}
	else if (argc == 4){
		if (strlen(argv[1]) == 1 && argv[1][0] == '-') {
                        f1 = 1;
                        
                }
                else {
                        f1 = 0;
                }

		if (strlen(argv[2]) == 1 && argv[2][0] == '-'){
                        
                        f2 = 1;
                }
                else {
                        f2 = 0;
                }

		if (strlen(argv[3]) == 1 && argv[3][0] == '-'){
			f3 = 1;
		}
		else {
			f3 = 0;
		}

                if ((f1 + f2) == 2){
                        
                        exit(-1);
                }
                else {

			

                        if (!f1) {
                                fdin1 = open(argv[1], O_RDONLY);
                                if (fdin1 < 0){
                                        perror(argv[1]);
                                        exit(-1);
                                }
                                
                        }

                        if (!f2) {
                                fdin2 = open(argv[2], O_RDONLY);
                                if (fdin2 < 0 ){
                                        perror(argv[2]);
                                        exit(-1);
                                }
                        }

			if (!f3){
				fdout = open(argv[3], O_WRONLY | O_CREAT, 0600);
				if (fdout < 0 ){
					perror(argv[3]);
					exit(-1);
				}
				if (!f1){
					while ( ( n = read(fdin1, buf , sizeof(buf) ) ) > 0 ) {
                                	        write(fdout,buf,n);
                               		}
					close(fdin1);
  				}
				if (!f2) {
					  while ( ( n = read(fdin2, buf , sizeof(buf) ) ) > 0 ) {
                                        	write(fdout,buf,n);
                                	  }
					  close(fdin2);
				}
				close(fdout);

			} else {
				if (!f1){
                        		while ( ( n = read(fdin1, buf , sizeof(buf) ) ) > 0 ) {
                                                write(STDOUT_FILENO,buf,n);
                                        }
                                } 
                                if (!f2) {
                                          while ( ( n = read(fdin2, buf , sizeof(buf) ) ) > 0 ) {
                                                write(STDOUT_FILENO,buf,n);
                                          }
                                }
			}

                }

            


	} 
}

