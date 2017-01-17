// I got a crossword puzzle of the internet and put it in code
// this is way better than the instructions I got for hw03
// so here it is and this code is all made and designed by me
// ivan capistran @01282924
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

#define row 15
#define col 15

//give user instructions
void UserInstruct(void);
void UserPrintPuzzle(char puzzle[row][col]);
void DisplaySearchWords(void);
char DisplaySearchWordsHex(int display);

//used this to test for how I was breaking down strings
// then i found out I had to use command line arguements
void TestStringBreakDown(char *string);

//my whole game
void Game(char puzzle[row][col], int argc, char *string[]);
static int SearchWords(char puzzle[row][col], char *string, int pc);
//void SearchWords(char puzzle[row][col], char *string);
static int Horizontal(char puzzle[row][col], char *string, int pc);
static int CheckHorizontalF(char puzzle[row][col], int r, int ac, char *string, int pc);
static int CheckHorizontalB(char puzzle[row][col], int r, int ac, char *string, int pc);
static int Verticle(char puzzle[row][col], char *string, int pc);
static int CheckVerticleF(char puzzle[row][col], int ar, int c, char *string, int pc);
static int CheckVerticleB(char puzzle[row][col], int ar, int c, char *string, int pc);
static int Diagonal(char puzzle[row][col], char *string, int pc);
static int CheckDiagonalFR(char puzzle[row][col], int ar, int ac, char *string, int pc);
static int CheckDiagonalBR(char puzzle[row][col], int ar, int ac, char *string, int pc);
static int CheckDiagonalFL(char puzzle[row][col], int ar, int ac, char *string, int pc);
static int CheckDiagonalBL(char puzzle[row][col], int ar, int ac, char *string, int pc);


//these are the command line arguements
main(int argc, char *argv[]){
// this is the puzzle i got from the internet, it is related to computers
char gamePuzzle[row][col] = {{'e','r','s','c','r','e','e','n','l','o','c','k','h','z','e'}, 
							 {'p','t','o','t','r','a','c','k','b','a','l','l','k','d','s'},
							 {'i','h','t','t','k','o','o','b','e','t','o','n','a','l','e'},
							 {'h','a','y','e','i','p','r','i','n','t','e','r','a','v','m'},
							 {'c','r','r','m','k','n','t','n','o','f','g','u','i','e','o'},
							 {'e','d','t','o','o','s','o','c','g','p','n','r','n','r','e'},
							 {'l','d','e','d','m','t','i','m','u','a','d','f','p','a','r'},
							 {'b','r','n','e','r','n','h','d','m','y','m','l','u','w','a'},
							 {'i','i','r','m','a','p','m','e','p','c','x','e','t','t','w'},
							 {'t','v','e','l','o','o','l','p','r','y','a','a','s','f','d'},
							 {'a','e','h','r','u','a','o','g','u','b','r','b','f','o','r'},
							 {'p','l','t','s','p','l','o','a','d','h','o','o','l','s','a'},
							 {'m','s','e','t','f','s','t','o','l','s','r','a','m','e','h'},
							 {'o','w','o','k','e','y','b','o','a','r','d','a','r','e','s'},
							 {'c','p','u','z','h','s','o','t','n','i','c','a','m','d','m'}}; 

// user instructions
UserInstruct();
UserPrintPuzzle(gamePuzzle);
DisplaySearchWords();

// telling user what words he or she searched for 
printf("\nThese are the words you searched for\n");
//char *words;
//argv = GetLine();
//TestStringBreakDown(words);

// searching for words and playing game
Game(gamePuzzle, argc, argv);

}

//test method no need to looky here
void TestStringBreakDown(char *string){
char *test;
test = (char *) malloc(1024);

int track = 0;
while(string[track] != '\0'){
//printf("test\n");
test[track] = string[track];
track++;
}

track = 0;
while(test[track] != '\0')
{
	printf("%c",test[track]);
	track++;
}
*(test+1) = '\0';
free (test);
}

//give user instructions
void UserInstruct(void){
printf("This is a word search program\n");
printf("I will display a word search puzzle\n");
printf("You will enter what words you want to find by entering them as command line arguments\n");
printf("I will tell you at what grid coordinates they start so you can start to notice them\n");
printf("For example the word Screen Lock starts at gamePuzzle[1][3] and runs horizontal\n");
printf("I will also display all the exact words to search for to run the program again.\n\n");
}

// print the puzzle to show user where to find his or her searched puzzles
void UserPrintPuzzle(char puzzle[row][col]){
int r = 0;
int c = 0;

for (r = -1; r < row ; r++){
	for (c = -1; c < col; c++){
		if ( c == -1 && r == -1){
		printf("  ");
		}
		if ( c > -1 && r == -1 ){
		printf("%c ",DisplaySearchWordsHex(c+1));
		}
		if (c == -1 && r > -1){
		printf("%c ",DisplaySearchWordsHex(r+1));
		}
		if(c > -1 && r > -1){
		printf("%c ",puzzle[r][c]);
		}
	}
	printf("\n");
	}
	
}

// display the words to search for 
void DisplaySearchWords(void){
printf("\nThese are the words to search for\n");
printf("bug  hardware  mouse\n");
printf("cables input notebook\n");
printf("chip keyboard ports\n");
printf("compatible lan printer\n");
printf("cpu laptop ram\n");
printf("diskette load rom\n");
printf("ethernet macintosh screenlock\n");
printf("fax manuals slots\n");
printf("floppydrive memory software\n");
printf("font modem trackball\n");
printf("games monitor upgrade\n");
printf("harddrive motherboard\n");
printf("I attached a picture in the folder so you can see that I took this puzzle from the internet\nNot sure what website it was from\n");
}

// this method returns the right character to display on the screen to align the crossword puzzle correctly
char DisplaySearchWordsHex(int display){
if (display == 1){
return('1');
}
if (display == 2){
return('2');
}
if (display == 3){
return('3');
}
if (display == 4){
return('4');
}
if (display == 5){
return('5');
}
if (display == 6){
return('6');
}
if (display == 7){
return('7');
}
if (display == 8){
return('8');
}
if (display == 9){
return('9');
}
if (display == 10){
return('A');
}
if (display == 11){
return('B');
}
if (display == 12){
return('C');
}
if (display == 13){
return('D');
}
if (display == 14){
return('E');
}
if (display == 15){
return('F');
}
}

// here is my game method, at first I didn't know what command line arguements were
// so then one of my buddy told me that I was doing this wrong so then I had to fix it all
// but it didn't take long since my logic on how to find the words works fine anyway
void Game(char puzzle[row][col],int argc, char *string[]){
/*
char *search;
search = (char *) malloc(1024);

int count = 0;
int pcounter = 0;

	while(string[count] != '\0'){
		if (string[count] != ' '){
		search[pcounter] = string[count];
		pcounter++;
		}
		if (string[count+1] ==
		if (string[count] == ' ' || string[count] == '\0'){	
			if (pcounter != 0){
			//search[pcounter+1] = '\0'; 
			SearchWords(puzzle,search,pcounter);
			//*(search - pcounter);
			search = NULL;
			pcounter = 0;
			}
		}
		count++;
	}
free(search);
*/
int i ;
int pcounter = 0;
char *temp;
for (i = 1; i < argc; i++){
temp = string[i];
	while(temp[pcounter] != '\0'){
	pcounter++;
	}
	//printf("length of pcounter %d\n" ,pcounter);
	// if search word == 0, then string[i] is not in the word puzzle
	int game = SearchWords(puzzle,string[i],pcounter);
	if(game != 1){
	printf("%s is not in the puzzle\n", string[i]);
	}
	pcounter = 0;
}
}

//this method is called for each string[] array and finds the words in all directions
// has a system to make sure the word is only found once and returns 0 if the word is not found
// change searchwords to ints to see if it found it
static int SearchWords(char puzzle[row][col], char *string, int pc){
//void SearchWords(char puzzle[row][col], char *string){

//if ((Horizontal(puzzle,string,pc) == 0 )&& (Verticle(puzzle,string,pc) == 0) && (Diagonal(puzzle,string,pc) == 0) ){
//return 0;
//}

// if anyone of these is already 1 stop search
if (Horizontal(puzzle,string,pc) == 1){
return 1;
}
else{ 
	if (Verticle(puzzle,string,pc) == 1){
	return 1;
	}
	else{
		if (Diagonal(puzzle,string,pc) == 1){
		return 1;
		}
		else{
		return 0;
		}
	}
}
//Verticle(puzzle,string,pc);
//Diagonal(puzzle,string,pc);
return 0;
}

//checks the word horizontal, pretty straight forward took me a while to set in the logic
static int Horizontal(char puzzle[row][col], char *string, int pc){
int r = 0;
int c = 0;

//int check  = 0;
//int rprint;
//int cprint;

// forward
for (r = 0; r < row; r++){
	for (c = 0; c < col; c++){
		if (puzzle[r][c] == *string){
			// if check horizontal is one return 1 
			if (CheckHorizontalF(puzzle, r, c, string, pc) == 1){
			printf("%s is horizontal forward starting at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
			return 1;
			//rprint = r;
			//cprint = c;
			//printf("%s is horizontal forward starting at gamePuzzle[%d][%d]\n",string,r,c);
			}
		}
		}
	}

// backward
for (r = 0; r < row; r++){
	for (c = (col - 1); c >= 0; c--){
	if (puzzle[r][c] == *string){
	// if check horizontal is one return 1
	if(CheckHorizontalB(puzzle,r,c,string,pc) == 1){
	printf("%s is horizontal backward starting at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
	return 1;
	}
	}
}
}
return 0;
}

// checks the word to see if it is horizontal forward
// used the words word count to see if it fully matches
static int CheckHorizontalF(char puzzle[row][col], int r, int ac, char *string, int pc){

int c = 0;
//int returnValue = 0;

//printf("stop check ac + pc = %d\n", (ac+pc));
if ((ac + pc) > col){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (c = 0; c < pc ; c++){
		//printf("%c = " , puzzle[r][ac + c]);
		//printf("%c\n" , string[c]);
		if (puzzle[r][ac + c] != string[c]){
		return 0;
		//printf("Checking value to see if its not equal\n");
		//returnValue = 0;
		//break;
		}
	} 
}
return 1;
}

// checks horizotal backward
static int CheckHorizontalB(char puzzle[row][col], int r, int ac, char *string, int pc){

int c = 0;
//int returnValue = 0;

if ((ac - pc) < 0){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (c = 0; c < pc ; c++){
		if (puzzle[r][ac - c] != *(string+c)){
		//returnValue = 0;
		return 0;
		}
	} 
}
return 1;
}

// checks verticle the logic is used from horizontal just gotta flip a few things around
static int Verticle(char puzzle[row][col], char *string, int pc){
int r = 0;
int c = 0;

//forward
for (c = 0; c < col; c++){
		for (r = 0 ; r < row; r++){
			if (puzzle[r][c] == *string ){
				if (CheckVerticleF(puzzle,r,c,string,pc) == 1){
				printf("%s is forward verticly at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
				return 1;
				}
			}
		}
}

//backward
for (c = 0; c < col; c++){
	for (r = (row - 1); r >= 0 ; r--){
		if (puzzle[r][c] == *string){
			if (CheckVerticleB(puzzle,r,c,string,pc) == 1){
			printf("%s is backward verticly at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
			return 1;
			}
		}
	}
}
return 0;
}

// checks word to be verticle forward
static int CheckVerticleF(char puzzle[row][col], int ar, int c, char *string, int pc){
int r = 0;
//int returnValue = 0;

if ((ar + pc) > row){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (r = 0; r < pc ; r++){
		if (puzzle[ar + r][c] != *(string+r)){
		//returnValue = 0;
		return 0;
		}
	} 
}
//return returnValue;
return 1;
}

// checks word to be verticle backward
static int CheckVerticleB(char puzzle[row][col], int ar, int c, char *string, int pc){
int r = 0;
//int returnValue = 0;

if ((ar - pc) < 0){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (r = 0; r < pc ; r++){
		if (puzzle[ar - r][c] != *(string+r)){
		//returnValue = 0;
		return 0;
		}
	} 
}
//return returnValue;
return 1;
}


// checks diagonal this one took a while to set in the logic of how the code was gonna break down each word
static int Diagonal(char puzzle[row][col], char *string, int pc){
int c = 0;
int r = 0;
// was thinking about breaking down the stuff into checking first half first, then second half or middle also
// but figured out another way
/*
int firstHalf = 0;
int middle = 0;
int secondHalf = 0;

int cc = 0;
int rc = 0;

//forward
// see whether to check first half 
// then check middle
// or then check second half

for (r = 0; r < row; r++){
	for (c = 0; c < col; c++){

	if (r == 0){
	firstHalf = 1;
	middle = 0;
	secondHalf = 0;
	}
	if ( r == 7){
	firstHalf = 0;
	middle = 1;
	secondHalf = 0;
	}
	if (r == 8){
	firstHalf = 0;
	middle = 0;
	secondHalf = 1;
	}
	if (firstHalf && i == 0){
	cc = col - 1;
	rc = 0;	
	}
	if (firstHalf && i > 0){
		if (CheckDiagonalF(puzzle, rc,cc string, pc) == 1){
		printf("%s is found diagonal foward at gamePuzzle[%d][%d]\n",rc,cc);
		}
		cc - c;
	}
*/	

//forward right
for (r = 0; r < row; r++){
		for (c = 0; c < col; c++){
			if (CheckDiagonalFR(puzzle,r,c,string,pc) == 1){
			printf("%s is found diagonal forward right at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
			return 1;
			}
		}
	
	}
	
//forward left
for (r = 0; r < row; r++){
		for (c = 0; c < col; c++){
			if (CheckDiagonalFL(puzzle,r,c,string,pc) == 1){
			printf("%s is found diagonal forward left at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
			return 1;
			}
		}
	
	}


//backward right
for (r = (row - 1); r >= 0; r--){
	for (c = (col -1) ; c >= 0; c--){
		if (CheckDiagonalBR(puzzle,r,c,string,pc) == 1){
		printf("%s is found diagonal backward right at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
		return 1;
		}
	}

}

//backward left
for (r = (row - 1); r >= 0; r--){
	for (c = (col -1) ; c >= 0; c--){
		if (CheckDiagonalBL(puzzle,r,c,string,pc) == 1){
		printf("%s is found diagonal backward left at gamePuzzle[%c][%c]\n",string,DisplaySearchWordsHex(r+1),DisplaySearchWordsHex(c+1));
		return 1;
		}
	}

}
return 0;
}

// checks diagonal forward to the right
static int CheckDiagonalFR(char puzzle[row][col], int ar, int ac, char *string, int pc){
int cplus = 0;
//int returnValue = 0;

if (((ar + pc) > row) ||((ac + pc) > col)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar + cplus][ac + cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}
//return returnValue;
return 1;
}

//checks diagonal backwards to the left
static int CheckDiagonalBL(char puzzle[row][col], int ar, int ac, char *string, int pc){
int cplus = 0;
//int returnValue = 0;

// if word is > 7 pc - ar 
// if word is <=7 ar - pc
// if word is > 7 pc - ac 
// if word is <=7 ac - pc

if (pc > ar ){
if (((pc - ar) < 0) || ((pc - ac) <  0)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar - cplus][ac - cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}
}
else{
if (((ar - pc) < 0) || ((ac - pc) <  0)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar - cplus][ac - cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}
}
//return returnValue;
return 1;
}

// checks diagonal forward to the left 
static int CheckDiagonalFL(char puzzle[row][col], int ar, int ac, char *string, int pc){
int cplus = 0;
//int returnValue = 0;

// if word is > 7 pc - ac 
// if word is <=7 ac - pc
if (pc > ar){
if (((ar + pc) > row) ||((pc - ac) > 0)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar + cplus][ac - cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}
}
else{
if (((ar + pc) > row) ||((ac - pc) < 0)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar + cplus][ac - cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}
}
//return returnValue;
return 1;
}

//checks diagonal backward to the right
static int CheckDiagonalBR(char puzzle[row][col], int ar, int ac, char *string, int pc){
int cplus = 0;
//int returnValue = 0;

// if word is > 7 pc - ar 
// if word is <=7 ar - pc
if (pc > (ar)){
if (((pc - ar) < 0) || ((pc + ac) >  col)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar - cplus][ac + cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}
}
else{
if (((ar - pc) < 0) || ((pc + ac) >  col)){
//returnValue = 0;
return 0;
}
else{
//returnValue = 1;
	for (cplus = 0; cplus < pc ; cplus++){
		if (puzzle[ar - cplus][ac + cplus] != *(string+cplus)){
		//returnValue = 0;
		return 0;
		}
	} 
}

}
//return returnValue;
return 1;
}
















