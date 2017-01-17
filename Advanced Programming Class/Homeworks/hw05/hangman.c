#include <stdio.h>
#include <stdlib.h>
#include "randword.h"

static const int NumberOfTries = 8;



Prompt(){
printf("welcome to hangman!\n");
printf("I will guess a secret word. On each turn, you guess a letter.");
printf("If the letter is in the secret word, I will show you where it appears;\n");
printf("If not, a part of your body gets strung up on the scaffold.\n");
printf("The object is to guess the word before you are hung.");
printf("\n");
}

int ChangeWord(char *word, char *gWord){
int i = 0;
while(word[i] != '\n'){
gWord[i] = word[i];
word[i] = '-';
i++;
}
return i;
}

CheckLetter(char *gWord, char *dWord, char input, int wSize, int *wC){
int correct = 0, i = 0;
for (i = 0; i <wSize; i++){
		if (input == gWord[i]){
		correct = 1;
		wC++;
		dWord[i] = input;
		}
}

if (correct){
printf("That guess is correct\n");
printf("The word now looks like this: %s\n", dWord);
}
if (!correct){
printf("There are no %c's in the word\n",input);
printf("The word now looks like this: %s\n", dWord);
}

}


Game(){
int i = 1, startGame = 0, wordSize, wordCounter;
startGame = InitDictionary();
char *wordChosen = ChooseRandomWord(startGame);
char *displayWord = wordChosen ,letter, *gameWord;
wordSize = ChangeWord(displayWord,gameWord);

printf("The word now looks like this: %s\n", displayWord);
printf("You have %d guesses left.\n", NumberOfTries);

while(i <= NumberOfTries){
printf("Guess a letter: ");
scanf("%c\n",&letter);
CheckLetter(gameWord,displayWord,letter,wordSize,&wordCounter);
if (wordCounter==wordSize){
printf("You guessed the word: %s\n",displayWord);
printf("You win\n");
}else{
printf("You have %d guesses left.\n", (NumberOfTries - i));
}
i++;
}
}

main(){
Prompt();
Game();
}

