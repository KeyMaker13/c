#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "genlib.h"
#include "simpio.h"
#include "strlib.h"
#include "string.h"
#include "scanadt.h"


int CheckScan(char *scan){
char *sp;
sp = scan;

while(*sp){
if (*sp == ' ' || isspace(*sp)){
	return 0;
}
if (*sp == '[' || *sp == ']'){
	return 0;
}
if (*sp == '+' || *sp == '-' || *sp == '=' || *sp == '/'){
	return 0;
}
if (*sp == '{' || *sp == '}'){
	return 0;
}
if (*sp == '(' || *sp == ')'){
	return 0;
}
if (*sp == ',' || *sp == ';'){
	return 0;
}
if (*sp == '<' || *sp == '>'){
	return 0;
}
if (isdigit(*sp)){
	return 0;
}
*sp++;
}
return 1;
}

int CheckScanWord(char *scan){
char *sp;
sp = scan;

if (strcmp(sp,"for") == 0){
return 0;
}
if (strcmp(sp,"int") == 0){
return 0;
}
if (strcmp(sp,"double") == 0){
return 0;
}
if (strcmp(sp,"char") == 0){
return 0;
}
if (strcmp(sp,"string") == 0){
return 0;
}
if (strcmp(sp,"return") == 0){
return 0;
}
if (strcmp(sp,"long") == 0){
return 0;
}
if (strcmp(sp,"float") == 0){
return 0;
}
free(sp);
return 1;
}

int BeginsWithChar(char *scan){
char *sp;
sp = scan;

if (isalpha(*sp)){
	return 0;

}
return 1;
}


main(int argc, char* argv[]){
scannerADT myScanner1, myScanner2;
myScanner1 = NewScanner();
myScanner2 = NewScanner();
string token1, token2;
int nTokens1, nTokens2, allTokensCount = 0, sameTokensCount = 0;


// read in both files
FILE *student1, *student2;
student1 = fopen(argv[1], "r");
student2 = fopen(argv[2], "r");
// if null then files could not be read
if (student1 == NULL){
printf("File 1 could not open\n");
}

if (student2 == NULL){
printf("File 2 could not open\n");
}

// scanner part
// dont forget to free strings
fseek(student1, 0, SEEK_END);
long int size1 = ftell(student1);
rewind(student1);
char* content1 = calloc(size1 + 1, 1);
fread(content1,1,size1,student1);

fseek(student2, 0, SEEK_END);
long int size2 = ftell(student2);
rewind(student2);
char * content2 = calloc(size2 + 1, 1);
fread(content2,1,size2,student2);

SetScannerString(myScanner1,content1);
SetScannerString(myScanner2,content2);
    nTokens1 = 0;
	nTokens2 = 0;
    while (MoreTokensExist(myScanner1) && MoreTokensExist(myScanner2)) {
        token1 = ReadToken(myScanner1);
		token2 = ReadToken(myScanner2);
        nTokens1++;
		nTokens2++;
		allTokensCount++;
		
		//if (CheckScan(token1) && CheckScan(token2) && CheckScanWord(token1) && CheckScanWord(token2)){
			if (strcmp(token1,token2) == 0 || (BeginsWithChar(token1) == 0 && BeginsWithChar(token2) == 0 ) ){
				//printf("file is the same\n");
				sameTokensCount++;
			}
		//}
        printf("%2d: \"%s\" ", nTokens1, token1);
		printf("%2d: \"%s\" \n", nTokens2, token2);
		free(token1);
		free(token2);
    }
//}

//printing information 
//print how many lines matched and the percentage
printf("%d percent of the lines match\n",((sameTokensCount*100)/allTokensCount));


free(content1);
free(content2);
FreeScanner(myScanner1);
FreeScanner(myScanner2);
fclose(student1);
fclose(student2);
}