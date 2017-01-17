#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //for isalpha(c)
#include <string.h> // for strlen(s)
#include "mnemonics.h"


// init the dialpad with values
const char *PressDialPad(char key){
switch (key) {
        case '2': return "ABC";
        case '3': return "DEF";
        case '4': return "GHI";
        case '5': return "JKL";
        case '6': return "MNO";
        case '7': return "PRS";
        case '8': return "TUV";
        case '9': return "WXY";
        default:
            return NULL;
		}
}

// function that will call the recursive function to print out all the characters
// does checks to see if a valid string is passed
void ListMnemonics(char *str){
int i = 0, ci = 0, notInRange = 0, checkRange = 0, isACharacter = 0, notDigitNotChar = 0, stringLength =0;
char notInRangeDigit;

stringLength = strlen(str);

	// check the string to see if it is valid
	while(str[i] != '\0'){
		if (isalpha(str[i])){
			isACharacter = 1;
		}
		if (isdigit(str[i])){
			checkRange = str[i] - '0' ;
				if (checkRange < 2 || checkRange > 9){
					notInRange = 1;
					notInRangeDigit = str[i];
				}
		}
		if(!isalpha(str[i]) && !isdigit(str[i])){
			notDigitNotChar = 1;
		}
		i++;
	}

i = 0;

	// passed checks so do recursive call
	if (notInRange == 0 && isACharacter == 0 && notDigitNotChar == 0){
		printf("Mnemonics for %s are:\n",str);
		RecursiveSolve(str,0);
		//printf("%s passed the checks\n", str);
	}

	// one of the digit was not within the range
	if (notInRange){
		printf("Mnemonics for %s are:\n", str);
		printf("None, %s contains a %c digit\n", str, notInRangeDigit);
	}
	
	// one of the digit is a character
	if (isACharacter){
		printf("Mnemonics for %s are:\n" , str);
		printf("None, %s contains at least one alphabetic character\n", str);	
	}
	
	// one of the digit is not a character and not a digit
	if (notDigitNotChar){
		printf("Mnemonics for %s are:\n" , str);
		printf("None, %s contains a character that is not a digit\n", str);
	
	}

}

// this method calls itself to solve the mnemonic puzzle
//void RecursiveSolve(char *str ,int strIndex,int strLength,int callIndex,int callLength){
void RecursiveSolve(char *str, int track){
/*
int i  = 0;
int charToInt = 0;
//base case
	if ( (strIndex == strLength) && (callIndex == callLength) ){
		for (i = 0; i < strIndex; i++)
			charToInt = (str[strIndex] - '0'); printf("%c ",dialPad[strIndex-2][callIndex]);
	}
	else if (callIndex <= callLength){
		RecursiveSolve(str,strIndex + 1, strLength, callIndex, callLength);
	
	}
*/
char originalChar = str[track];
	if (originalChar == 0){
		printf("%s\n", str);
	} else {
		const char *letters = PressDialPad(originalChar);
			if (letters==NULL) {
				str[track] = '*';
				RecursiveSolve(str, track + 1);
			} else {
				for(;*letters!=0; letters++) {
					str[track] = *letters;
					RecursiveSolve(str, track + 1);
            }
        }
        str[track] = originalChar;
    }
}


