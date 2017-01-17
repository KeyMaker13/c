#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define BUFSZ 1024

int main(int argc, char *argv[])
{
	char buf[BUFSZ];
	int n;

	if(argc!=3)
	{
		if(argc!=4)
		{
			printf("Error: Incorrect Number of arguments\n");
			exit(-1);
		}
	}

	if(argc ==3)
	{
		if((strcmp (argv[1],"-")==0) && (strcmp(argv[2],"-")==0))
		{
			printf("Error: Incorrect Arguments\n"); 
			exit(-1);
		}

		if(strcmp (argv[1],"-")==0)
		{
			int FD1=STDIN_FILENO;

			while((n=read(FD1,buf,BUFSZ)))
			{
				write(STDOUT_FILENO,buf,n);
			}

			int FD2;

			if ((FD2 = open(argv[2], O_RDONLY))<0)
			{
				perror(argv[2]);
				close(FD1);
				exit(-1);
			}

			while((n=read(FD2,buf,BUFSZ))>0)
			{
				write(STDOUT_FILENO,buf,n);
			}

			close(FD1);
			close(FD2);
		}

		if(strcmp (argv[2],"-")==0)
		{
			int FD1;

			if ((FD1 = open(argv[1], O_RDONLY))<0)
			{
				perror(argv[1]);
				exit(-1);
			}

			int n1;
			char buf1[BUFSZ];
			int FD2=STDIN_FILENO;

			while((n=read(FD1,buf,BUFSZ))>0)
			{
				write(STDOUT_FILENO,buf,n);

			}

			while((n1=read(FD2,buf1,BUFSZ)))
			{
				write(STDOUT_FILENO,buf1,n1);
			}

			close(FD1);
			close(FD2);
		}


		if((strcmp (argv[1],"-")!=0) && (strcmp(argv[2],"-")!=0))
		{
			int FD1;

			if ((FD1 = open(argv[1], O_RDONLY))<0)
			{
				perror(argv[1]);
				exit(-1);
			}

			int n1;
			char buf1[BUFSZ];
			int FD2;

			if ((FD2 = open(argv[2], O_RDONLY))<0)
			{
				perror(argv[2]);
				close(FD1);
				exit(-1);
			}


			while((n=read(FD1,buf,BUFSZ))>0)
			{
				write(STDOUT_FILENO,buf,n); 
			}

			while((n1=read(FD2,buf1,BUFSZ))>0)
			{
				write(STDOUT_FILENO,buf1,n1);
			}
			close(FD1);
			close(FD2);
		}

	}


	if(argc ==4)
	{
		if((strcmp (argv[1],"-")==0) && (strcmp(argv[2],"-")==0))
		{
			printf("Error: Incorrect Arguments\n"); 
			exit(-1);
		}

		int FDOUT;

		if(strcmp (argv[1],"-")==0)
		{
			int FD1=STDIN_FILENO;
			int FD2;

			if ((FD2 = open(argv[2], O_RDONLY))<0)
			{
				perror(argv[2]);
				close(FD1);
				exit(-1);
			}

			if((FDOUT = open(argv[3],O_WRONLY|O_TRUNC|O_CREAT,0600))<0)
			{
				perror(argv[3]);
				close (FD1);
				close (FD2);
				exit(-1);
			}

			while ((n=read(FD1,buf,BUFSZ)))
			{
				write(FDOUT,buf,n);
			}

			while((n=read(FD2,buf,BUFSZ))>0)
			{
				write(FDOUT,buf,n);
			}   

			close(FD1);
		        close(FD2);
		        close(FDOUT);

		}

		if(strcmp (argv[2],"-")==0)
		{
			int FD1;

			if ((FD1 = open(argv[1], O_RDONLY))<0)
			{
				perror(argv[1]);
				exit(-1);
			}

			int n1;
			char buf1[BUFSZ];
			int FD2=STDIN_FILENO;

			if((FDOUT = open(argv[3],O_WRONLY|O_TRUNC|O_CREAT,0600))<0)
			{
				perror(argv[3]);
				close (FD1);
				close (FD2);
				exit(-1);
			}

			while((n=read(FD1,buf,BUFSZ))>0)
			{
				write(FDOUT,buf,n);
			}

			while((n1=read(FD2,buf1,BUFSZ)))
			{
				write(FDOUT,buf1,n1);
			}

			close(FD1);
			close(FD2);
			close(FDOUT);
		}

		if((strcmp (argv[1],"-")!=0) && (strcmp(argv[2],"-")!=0))
		{
			int FD1;

			if ((FD1 = open(argv[1], O_RDONLY))<0)
			{
				perror(argv[1]);
				exit(-1);
			}

			int n1;
			char buf1[BUFSZ];
			int FD2;

			if ((FD2 = open(argv[2], O_RDONLY))<0)
			{
				perror(argv[2]);
				close(FD1);
				exit(-1);
			}

			if((FDOUT = open(argv[3],O_WRONLY|O_TRUNC|O_CREAT,0600))<0)
			{
				perror(argv[3]);
				close(FD1);
				close (FD2);
				exit(-1);
			}

			while((n=read(FD1,buf,BUFSZ))>0)
			{
				write(FDOUT,buf,n);
			}

			while((n1=read(FD2,buf1,BUFSZ))>0)
			{
				write(FDOUT,buf1,n1);

			}

			close(FD1);
			close(FD2);
			close(FDOUT);
		}

	}

return(0);
}


