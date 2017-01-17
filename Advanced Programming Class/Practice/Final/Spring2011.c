#include <stdio.h>

char *read_a_tag(FILE *fp);

main(int argc, char *argv[]){


printf("-----------------Question Two--------------\n");
FILE *in;
char *t;
in = fopen(argv[1],"r");
if (in == NULL) printf("No Memory Left\n");
t = read_a_tag(in);
printf("First tag is : %s\n",t);


}

char *read_a_tag(FILE *inFile){

char *tag = NULL, tmp[256];
int t = 1, open = 0, i = 0;

while (t){
	if (open){
		fscanf(inFile,"%c",&tmp[i]);
		if (tmp[i]== '>'){
			open = 0;
			t = 0;
			tmp[i] = '\0';
		}
		else{
			//tmp[i++] = ch;
			i++;
		}
	}
	else {
		fscanf(inFile,"%c",&tmp[i]);
		if(tmp[i] == '<'){
			open = 1;
		}
	}
}
tag = tmp;
return tag;
}