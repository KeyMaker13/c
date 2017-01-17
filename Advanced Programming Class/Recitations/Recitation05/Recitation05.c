#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

//prototypes
void UserInstruct(void);
int NumberOfCharacters(char *string);
void ReverseCharacters(char *string);
int LexOrder(char *s1, char *s2);
void LexOrderPrint(int p);
int StringSearch(char *s1, char *s2);
void StringSearchPrint(int p);

// char* myArray;
// myArray++;
main(){
UserInstruct();
char *s1;
char *s2;
s1 = GetLine();
s2 = GetLine();

int s1Length = NumberOfCharacters(s1);
int s2Length = NumberOfCharacters(s2);

//displaying number of characters
printf("The first string you entered is %d characters long\n", s1Length);
printf("The second string you entered is %d characters long\n", s2Length);

//reversing string
printf("Your first string in reverse is ");
ReverseCharacters(s1);
printf("\n");
printf("Your first string in reverse is ");
ReverseCharacters(s2);
printf("\n");

//lexographical order
printf("Comparing in lexographic order\n");
int lex = LexOrder(s1,s2);
LexOrderPrint(lex);


// s1 in s2
int ss = StringSearch(s1,s2);
StringSearchPrint(ss);

// testing purposes
//char test[] = "test";
//char testing[] = "testing";

//char *testString1 = test;
//char *testString2 = &testing;

//int numOfChar = NumberOfCharacters(testString1);
//printf("test %d", numOfChar);
}

void UserInstruct(void){
printf("Enter two words\n");
printf("I will count the letters for both\n");
printf("I will reverse both of them\n");
printf("I will compare both of them and display the number 0 if they are the same\n");
printf("Display -1 if S1 comes before S2\n");
printf("Display 1 if S1 comes after S2\n");
printf("Enter your two Strings\n");
}

int NumberOfCharacters(char *string){
int count = 0;
while(*string != '\0'){
	string++;
	count++;	
}	
return count;
}

// must minus one to count because of the null '\0' character
void ReverseCharacters(char *string){
int count = NumberOfCharacters(string);
int s = 1;
//char display;
while (s){
	if (count == -1){
	s = 0;
	}
	else{
	//display = *string+count;
	//printf("%c", display);
	// must put *(string+count)
	printf("%c", *(string+count));
	count--;
	}
}
}

int LexOrder(char *s1, char *s2){

int sizeOfS1 = NumberOfCharacters(s1);
int sizeOfS2 = NumberOfCharacters(s2);

int s = 1;

int r = 0;

int count = 0;

while(s){
if (count == sizeOfS1 || count == sizeOfS2){
	s = 0;
	if (sizeOfS1 > sizeOfS2){
	r = 1;
	return 1;
	}
	if (sizeOfS2 > sizeOfS1){
	r = -1;
	return -1;
	}
}

if ( *(s1+count) < *(s2+count) ){
s = 0;
r = -1;
return -1;
}

if (*(s1+count) > *(s2+count)){
s = 0;
r = 1;
return 1;
}
count++;
}
	return r;
}

void LexOrderPrint(int p){

if (p == 0)
printf("Two words are the same\n");

if (p == 1)
printf("S1 is after S2\n");

if (p == -1)
printf("S1 is before S2\n");

}

int StringSearch(char *s1, char *s2){

int size = NumberOfCharacters(s1);
int i = 0;

int r = 1;
while (i < size){
	if (*(s1++) != *(s2++)){
		r = 0;
	}
	i++;
}

return r;
}

void StringSearchPrint(int p){
if (p == 1)
	printf("S1 is in S2\n");
	
if (p == 0)
	printf("S1 is not in S2\n");

}