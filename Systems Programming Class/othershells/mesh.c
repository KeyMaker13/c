#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "cmdscan.h"

int cmdscan(char *cmdbuf, struct cmd *com);

int main(){
    char buf[1024];
    struct cmd command;
    int i, fd1[2], fd2[2];
    int fdin, fdout;
    int ndx;
    pid_t parent, mypid;

    printf("> ");    
    while(  ( strcmp( gets(buf), "exit" )!= 0 ) ){             
        if (cmdscan(buf,&command)){
            printf("Illegal Format: \n");
            continue;
        }
        i = 0;
        printf("prog1 = ");
        printf("%s\n",command.argv1[i++]);
        while( command.argv1[i] != NULL )
            printf("        %s\n",command.argv1[i++]);
            printf("redirect_in = %d\nredirect_out = %d\nredirect_append = %d\nbackground = %d\npiping = %d\n",
                command.redirect_in, command.redirect_out, command.redirect_append, 
                command.background, command.piping);
            if ( command.redirect_in )
            printf("infile = %s\n", command.infile);
            if ( command.redirect_out )
            printf("outfile = %s\n", command.outfile);
            if ( command.piping ) {
                i = 0;
                printf("prog2 = ");
                printf("%s\n",command.argv2[i++]);
                while( command.argv2[i] != NULL )
                    printf("        %s\n",command.argv2[i++]);
            }
        printf("executing!\n");
     if ( command.piping != 1){  
        /* ONE PROC */              
        if ( command.background == 1){
            /* DOUBLE FORK */
            switch( fork()){
                case -1: perror("fork error");
                     exit(-1);
                case 0: 
                    switch( fork()){                                
                        case -1: 
                            perror("fork error");              
                            exit(-1);
                        case 0: 
                            if (command.redirect_in == 1){          // redirect in
                                fdin = open(command.infile, O_RDONLY);
                                if (fdin < 0 ){
                                    perror("<infile> open error");
                                    exit(-1);
                                }
                                dup2(fdin, STDIN_FILENO);          // dup2 filein STDIN
                                close(fdin);
                            }
                            if(command.redirect_out == 1){        // redirect out n append
                                if (command.redirect_append == 1){
                                    fdout = open(command.outfile, O_WRONLY | O_CREAT | O_APPEND, 0600);
                                    if (fdout < 0 ){
                                        perror("<outfile> open error");
                                        exit(-1);
                                    }
                                }else{
                                    fdout = open(command.outfile, O_RDONLY | O_CREAT | O_TRUNC, 0600);
                                    if (fdout < 0 ){
                                        perror("<outfile> open error");
                                        exit(-1);
                                    }
                                }
                                dup2(fdout, STDOUT_FILENO);          // dup2 fileout into STDOUT
                                close(fdout); 
                            }
                            execvp(command.argv1[0], command.argv1);
                            perror("exec error");
                            exit(-1);
                        default: exit(0);
                    }  
                default: wait(NULL);           
            }
        }else{  // if no background can do one exec n parent wait(NULL)
            switch( fork()){                                
                case -1: 
                    perror("fork error");              
                    exit(-1);
                case 0: 
                    if (command.redirect_in == 1){          // redirect in
                        fdin = open(command.infile, O_RDONLY);
                        if (fdin < 0 ){
                            perror("<infile> open error");
                            exit(-1);
                        }
                        dup2(fdin, STDIN_FILENO);          // dup2 filein STDIN
                        close(fdin);
                    }
                    if(command.redirect_out == 1){        // redirect out n append
                        if (command.redirect_append == 1){
                            fdout = open(command.outfile, O_WRONLY | O_CREAT | O_APPEND, 0600);
                            if (fdout < 0 ){
                                perror("<outfile> open error");
                                exit(-1);
                            }
                        }else{
                            fdout = open(command.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0600);
                            if (fdout < 0 ){
                                perror("<outfile> open error");
                                exit(-1);
                            }
                        }
                        dup2(fdout, STDOUT_FILENO);          // dup2 fileout into STDOUT
                        close(fdout); 
                    }
                execvp(command.argv1[0], command.argv1);
                perror("exec error");
                exit(-1); 
                default:
                    wait(NULL);     
            } 
        }
    }else{  // 2 PROCS
        if ( command.background == 1){
            pipe(fd1);
            ndx = 0;
            switch( fork()){
                case -1: 
                    perror("fork error\n");
                    exit(-1);
                case 0:
                    switch( fork()){
                        case -1:
                            perror("fork error\n");
                            exit(-1);
                        case 0:
                            ndx = 1;
                            switch( fork()){
                                case -1:
                                    perror("fork error\n");
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
        }else{  /* NO BACKGROUND */
            pipe(fd1);
            // need to fork 2 procs and give index;
            ndx = 0;
            // creating 2 procs
            switch(fork()){
                case -1:
                    perror("fork error\n");
                    exit(-1);
                case 0:
                    ndx = 1;
                    mypid = getpid();
                    switch(fork()){
                        case -1:
                            perror("fork error\n");
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
            close(fd1[0]);
            close(fd1[1]);
            waitpid(mypid, NULL, 0);
        }
        if (ndx == 1){
            close(fd1[1]);
            if(command.redirect_out == 1){        // redirect out n append
                if (command.redirect_append == 1){
                    fdout = open(command.outfile, O_WRONLY | O_CREAT | O_APPEND, 0600);
                    if (fdout < 0 ){
                        perror("<outfile> open error");
                        exit(-1);
                    }
                }else{
                    fdout = open(command.outfile, O_WRONLY | O_CREAT | O_TRUNC, 0600);
                    if (fdout < 0 ){
                        perror("<outfile> open error");
                        exit(-1);
                    }
                }
                dup2(fdout, STDOUT_FILENO);          // dup2 fileout into STDOUT
                close(fdout); 
            }
            dup2(fd1[0], STDIN_FILENO);
            close(fd1[0]);
            execvp(command.argv2[0], command.argv2);
            perror("exec error");
            exit(-1); 
        }
        if (ndx == 2){
            close(fd1[0]);
            if (command.redirect_in == 1){          // redirect in
                fdin = open(command.infile, O_RDONLY);
                if (fdin < 0 ){
                    perror("<infile> open error");
                    exit(-1);
                }
                dup2(fdin, STDIN_FILENO);          // dup2 filein STDIN
                close(fdin);
            }
            dup2(fd1[1], STDOUT_FILENO);
            close(fd1[1]);
            execvp(command.argv1[0], command.argv1);
            perror("exec error");
            exit(-1); 
        }
    }

    printf("\n> ");
  }                                  
  exit(0);
}    











