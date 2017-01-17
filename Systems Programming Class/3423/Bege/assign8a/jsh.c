#include <stdio.h>
#include <sys/types.h>
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


int main(void){


char in[1024];

  struct cmd command;
while(strcmp(gets(in),"exit")!=0){

    if (cmdscan(in,&command)){
      printf("Illegal Format: \n");
      continue;
    }




if(argv2==NULL){



switch (fork()){

case -1: printf("error\n"); exit(-1);

case 0:
exacvp(command.argv1);




}







    }

return 0;
    }
