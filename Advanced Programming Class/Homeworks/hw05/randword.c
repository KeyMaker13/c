#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "randword.h"


string words[20];

int InitDictionary(){
string scan;
int counter = 0;
ILE *infile = fopen("words.txt","r");
if(infile == NULL){
	printf("file name not correct\n");
	exit(1);
}
//while(fscanf(infile, "%s\n", &stringScan) != EOF){
//words[counter] = stringScan;
while (fscanf(infile,"%s\n",&scan) != EOF){
//while(feof(infile) == 0){
words[counter] = scan;
counter++;
        }

fclose(infile);
return counter; 
}

string ChooseRandomWord(int fileSize){
//static char *rWord;
//int fileSize = InitDictionary();
int r , i = 0;

r = rand() % 20;
//int randWord = rand()%fileSize;

	 
   
//rWord = words[randWord]; 
//return rWord;
return words[randWord];
}