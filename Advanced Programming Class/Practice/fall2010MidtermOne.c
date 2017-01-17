#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

//question1
double *MinMax(double minMax[], int numOfElements);
//question3
int IsVowel(char ch);
//int removeVowelArray(char s[]);
int removeVowelPointer(char *s);

main(int argc, char *argv[]){
//question1
double test[] = {6.5,2.0,4.4,8.1,3.3};
double *values;
values = MinMax(test, 5);
printf("The min is %lf the max is %lf",values[0],values[1]);
printf("\n");
int v = 14 % 5 / 3;
printf("%d",v);

//question3
//char s[] = {"xyabbAaaecccDEf"};
//int six = removeVowelArray(s);
//printf("removed %d vowels and the remaining string is %s",six,s);
//char testCh[] = {"test"};
//char *testingCh;

//char testingCh[] = {"testing"};
//testingCh = testCh;
//printf("new array is now %s ", testingCh);

//question 4
/*
while (--argc > 0 ){
printf("%s\n", *(argv+argc));
}
printf("%c\n", argv[0][5]);
printf("%c\n", *(argv[2]+3));
*/
}

//question 1
double *MinMax(double minMax[], int numOfElements){
double min = minMax[0], max = 0, temp;
static double r[2];
int i;
for (i = 1; i < numOfElements; i++){
	if (max < minMax[i]){
		max = minMax[i];
		}

	if (min > max){
	temp = max;
	max = min;
	min = temp;
	}
}
r[0] = min;
r[1] = max;

return r;
}

//question3
int IsVowel(char ch){
	switch(ch){
	case 'A': case 'E': case 'I': case 'O': case 'U':
	case 'a': case 'e': case 'i': case 'o': case 'u':
	return 1;
	default:
	return 0;
	}
}

/*
int removeVowelArray(char s[])
{
int sizeOfS = 0;
int sizeOfV = 0;
int i =0;


while (s[i] != '\0'){
if (IsVowel(s[i]) == 1){
sizeOfV++;

}
i++;
}
sizeOfS= i;
char temp[sizeOfS - sizeOfV];
i = 0;
int tempc = 0;
while (s[i] != '\0'){
if (IsVowel(s[i]) == 0){
temp[tempc] = s[i];
tempc++;
}
i++;
}

i = 0;
while (temp[i] != '\0'){
s[i] = temp[i];
i++;
}
s[++i] = '\0';


return sizeOfV;
}
*/

int removeVowelPointer(char *s)
{
int r = 0, i = 0;

	while (*(s+i) != '\0'){
	if (IsVowel(*(s+i)) == 1){
	*(s+i) = 'T';
	r++;
	}
	i++;
	}
return r;
}

