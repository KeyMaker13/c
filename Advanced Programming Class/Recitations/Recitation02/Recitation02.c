#include <stdio.h>
#include "genlib.h"
#include "simpio.h"

//constants
#define sentinel -1

/*prototypes*/
int GetValue(void); 
void ValueSize(int size);
int UserExit(void);
void SingleDigit(int size);
void Tens(int size);
void Teens(int size);
void Hundred(int size);
void Thousand(int size);
void TenThousand(int size);
void TeenThousand(int size);
void HundredThousand(int size);


main(){
printf("Enter a number and I will word it for you.\nOr enter -1 to quit.\n");

int v,q,b;
b = 1;
	while(b){
	v = GetValue();
	ValueSize(v);
	printf("\n");
	//q = UserExit();
		if (v == sentinel){
		b = 0;
		}
	}
}

int UserExit(){
int r;
printf("\nWant to quit? Enter 0\nIf not enter any other number\n");
r = GetInteger();
return r;
}

//gets a value and checks to see if its within range
int GetValue(){
int b = 1;
int num = 0;
printf("The value must be between 1 and 999,999\n ");

	while(b){
	num = GetInteger();
		if(num < 0 || num > 1,000,000){
		printf("\nNumber must be between 1 and 999,999\nEnter correct range please\n");
		num = GetInteger();
		}
		else{
		b = 0;
		}
}	
	
return num;
}

// checks value of number to see what method to call
void ValueSize(int size){
	if (size == 0){
	printf("zero ");
	}

	if (size>0 && size <=99){
	//tens
	Tens(size);
	}

	if (size>99 && size <=999){ 
	//hundreds
	Hundred(size);
	}

	if (size >999 && size <=9999){
	//thousands
	Thousand(size);
	}

	if (size >9999 && size <=99999 ){
		if (size >10999 && size < 19999){
		TeenThousand(size);	
		}
		else{
		//ten thousands
		TenThousand(size);
		}
	}
	
	if (size > 99999 && size <=999999){
	//hundred thousands
	HundredThousand(size);
	}
}

// prints out a single digit
void SingleDigit(int size){
	if (size == 1){
	printf("one ");
	}
	if (size == 2){
	printf("two ");
	}
	if (size == 3){
	printf("three ");
	}
	if (size == 4){
	printf("four ");
	}
	if (size == 5){
	printf("five ");
	}
	if (size == 6){
	printf("six ");
	}
	if (size == 7){
	printf("seven ");
	}
	if (size == 8){
	printf("eight ");
	}
	if (size == 9){
	printf("nine ");
	}
	if (size == 10){
	printf("ten ");
	}
}

// prints out tens
void Tens(int size){
int rp;
	
	if (size >0 && size <= 10){
	SingleDigit(size);
	}

	if (size >10 && size <=19){
	Teens(size);
	}

	if (size >19 && size <= 29){
		if (size%20 == 0){
		printf("twenty ");
		}
		else{
		printf("twenty-");
		rp = size%20;
		SingleDigit(rp);
		}
	}

	if (size > 29 && size <= 39){
		if (size%30 == 0){
		printf("thirty ");
		}
		else{
		printf("thirty-");
		rp = size%30;
		SingleDigit(rp);
		}
	}

	if (size > 39 && size <=49){
		if (size%40 == 0){
		printf("fourty ");
		}
		else{
		printf("fourty-");
		rp = size%40;
		SingleDigit(rp);
		}
	}

	if (size > 49 && size <= 59){
		if (size%50 == 0){
		printf("fifty ");
		}
		else{
		printf("fifty-");
		rp = size%50;
		SingleDigit(rp);
		}
	}

	if (size > 59 && size <= 69){
		if (size%60 == 0){
		printf("sixty ");
		}
		else{
		printf("sixty-");
		rp = size%60;
		SingleDigit(rp);
		}
	}

	if (size > 69 && size <= 79){
		if (size%70 == 0){
		printf("seventy ");
		}
		else{
		printf("seventy-");
		rp = size%70;
		SingleDigit(rp);
		}
	}

	if (size > 79 && size <= 89){
		if (size%80 == 0){
		printf("eighty ");
		}
		else{
		printf("eighty-");
		rp = size%80;
		SingleDigit(rp);
		}
	}

	if (size > 89 && size <= 99){
		if (size%90 == 0){
		printf("ninety ");
		}
		else{
		printf("ninety-");
		rp = size%90;
		SingleDigit(rp);
		}
	}
}

// prints out the teens
void Teens(int size){
	if (size == 11){
	printf("eleven ");
	}
	if (size == 12){
	printf("twelve ");
	}
	if (size == 13){
	printf("thirteen ");
	}
	if (size == 14){
	printf("fourteen ");
	}
	if (size == 15){
	printf("fifteen ");
	}
	if (size == 16){
	printf("sixteen ");
	}
	if (size == 17){
	printf("seventeen ");
	}
	if (size == 18){
	printf("eighteen ");
	}
	if (size == 19){
	printf("nineteen ");
	}
}

// prints out hundreds
void Hundred(int size){
int rp;	
	if (size >99 && size <= 199){
		if(size%100 == 0){	
		printf("one hundred ");
		}
		else{
		rp= size%100;
		printf("one hundred ");
		Tens(rp); 
		}
	}

	if (size >199 && size <=299){
		if(size%200 == 0){	
		printf("two hundred ");
		}
		else{
		rp= size%200;
		printf("two hundred ");
		Tens(rp); 
		}
	}

	if (size >299 && size <= 399){
		if(size%300 == 0){	
		printf("three hundred ");
		}
		else{
		rp= size%300;
		printf("three hundred ");
		Tens(rp); 
		}
	}

	if (size > 399 && size <= 499){
		if(size%400 == 0){	
		printf("four hundred ");
		}
		else{
		rp= size%400;
		printf("four hundred ");
		Tens(rp); 
		}
	}

	if (size > 499 && size <=599){
		if(size%500 == 0){	
		printf("five hundred ");
		}
		else{
		rp= size%500;
		printf("five hundred ");
		Tens(rp); 
		}
	}	

	if (size > 599 && size <= 699){
		if(size%600 == 0){	
		printf("six hundred ");
		}
		else{
		rp= size%600;
		printf("six hundred ");
		Tens(rp); 
		}
	}

	if (size > 699 && size <= 799){
		if(size%700 == 0){	
		printf("seven hundred ");
		}
		else{
		rp= size%700;
		printf("seven hundred ");
		Tens(rp); 
		}
	}

	if (size > 799 && size <= 899){
		if(size%800 == 0){	
		printf("eight hundred ");
		}
		else{
		rp= size%800;
		printf("eight hundred ");
		Tens(rp); 
		}
	}

	if (size > 899 && size <= 999){
		if(size%900 == 0){	
		printf("nine hundred ");
		}
		else{
		rp= size%900;
		printf("nine hundred ");
		Tens(rp); 
		}
	}
}

//prints out thousands
void Thousand(int size){
int rp;	
	if (size >999 && size <= 1999){
		if(size%1000 == 0){	
		printf("one thousand ");
		}
		else{
		rp= size%1000;
		printf("one thousand ");
		ValueSize(rp);		
		//Hundred(rp); 
		}
	}

	if (size >1999 && size <=2999){
		if(size%2000 == 0){	
		printf("two thousand ");
		}
		else{
		rp= size%2000;
		printf("two thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}

	if (size >2999 && size <= 3999){
		if(size%3000 == 0){	
		printf("three thousand ");
		}
		else{
		rp= size%3000;
		printf("three thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}

	if (size > 3999 && size <= 4999){
		if(size%4000 == 0){	
		printf("four thousand ");
		}
		else{
		rp= size%4000;
		printf("four thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}

	if (size > 4999 && size <=5999){
		if(size%5000 == 0){	
		printf("five thousand ");
		}
		else{
		rp= size%500;
		printf("five thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}	

	if (size > 5999 && size <= 6999){
		if(size%6000 == 0){	
		printf("six thousand ");
		}
		else{
		rp= size%6000;
		printf("six thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}

	if (size > 6999 && size <= 7999){
		if(size%7000 == 0){	
		printf("seven thousand ");
		}
		else{
		rp= size%7000;
		printf("seven thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}

	if (size > 7999 && size <= 8999){
		if(size%8000 == 0){	
		printf("eight thousand ");
		}
		else{
		rp= size%8000;
		printf("eight thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}

	if (size > 8999 && size <= 9999){
		if(size%9000 == 0){	
		printf("nine hundred ");
		}
		else{
		rp= size%9000;
		printf("nine thousand ");
		ValueSize(rp);
//		Hundred(rp); 
		}
	}
}

void TeenThousand(int size){
int rp;	
	if (size >10999 && size <= 11999){
		if(size%11000 == 0){	
		printf("eleven thousand ");
		}
		else{
		rp= size%11000;
		printf("eleven thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size >11999 && size <=12999){
		if(size%12000 == 0){	
		printf("twelve thousand ");
		}
		else{
		rp= size%12000;
		printf("twelve thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size >12999 && size <= 13999){
		if(size%13000 == 0){	
		printf("thirteen thousand ");
		}
		else{
		rp= size%13000;
		printf("thirteen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 13999 && size <= 14999){
		if(size%14000 == 0){	
		printf("fourteen thousand ");
		}
		else{
		rp= size%14000;
		printf("fourteen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 14999 && size <=15999){
		if(size%15000 == 0){	
		printf("fifteen thousand ");
		}
		else{
		rp= size%15000;
		printf("fifteen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}	

	if (size > 15999 && size <= 16999){
		if(size%16000 == 0){	
		printf("sixteen thousand ");
		}
		else{
		rp= size%16000;
		printf("sixteen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 16999 && size <= 17999){
		if(size%17000 == 0){	
		printf("seventeen thousand ");
		}
		else{
		rp= size%17000;
		printf("seventeen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 17999 && size <= 18999){
		if(size%18000 == 0){	
		printf("eighteen thousand ");
		}
		else{
		rp= size%18000;
		printf("eighteen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 18999 && size <= 19999){
		if(size%19000 == 0){	
		printf("nineteen thousand ");
		}
		else{
		rp= size%19000;
		printf("nineteen thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}
}

//prints out ten thousands
void TenThousand(int size){
int rp;	
	if (size >9999 && size <= 19999){
		if(size%10000 == 0){	
		printf("ten thousand ");
		}
		else{
		rp= size%10000;
		printf("ten thousand ");
				

		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size >19999 && size <=29999){
		if(size%20000 == 0){	
		printf("twenty thousand ");
		}
		else{
		rp= size%20000;
		printf("twenty thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size >29999 && size <= 39999){
		if(size%30000 == 0){	
		printf("thirty thousand ");
		}
		else{
		rp= size%30000;
		printf("thirty thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 39999 && size <= 49999){
		if(size%40000 == 0){	
		printf("fourty thousand ");
		}
		else{
		rp= size%40000;
		printf("fourty thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 49999 && size <=59999){
		if(size%50000 == 0){	
		printf("fifty thousand ");
		}
		else{
		rp= size%50000;
		printf("fifty thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}	

	if (size > 59999 && size <= 69999){
		if(size%60000 == 0){	
		printf("sixty thousand ");
		}
		else{
		rp= size%60000;
		printf("sixty thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 69999 && size <= 79999){
		if(size%70000 == 0){	
		printf("seventy thousand ");
		}
		else{
		rp= size%70000;
		printf("seventy thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 79999 && size <= 89999){
		if(size%80000 == 0){	
		printf("eighty thousand ");
		}
		else{
		rp= size%80000;
		printf("eighty thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}

	if (size > 89999 && size <= 99999){
		if(size%90000 == 0){	
		printf("ninety thousand ");
		}
		else{
		rp= size%90000;
		printf("ninety thousand ");
		ValueSize(rp);
//		Thousand(rp); 
		}
	}
}

// prints out hundred thousands
void HundredThousand(int size){
int rp;	
	if (size >99999 && size <= 199999){
		if(size%100000 == 0){	
		printf("one hundred thousand ");
		}
		else{
		rp= size%100000;
		printf("one hundred thousand ");
		ValueSize(rp);
		//TenThousand(rp); 
		}
	}

	if (size >199999 && size <=299999){
		if(size%200000 == 0){	
		printf("two hundred thousand ");
		}
		else{
		rp= size%200000;
		printf("two hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}

	if (size >299999 && size <= 399999){
		if(size%300000 == 0){	
		printf("three hundred thousand ");
		}
		else{
		rp= size%300000;
		printf("three hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}

	if (size > 399999 && size <= 499999){
		if(size%400000 == 0){	
		printf("four hundred thousand ");
		}
		else{
		rp= size%400000;
		printf("four hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}

	if (size > 499999 && size <=599999){
		if(size%500000 == 0){	
		printf("five hundred thousand ");
		}
		else{
		rp= size%500000;
		printf("five hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}	

	if (size > 599999 && size <= 699999){
		if(size%600000 == 0){	
		printf("six hundred thousand ");
		}
		else{
		rp= size%600000;
		printf("six hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}

	if (size > 699999 && size <= 799999){
		if(size%700000 == 0){	
		printf("seven hundred thousand ");
		}
		else{
		rp= size%700000;
		printf("seven hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}

	if (size > 799999 && size <= 899999){
		if(size%800000 == 0){	
		printf("eight hundred thousand ");
		}
		else{
		rp= size%800000;
		printf("eight hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}

	if (size > 899999 && size <= 999999){
		if(size%900000 == 0){	
		printf("nine hundred thousand ");
		}
		else{
		rp= size%900000;
		printf("nine hundred thousand ");
		ValueSize(rp);
//		TenThousand(rp); 
		}
	}
}
















