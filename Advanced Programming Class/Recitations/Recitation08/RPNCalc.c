#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "genlib.h"
#include "stack.h"


//This is the prompt to tell the user what is going on
void Prompt(){
	printf("This is a RPN Calculator\n");
	printf("You will enter a Reverse Polish Notation equation like the example bellow\n");
	printf("50.0 (enter) 1.5 (x) 3.8 (enter) 2.0 (/) (+)\n");
	printf("If you enter incorrect values you can try again\n");
	char minus = '-';
	printf("The only correct operators are + %c / *\n",minus);
	printf("I will calculate the equation you entered\n");
	printf("press q any time to quit\n");
}

//checks the character to make sure it is a valid operator sign
int isOperator(char check){
   switch (check){
      case '*' : return 1;
      case '/' : return 1;
      case '+' : return 1;
      case '-' : return 1;
      case 'x' : return 1;
      default  : return 0;
   }
/* return 0; */  /* your switch case will handle returns, don't need a return 0 here. */
}

// checks to see if the value of the string inputed is correct
int IsValidChar(char check){
// 0-9 isdigit(check)
// (* + - /)  isOperator(check)
	if (!isdigit(check) && !isOperator(check) && check != '.')
		return 0;
	return 1;
}

// run a loop through the whole string and see if the characters are
// valid 
int CheckEntry(char *str){
   char *p;
   p = str;
   while(*p)
      if(!IsValidChar(*p))
         return 1;
      else
         p++;
   return 0;
}

double OperandCase(char o, double lhs, double rhs){
   switch (o){
      case '+' : return (lhs + rhs);
      case '-' : return (lhs - rhs);
      case '*' : return (lhs * rhs);
      case '/' : return (lhs / rhs);
      case 'x' : return (lhs * rhs);
      default: printf("Hacker\n"); /* shouldn't you just put return 0.0 here? Unless this is for something else */
   }
   return 0.0;
}

CalcRPN(char *str, stackADT stack){
   double lhs, rhs, result, pInput;
   char o = str[0], *p;
   if(isdigit(o)){
      p = str;
      //pInput = malloc(sizeof(double));
      pInput = atof(p);
      //Push(stack,(stackElementT)StringToReal(in)); works
      //Push(stack,(stackElementT)atof(in)); does not work
      Push(stack, (stackElementT)(int)pInput);
   }
   if(isOperator(o)){
      rhs =(int) Pop(stack);
      lhs = (int) Pop(stack);
      result = OperandCase(o,lhs,rhs);
      printf("%d\n", (int)result);
      Push(stack,(stackElementT)(int)result);
   }
}

static void DisplayStack(stackADT stack)
{
   int i, depth;
   printf("Stack: ");
   depth = StackDepth(stack);
   if (depth == 0)
      printf("empty\n");
   else {
      for (i = depth - 1; i >= 0; i--) {
         if (i < depth - 1)
            printf(", ");
         printf("%d",(int) GetStackElement(stack, i));
      }
      printf("\n");
   }
}

// checks to see if the user entered a q
int Exit(char *q){
   char *p;
   p=q;
   while(*p)
      if(*p == 'q' || *p == 'Q')
         return 1;
      else
         p++;
   return 0;
}

//This is the main engine that runs the program
void Calculator(){

// doing a while loop with a integer variable
// the user will exit the program with ExitPrompt

   int run = 1;
   double lhs, rhs, result, pInput;
   char *rpn, *p, o;
   stackADT RPNStack, ptr;
   RPNStack = NewStack();
   ptr = RPNStack;
   printf("Begin to enter your RPN equation: ");
   while(run){
      printf("> ");
/*    rpn = malloc(10*sizeof(char)) */    /* don't need this because rpn points to whatever GetLine() is */
      rpn = (char *) GetLine();
      o = *rpn;    /* this is the same as rpn[0]. Ask me if you aren't sure why. */
      p = rpn;
      // if it contains a q then exit loop

/*
 * You shouldn't have to change run to 0,
 * when you have it break, the while loop
 * breaks, if you set run = 0 and use that
 * as the break method it will do everything
 * else and then when the loop restarts it
 * will break. I removed run = 0, ie, and your i
 * variables because that wasn't needed either.
 * Also changed your Exit function to lose the
 * second parameter that took an int.
 */
      if(Exit(p)){
      /* free everything when you exit */
         FreeStack(RPNStack);
         free(rpn);
         break;
      // if it doesn't contains the correct characters
      }
      if (CheckEntry(p)){
         printf("This entry does not contain a valid character\n");
      } else {
         // calculate rpn
            // display rpn
         //CalcRPN(rpn,RPNStack);
         //DisplayStack(RPNStack);
         //printf("\n");
/*       if(isdigit(rpn[0])){ */
         if(isdigit(o)){
/*          in = rpn */                            /* you can get rid of this because you don't need it */
            pInput = atof(p);
/*          pInput = atoi(p); */                   /* This one converts it to an int just in case you dont know */
            //Push(stack,(stackElementT)StringToReal(in)); works
            //Push(stack,(stackElementT)atof(in)); does not work
            Push(ptr, (stackElementT)(int)pInput);
         }
         if(isOperator(o)){
            rhs =(int)Pop(ptr);
            //free(pInput[i]);
            lhs = (int)Pop(ptr);
            result = OperandCase(o,lhs,rhs);
            printf("%d\n", (int)result);
            Push(ptr,(stackElementT)(int)result);
         }
      }
/*
 * If you don't free rpn after each GetLine(), the memory allocated for it is lost
 * everytime rpn does GetLine() again. Therefore, you have to free it after each use.
 */
   free(rpn);
   }
}

int main(){
	Prompt();
	Calculator();
	return 0;
}
