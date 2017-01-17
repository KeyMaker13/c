

/*This program prints a calendar for a year specified. The user enters a
     year for the calendar and the programs automatically prints the calendar
     in text format.
     The codes are: day_code (0 = Sun, 1 = Mon, etc.)
                    leap_year (0 = no leap year, 1 = leap year)   */
#include <stdio.h>
#include <stdlib.h>     
#include "genlib.h"
#include "simpio.h"

#define Sentinel 0  
#define TRUE 1
#define FALSE 0

int get_day_code (int year);
int get_leap_year (int year);
void print_calendar (int year, int day_code, int leap_year);
int get_year (void);
void UserPrompt(void);
int UserChoice(void);
int OptionOneCalc(int year, int month, int day);
static void DayName(int dayFinal);
int UserExit(void);
static int OptionOne(void);
static int OptionTwo(void);
int OptionOneReturnCorrectMonth(int month);

main()
{
/*start while */
while(TRUE){
/*Prompting User with Instructions*/
UserPrompt();

/*Asking User for option of choice*/
int choice = UserChoice();

/*Choice Selection*/
if (choice == 1)
{
OptionOne();
}

if (choice == 2)
{
OptionTwo();
}

int e = UserExit();
if (e == Sentinel) break;
}

/* end while */
}

static int OptionOne(){
int y,m,d;
printf("Enter year ");
y = GetInteger();
printf("Enter Month ");
m = GetInteger();
printf("Enter day ");
d = GetInteger();
int display = OptionOneCalc(y,m,d);
DayName(display);
return 0;
}

static int OptionTwo(){
 int year, day_code, leap_year; 

int b = 1;   
  while(b){
   year = get_year();
if (year < 1750){
printf("Year must be greater than 1751\n");
}
else{
b = 0;
}                           
}   
day_code = get_day_code (year);
   leap_year = get_leap_year (year);
   print_calendar(year, day_code, leap_year);   
return 0;
}

/*user exit choice */
int UserExit(){
printf("\nIf you want to exit press 0\nIf you want to continue enter 1 any other number\nI will keep on asking because magic can last forever\n");
int exit = GetInteger();
return exit;
}

/*Asking user to type in option 1 or option 2 */
void UserPrompt(){
printf("Hi I am the magic calendar maker\n");
printf("I will give you two options\n");
printf("Press 1 and you will enter a specific date in time and I will tell you on what day it lands\n");
printf("Press 2 and you will enter a specific year and I will display that yearly calendar for you\n");
printf("And your option is ?\n");
}

/* ask user for choice option*/
int UserChoice(void)
{
	int choice;
	choice = GetInteger();
	printf("You have chosen %d \n", choice);
	return choice;
}

/*This is option one for the assignment I used a formula from the internet to find the day*/ 
/*It does not return Wednesday for the 2/15/2006 date*/

int OptionOneCalc(int year, int month, int day) { 
/* I AM NO MATH GOD :'( (extreme sadness and failures) */

int y = year;
int m = month;
int d = day;
int final;

int t = OptionOneReturnCorrectMonth(m-1);
/* static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4}; */


y -=m<3;
return (y + y/4 - y/100 + y/400 + t + d) % 7; 


/*this one prints out thursday for 2/15/2006*/
/*
int k = day;
int m = OptionOneReturnCorrectMonth(month);
int century = year/100;
int yYear = year - century*100;
int final = ((k + (int) floor(2.6*m - 0.2) - 2*century + yYear + (int) floor(yYear/4) + (int) floor(century/4))%7);
*/

/* this one printed out tuesday for 2/15/2006
int century = year/100; 
int s1 = century/4 - 2*century*19 -1; 
int s2 = 5*year/4; 
int s3 = 26*(month + 1)/10;
int s4 = day; 
int s5 = s1 + s2 + s3 + s4; 
int final = s5%7; 
*/

/*
return final;
*/
}

int OptionOneReturnCorrectMonth(int month){
if (month == 0){
return 0;
}
if (month == 1){
return 3;
}
if (month == 2){
return 2;
}
if (month == 3){
return 5;
}
if (month == 4){
return 0;
}
if (month == 5){
return 3;
}
if (month == 6){
return 5;
}
if (month == 7){
return 1;
}
if (month == 8){
return 4;
}
if (month == 9){
return 6;
}
if (month == 10){
return 2;
}
if (month == 11){
return 4;
}
}

/* returns the day name of the week for option1 */
static void DayName(int dayFinal){
	switch(dayFinal){
	case 0 :printf ("The day is Sunday\n");break;
	case 1 :printf ("The day is Monday\n");break;
	case 2 :printf ("The day is Tuesday\n");break;
	case 3 :printf ("The day is Wednesday\n");break;
	case 4 :printf ("The day is Thursday\n");break;
	case 5 :printf ("The day is Friday\n");break;
	case 6 :printf ("The day is Saturday\n");break;
	default:printf ("No\n");
	}
}
     
int get_year (void)
{
int year;
printf ("Enter a year: ");
scanf ("%d", &year);
return year;
}             
int get_day_code (int year)
{
int day_code;
int x1, x2, x3;
        x1 = (year - 1.)/ 4.0;
        x2 = (year - 1.)/ 100.;
        x3 = (year - 1.)/ 400.;
day_code = (year + x1 - x2 + x3) %7;
return day_code;
}             
int get_leap_year (int year)
{
        
//if((year% 4) == 0 );
if(year% 4==0 && year%100 != 0 || year%400==0)
   return TRUE;
   else return FALSE;   
                
}
void print_calendar (int year, int day_code, int leap_year) //function header
{
        int  days_in_month,     /* number of days in month currently 
                                                     being printed */
         day,       /* counter for day of month */
         month;     /* month = 1 is Jan, month = 2 is Feb, etc. */
     printf ("                   %d", year);
     for ( month = 1; month <= 12; month++ ) {
          switch ( month ) { /* print name and set days_in_month */
          case 1:
               printf("\n\nJanuary" );
               days_in_month = 31;
               break;
          case 2:
               printf("\n\nFebruary" );
               days_in_month = leap_year ? 29 : 28;
               break;
          case 3:
               printf("\n\nMarch" );
               days_in_month = 31;
               break;
          case 4:
               printf("\n\nApril" );
               days_in_month = 30;
               break;
          case 5:
               printf("\n\nMay" );
               days_in_month = 31;
               break;
          case 6:
               printf("\n\nJune" );
               days_in_month = 30;
               break;
          case 7:
               printf("\n\nJuly" );
               days_in_month = 31;
               break;
          case 8:
               printf("\n\nAugust" );
               days_in_month = 31;
               break;
          case 9:
               printf("\n\nSeptember" );
               days_in_month = 30;
               break;
          case 10:
               printf("\n\nOctober" );
               days_in_month = 31;
               break;
          case 11:
               printf("\n\nNovember" );
               days_in_month = 30;
               break;
          case 12:
               printf("\n\nDecember" );
               days_in_month = 31;
               break;
          }
          printf("\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
          /* advance printer to correct position for first date */
          for ( day = 1; day <= 1 + day_code * 5; day++ )
               printf(" " );
          /* print the dates for one month */
          for ( day = 1; day <= days_in_month; day++ ) {
               printf("%2d", day );
               if ( ( day + day_code ) % 7 > 0 ) /* before Sat? */
                    /* move to next day in same week */
                    printf("   " );
               else  /* skip to next line to start with Sun */
                    printf("\n " );
          }
          /* set day_code for next month to begin */
          day_code = ( day_code + days_in_month ) % 7;
     }
}





