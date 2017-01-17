#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
struct cmd
  {
    int redirect_in;     /* Any stdin redirection?         */
    int redirect_out;    /* Any stdout redirection?        */
    int redirect_append; /* Append stdout redirection?     */
    int background;      /* Put process in background?     */
    int piping;          /* Pipe prog1 into prog2?         */
    char *infile;        /* Name of stdin redirect file    */
    char *outfile;       /* Name of stdout redirect file   */
    char *argv1[10];     /* First program to execute       */
    char *argv2[10];     /* Second program in pipe         */
  };

int cmdscan(char *cmdbuf, struct cmd *com);


int main(){
	int stop = 0;
	char buf[1024];
	struct cmd command;
	int i;
	int fd[2], fdin, fdout;
	pid_t pid, pidBG;

	while(!stop){ 
		write(STDOUT_FILENO, ">", 1);
		if((gets(buf) == NULL)){
			continue;
		}
		else if(strcmp(buf, "exit") == 0){
			stop = 1;
			continue;
		}
	    	if (cmdscan(buf,&command)){
	    		printf("Illegal Format: \n");
			continue;
	    	}
		if(command.redirect_in){
			if((fdin = open(command.infile, O_RDONLY)) == -1){
				perror("fdin");
				exit(-1);
			}
		}
		if(command.redirect_out){
			if(command.redirect_append){
				if((fdout = open(command.outfile, O_WRONLY | O_APPEND | O_CREAT, 0600)) == -1){
					perror("open append");
					exit(-1);
				}
			}
			else{
				if((fdout = open(command.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1){
					perror("open out");
					exit(-1);
				}
			}
		}
		switch(pid = fork()){
			case -1:
				perror("fork");
				exit(-1);
			case 0:
				if(pipe(fd) == -1){
					perror("pipe");
					exit(-1);
				}
				switch(pidBG = fork()){
					case -1:
						perror("fork2");
						exit(-1);
					case 0:
						close(fd[0]);
						if(command.redirect_in){
							close(0);
							dup(fdin);
							close(fdin);
						}
						if(command.redirect_out && !command.piping){
							close(1);
							dup(fdout);
							close(fdout);
						}
						else if(command.piping){
							dup2(fd[1], STDOUT_FILENO);
						}
						close(fd[1]);
						execvp(command.argv1[0], command.argv1);
						perror("execvp arg1");
						exit(-1);
						break;
					default:
						if(!command.piping){
							exit(0);
						}
						else{
							dup2(fd[0], STDIN_FILENO);
							close(fd[0]);
							if(command.redirect_out){
								close(1);
								dup(fdout);
								close(fdout);
							}
							close(fd[1]);
							execvp(command.argv2[0], command.argv2);
							perror("execvp arg2");
							exit(-1);
						}
				}
			default:
				if(!command.background){
					if(waitpid(pid, NULL, 0) != pid){
						perror("waitpid error");
						exit(-1);
					}
				}
		}
	}
  exit(0);
}
