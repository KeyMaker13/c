#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genlib.h"

static int space_remove(char *s) 
{

/*
int i = 0, ic = 1, r = 0,space = 0;
//char *sp = (char *) malloc(strlen(s) * sizeof(char));
char sp[256];
while (*(s+i) != '\0'){
	if (*(s+i) == ' ' && *(s+i+1) == ' '){
		space = 1;
		r++;
	}
	if (space){
		sp[i] = *(s+i+r);
		i++;
	}
	
	else if (!space){
		sp[i] = *(s+i+r);
		i++;
	
	}
	else {
		sp[i] = *(s+i+r);
		i++;
	}
	space = 0;
}
sp[i+1] = '\0';
printf("sp:%s \n",sp);
//s = sp;
strcpy(s,sp);
//free(sp);
return r;
*/
int i = 0;
char *s1=malloc(strlen(s)*sizeof(char));
    char *s2=s1; // for printing
    int count=0;
    while(*s){
        *s1++=*s++; // copy first even if space, since we need the 1st space
        if(*(s-1) == ' '){ //if what we just copied is a space
            while(*s ==' '){
                count++;
                s++; // ignore the additional spaces
            }
        }
    }
    *s1='\0'; //terminate
    printf("%s",s2);
	//s = strcpy(s,s1);
	//s = s1;	
    return count;
}

main(){
printf("-----------------Fall 2010-------------------\n");

printf("-----------------Question 3-------------------\n");
char *s = "abc   def gh    ijklmn";
int rm = space_remove(s);
printf("here 3\n");
printf("Fixed: %d many spaces\n",rm);
printf("String now is :%s\n",s);





//char *t = "test";
//char *te = "ing";
//strcpy(t,te);

}