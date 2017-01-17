#include <stdio.h>
        #include <sys/types.h>
        #include <unistd.h>
        #include <stdlib.h>
        #include <string.h>

        int main(void){

        int t=0;
        int fd[9][2];
        int i;

        for(i=0;i<9 ;i++){

                if(pipe(fd[i])){
                        printf("error pipe\n");
                        exit(-1);
                }
        }

        int parent;
        int x;
        for(x=1;x<9;x++){

                switch(parent=fork()){
                        case-1: perror("fork error"); exit (-1);
                        case 0:  t=x ;
                                break;
                        default: break;
                }
                if(parent) break;
        }

        int x1;
        for(x1 =0;x1<9;x1++){
                if(x1!=t){
                        close(fd[x1][0]);
                }
                else {close (fd[x1][1]);}
        }

        int rng = RAND_MAX/9;
            rng*=9;
        int x2;
        srand(3773713*t);
        for(x2=0;x2<13;x2++){

                int num;
                int j;

                do{
                        num=rand();
                        j=num%9;
                }while(num>= rng || t==j);




                char str[9];
                snprintf(str,9,"process%d", t);
                if      (write(fd[j][1],str,sizeof(str)) <0 ){
                        printf("error on write\n");
                }

        }

        int x3;
        for(x3=0;x3<9;x3++)
                if(t!=x3){
                        close(fd[x3][1]);
                }


        char buf[9];
        while( read(fd[t][0],buf,sizeof(buf))>0){
                printf("process%d has received a message from %s\n",t,buf);
        }
        close(fd[t][0]);
        return 0;
}
