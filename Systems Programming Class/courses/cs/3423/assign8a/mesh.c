#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

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

int main (void) {
	// sentinal
	int s = 1;	
	char buf[1024];
	struct cmd command;

	int fd[2], fdin, fdout,fdinflag = 0,fdoutflag = 0,ndx,mypid;
    	pid_t pid, pidBG;

	while(s) {
		// custom cmd line
 		printf("CMDLINE$-->");

		// wil get first line of input		 
		if((gets(buf) == NULL)){
			continue;
	        }
	        else if(strcmp(buf, "exit") == 0){
			s = 0;
            		continue;
        	}
		
		// will read into struct
		if (cmdscan(buf,&command)){
            		printf("Illegal Format: \n");
            		continue;
        	}
		
		// if there is for redirect_in set a flag
		if(command.redirect_in == 1){	
            		if((fdin = open(command.infile, O_RDONLY)) == -1){
                		perror("fdin");
                		exit(-1);
            		}
			fdinflag = 1;
        	}
		
		// if there is for redirect_out set a flag
        	if(command.redirect_out == 1){
			
        		if(command.redirect_append == 1){
                		if((fdout = open(command.outfile, O_WRONLY | O_APPEND | O_CREAT, 0600)) == -1){
                 			perror("open append");
                   			exit(-1);
               			}		
            		}
            		else
			{
               			if((fdout = open(command.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1){
                    			perror("open out");
                    			exit(-1);
                		}
            		}
			fdoutflag = 1;
        	}
		// if the user wants to pipe do here
		if (command.piping) {
			if ( command.background == 1){
           			pipe(fd);
           			ndx = 0;
           			switch( fork()){
               				case -1: 
                 	  			perror("fork error");
                   				exit(-1);
               				case 0:
                   				switch( fork()){
                       					case -1:
                           					perror("fork error");
                           					exit(-1);
                       					case 0:
                           					ndx = 1;
                           					switch( fork()){
                               						case -1:
                                   						perror("fork error");
                                   						exit(-1);
                               						case 0:
                                   						ndx = 2;
                                   						break;
                               						default:
                                   						break;
                           					}
                       					default:
                           					exit(0);
                   				}
               				default:
                   				wait(NULL);
           			}
		// the user does not want to background       		
		}else{  
           		pipe(fd);
           		
           		ndx = 0;

           		switch(fork()){
               			case -1:
                   			perror("fork error");
                   			exit(-1);
               			case 0:
                   			ndx = 1;
                   			mypid = getpid();
                   			switch(fork()){
                       				case -1:
                           				perror("fork error");
                           				exit(-1);
                       				case 0:
                           				ndx = 2;
                           				break;
                       				default:
                           				break;        
                   			}
               			default:
                   			break;        
           		}
       	 	}   
       		if (ndx == 0){
           		close(fd[0]);
           		close(fd[1]);
			// need to close them in the parent process!!!! why my program kept writing to my out program all the time 
	   		if (fdinflag) {
	   			close(fdin);
	   		} 
           		if (fdoutflag) {
	   			close(fdout);
	   		}
           		waitpid(mypid, NULL, 0);
       		}
       		if (ndx == 1){
           		close(fd[1]);
           		if (fdoutflag){
               		dup2(fdout, STDOUT_FILENO);
               		close(fdout); 
           		}
           		dup2(fd[0], STDIN_FILENO);
           		close(fd[0]);
           		execvp(command.argv2[0], command.argv2);
           		perror("exec error");
           		exit(-1); 
       		}
       		if (ndx == 2){
         		close(fd[0]);
           		if (fdinflag){
	       			dup2(fdin, STDIN_FILENO);          
               			close(fdin);
           		}
           		dup2(fd[1], STDOUT_FILENO);
           		close(fd[1]);
           		execvp(command.argv1[0], command.argv1);
           		perror("exec error");
           		exit(-1); 
       		}
   		
	
		} else {
				switch(pid = fork()) {
					case -1:
						perror("fork error");
						exit(-1);
					case 0:
						if (command.background == 1) {	
							switch(fork()){
								case -1:
									perror("fork error");
									exit(-1);
								case 0:
									if (fdinflag) {
										dup2(fdin,STDIN_FILENO);
										close(fdin); 
									}
									if (fdoutflag) {
										dup2(fdout,STDOUT_FILENO);
										close(fdout);
									}
									execvp(command.argv1[0],command.argv1);
									perror("exec error");
									exit(-1);
								default:
									exit(0); 	
							}					
						}
						else{
							if (fdinflag) {
                                                		dup2(fdin,STDIN_FILENO);
                                                                close(fdin); 
                                                        }
                                                        if (fdoutflag) {
                                                                dup2(fdout,STDOUT_FILENO);
                                                                close(fdout);
                                                        }
                                                        execvp(command.argv1[0],command.argv1);
                                                        perror("exec error");
                                                        exit(-1); 
						}
					default:
						if (command.background == 0){
							waitpid(pid,NULL,0);
							// needed to close the fdins and fdouts because they were still linked to parent processes and therefor all my commands were all being sent to the outfile. 							
							if (fdinflag) {
                                                		close(fdin); 
                                                        }
                                                        if (fdoutflag) {
                                                                
                                                                close(fdout);
                                                        }
							
						}else {
							if (fdinflag) {
								close(fdin);
							}
							if (fdoutflag) {
								close(fdout);
							}						
						}	
				}
		}	
	}
	exit(0);
}
