#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
char *ReverseCopy(char *s);


static int tag_match(char *b, char *c){

printf(" b:%s , c:%s \n",bt,ct);


/*
char *bp, *cp;
int i = 1, i2 = 0;
bp = b; 
cp = c;
if (bp == NULL || cp == NULL) return 12;
if (*c == '/') printf("test\n");
if (*b == '/') printf("testTwo\n");
*cp++;

while (cp != '\0'){
	while (bp != '\0'){
		printf("bp is :%c , cp is %c\n", *bp, *cp);
		if (*bp != *cp){
			return 0;
		}
		else{
		*bp++;
		//*(cp+i);
		}
	}
//*(bp+i2);
*cp++;
}

return 1;

//return 1;

*/

/*
int i = 0, r = 0;
char *cp = &*c, *bp = &*b;
while (*(cp+i) != '\0'){
	printf("here c:%c\n", *(cp+i+1));
	if (*(cp+i+1) == *(bp + i + 1)) {
		printf("hereTest b:%c\n\n", *(bp+i + 1));
		//return 0;
	}
		
	//*(cp++);
	i++;
}
//printf("all equal\n");
return 5;

*/


}

char *read_a_tag(FILE *inFile){

if (inFile == NULL) return "Null File";

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

main(int argc, char *argv[]){
char *t;
t = "test";

char *d = ReverseCopy(t);
printf("Reversing String now\n");
printf("String:%s\n",d);

printf("-------------Question 2--------------\n");
stackADT stack = NewStack();
FILE *in; 
//char *test = (char *)malloc(256*sizeof(char)), *test2 , *t1; int tM;
char *test, *test2 , *t1; 
int tM;
in = fopen("webpage.html","r");
if (in == NULL) printf("Null File my nigga\n");

string t1 = read_a_tag(in);
string t2 = read_a_tag(in);



/*
if (tag_match(read_a_tag(in),read_a_tag(in))){
printf("Testing double method calls\n");
}
else{
	printf("Did not work\n");
}
*/

test = read_a_tag(in);
printf("Testing read_a_tag method, tag:%s \n",test); 
test2 = read_a_tag(in);
printf("Testing read_a_tag method, tag:%s \n",test2); 
tM = tag_match(test,test2);
printf("Did these tags match?:%d\n", tM);

test = read_a_tag(in);
t1 = (char *) malloc(strlen(test) * sizeof(char));
if (t1 == NULL) printf("No Memory\n");
t1 = test;
printf("Testing read_a_tag method, tag:%s \n",t1); 
test2 = read_a_tag(in);
printf("Testing read_a_tag method, tag:%s \n",test2); 
tM = tag_match(t1,test2);
printf("Did these tags match?:%d\n", tM);



fclose(in);



}

char *ReverseCopy(char *s)
{
char *r;
int l = strlen(s), i = 0;
printf("string Length: %d \n",l);
r =(char *) malloc(l*sizeof(char));
if (r == NULL)
	return "No Memory";

while(i < l){
*(r+i) = *(s+l-i-1);
//*(r+i) = 't';
i++;
}

//r = s;

return r;
}



