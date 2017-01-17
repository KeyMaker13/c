#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
//just incase
#include <math.h>
//never used it
#include "random.h"

//constants
#define row 50
#define col 30
//to figure out how to cycle through arrays
#define one 1
#define two 2
#define three 3

//prototypes
void UserInstruct(void);
void InitStartArray(int a[row][col], int r, int c);
void PrintArray(int p[row][col], int r, int c);
void SetLife(int a[row][col]);
int AskGeneration(void);
int Game(int g,int *gf, int *sp, int a[row][col], int b[row][col], int c[row][col]);
int CheckNeighbor(int check[row][col], int r, int c);
void TransferArray(int a[row][col], int b[row][col]);
//void Birth(int birth[row][col], int r, int c);
int CheckArray(int c1[row][col], int c2[row][col], int r, int c);

//main 
main(){
// 3 starting arrays
int a[row][col], b[row][col], c[row][col];

//telling user what to do
UserInstruct();

//make first array is all zero
InitStartArray(a,row,col); 

//asking user to set cells with life in them
SetLife(a); 

//printing array
printf("The life you have made in the grid\n");
PrintArray(a,row,col);

//ask user for number of generations
int generations = AskGeneration();

//play game
int genFinal;
int samePattern;
int numberOfGenerations = Game(generations, &genFinal,&samePattern,a,b,c);
 
printf("After %d generations this much life remaineds\n", numberOfGenerations);
if (samePattern){
printf("Steady state was reached\n");
}
//print out final array
 if (genFinal == one){
	PrintArray(a,row,col);
 }
 if (genFinal == two){
	PrintArray(b,row,col);
 }
 if (genFinal == three){
	PrintArray(c,row,col);
 } 
 

}

//tell user insructions
void UserInstruct(void){
printf("This is the game of life\n");
printf("Created in a 50 x 30 grid\n");
printf("I will ask you to fill the grid with life\n");
printf("\n");
}

//setting everything to 0
void InitStartArray(int a[row][col], int r, int c){
int i;
int j;

for (i=0; i < r; i++){
	for (j=0 ; j < c; j++)
	a[i][j] = 0;	
}	

}

// set life method
void SetLife(int a[row][col]){
printf("You will enter i and j\n");
printf("i for row, j for column\n");
printf("A[i][j] is the position of where an organism will be filled\n");
printf("instead of typing 0,0 for the top left of the array, you can type 1,1\n");
printf("I subtracted 1 from your input so you can treat 1,1 as the start of the array\n");
printf("enter -1, and -1 to stop\n");
printf("if i or j are not with in range you will have to enter the values again\n");

int i, j, s=1;
int ir, jr;
while (s){
printf("Enter i : ");
i = GetInteger() - 1;
ir = 1;
printf("Enter j : ");
j = GetInteger() - 1;
jr = 1;
if (i + j == -4){
	s = 0;
	ir = 0;
	jr = 0;
}
if (i < 0 || i > row){
printf("i is not within range\n");
ir = 0;
}
if (j < 0 || j > col){
printf("j is not within range\n");
jr = 0;
}
if (ir&&jr){
a[i][j] = 1;
}
}

}

//play game
//it was hard for the part of an oscillation of two alternating patterns is reached
// and I couldnt figure out the logic to put that in my code
int Game(int g, int *gf, int *sp, int a[row][col], int b[row][col], int c[row][col]){
int s = 1;
int curGen = 0;

while (s){
//if gen is 0 stop game
if (g == curGen ){
s =0;
}
else{
//need to figure out how to switch arrays in parameters until gen count is out
//and how to switch them into TransferArray method
if (curGen%3 ==1 || curGen%3 == 0){
TransferArray(a,b);
*gf = two;
// check a b to see if the same
if (CheckArray(a,b,row,col) == 1){
	*sp = 1;
	s= 0;
	}
// check b c to see if the same 
if (CheckArray(b,c,row,col) == 1){
	*sp = 1;
	s= 0;
	}
}
else if (curGen%3 == 2){
TransferArray(b,c);
*gf = three;
// check b c
if (CheckArray(b,c,row,col) == 1){
	*sp = 1;
	s= 0;
	}
// check a c
if (CheckArray(a,c,row,col) == 1){
	*sp = 1;
	s= 0;
	}
}
else{
TransferArray(c,a);
*gf = one;
// check a c
if (CheckArray(a,c,row,col) == 1){
	*sp = 1;
	s= 0;
	}
// check a b
if (CheckArray(a,b,row,col) == 1){
	*sp = 1;
	s= 0;
	}
}
curGen++;
}

}
return curGen;
}

// checks surrounding cells to see if they contain a 1 or zero and returns the count number 
int CheckNeighbor(int check[row][col], int r, int c){
int count = 0;

// assuming that check[i][j] is 1
	if (r-1 >= 0 && c-1 >= 0){
		if (check[r-1][c-1] == 1){
			count++;
		}
	}
	if (r-1 >= 0){
		if (check[r-1][c] == 1){
			count++;
		}
	}
	if (r-1 >= 0  && c+1 < col){
		if (check[r-1][c+1] == 1){
			count++;
		}
	}	
	if (c-1 >= 0){
		if (check[r][c-1] == 1){
			count++;
		}
	}	
	if (c+1 < col){
		if (check[r][c+1] == 1){
			count++;
		}
	}	
	if (r+1 < row && c-1 >= 0){
		if (check[r+1][c-1] == 1){
			count++;
		}
	}
	if (r+1 < row){
		if (check[r+1][c] == 1){
			count++;
		}
	}
	if (r+1 < row && c+1 < col){
		if (check[r+1][c+1] == 1){
			count++;
		}
	}
return count;
}

// checks arrays to see if they are equal
int CheckArray(int c1[row][col], int c2[row][col], int r, int c){
int i,j;

for (i = 0; i < r; i++){
	for (j = 0; j < c; j++){
		if (c1[i][j] != c2[i][j]){
		return 0;
		}
	}

}
return 1;
}


// maybe need to cut down the parameters down two only two arrays
void TransferArray(int a[row][col], int b[row][col]){
int i;
int j;

// need to set up a way to switch from array a to b to c and back to b then a until generation count is out
// and return the proper array to copy to
// maybe use a pointer to point to array 

for (i = 0; i < row; i++){
	for (j = 0; j < col; j++){
		if(a[i][j] == 1){
			if ( (CheckNeighbor(a,i,j) != 2) && (CheckNeighbor(a,i,j) != 3)){
				//set to zero
				b[i][j] = 0;
				}
			else{
				//copy and leave alone
				b[i][j] = 1;
				}
		}
		if (a[i][j] == 0){
			if (CheckNeighbor(a,i,j) == 3){
				// make new cell
				b[i][j] = 1;
				//Birth(b,i,j);
				}
				else{
				b[i][j] = 0;
				}
		}
	}
}	 

}
/*
void Birth(int birth[row][col], int r, int c){
// need to run checks for neighbor cells and be sure that they are not 1 then select random area to fill with birth

int b[] = {0 ,0, 0, 0, 0, 0, 0, 0};

	if (r-1 >= 0 && c-1 >= 0){
		if (birth[r-1][c-1] == 0) //0
			b[0] = 1;
	}
	if (r-1 >= 0){
		if (birth[r-1][c] == 0) //1
			b[1] = 1;
	}
	if (r-1 >= 0  && c+1 < col){
		if (birth[r-1][c+1] == 0) //2
			b[2] = 1;
	}	
	if (c-1 >= 0){
		if (birth[r][c-1] == 0) //3
			b[3] = 1;
	}	
	if (c+1 < col){
		if (birth[r][c+1] == 0) //4
			b[4] = 1;
	}	
	if (r+1 < row && c-1 >= 0){
		if (birth[r+1][c-1] == 0) //5
			b[5] = 1;
	}
	if (r+1 < row){
		if (birth[r+1][c] == 0) //6
			b[6] = 1;
	}
	if (r+1 < row && c+1 < col){
		if (birth[r+1][c+1] == 0) //7
			b[7] = 1;
	}

//maybe take away random and just put in next available array	
//int s = 1;
//int rand , i;
int p, i = 1;
while (TRUE && i < 8){
//rand = RandomInteger(1,8);
//--rand;
	if (b[i] == 1){
		p = i;
		break;
		}
		else{
		i++;
		}
	}
// switch case to see what cell will have life in it randomly
switch (p){
case 0 : birth[r-1][c-1] = 1; break;
case 1 : birth[r-1][c] = 1; break;
case 2 : birth[r-1][c+1] = 1; break;
case 3 : birth[r][c-1] = 1; break;
case 4 : birth[r][c+1] = 1; break;
case 5 : birth[r+1][c-1] = 1; break;
case 6 : birth[r+1][c] = 1; break;
case 7 : birth[r+1][c+1] = 1; break;
}
}
*/

// asking user for number of generations to play and returning the number
int AskGeneration(void){
printf("How many generations do you want to play?\n");
int r = GetInteger();
return r;
}

//test array i made but could not get it to work to display if all the array was filled with zeros
void PrintArray(int p[row][col], int r, int c){
int i,j;
	for (i = 0 ; i < r ; i++){
		for (j = 0 ; j < c; j++){
			if (p[i][j] == 0){
			printf(" ");
			}
			else{
			printf("x");
			//printf("%d", p[i][j]);
			}
		}
	printf("\n");
	}
}


