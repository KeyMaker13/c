#ifndef _mnemonics_h
#define _mnemonics_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //for isalpha(c)
#include <string.h> // for strlen(s)

const char *PressDialPad(char key);

void ListMnemonics(char *str);

// make a recursive function that will do the recursive calls

// run a for loop to see if all characters are numbers and if it is not a number record the character inputed 
// if number is less than 2 or greater than 9  
		// brainstorming at bottom // do recursive calls
// if not true then print that the *str is incorrect and print the character that was not correct or the fact that it is less than two or greater than nine
// make check int lessThanTwo = 0,isACharacter = 0;
// if one of the checks comes true then the int becomes one 
// if one of the ints and true then either print not less than 9 and not greater than two or is a character and display the character to the user


		// this recursive function is quite hard to figure out
		// recursive call
			// run the *str through a recursive call
				// base case
					// base case - the digit in the call is called 3 times or reaches the last character
					// every single digits last character must be called for the recursion to stop
				// printing
					// must print out the characters bieng used in the calls
				// RecursiveSolve(char *str ,int strIndex,int strLength,int callIndex,int callLength);
					//
				
				
					
//void RecursiveSolve(char *str ,int strIndex,int strLength,int callIndex,int callLength);
void RecursiveSolve(char *str, int track);
// base case
	//  callindex == call length 
	
	
	//if (callIndex)
		//printf str[strIndex]


#endif

