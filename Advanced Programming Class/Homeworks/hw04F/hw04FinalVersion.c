/*
I took over another employee.c file and I looked around and messed with it.
I figured out that I simply was forgeting that the string and the scanf or GetLine() function works different. 
So I convereted everything to a char pointer

then i took out the initializer method
I put the initializer method in the getpayroll method and let it run.
this time it worked i figured it out


NEED TO BE AWARE OF YOUR DATA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"


#define MaxEmployees 100



typedef struct {
    //char *name;
    //char *title;
    //char *ssnum;
	string name;
	string title;
	string ssnum;
    double salary;
    int withholding;
} employeeRecordT;



typedef struct {
    //char *name;
    //char *title;
    //char *ssnum;
	string name;
	string title;
	string ssnum;
    double salary;
    int withholding;
} *employeeT;



typedef struct {
    employeeT *employees;
    int nEmployees;
} *payrollT;


 //static char n[30];
 //static char t[30];
 //static char ss[30];
 static string n;
 static string t;
 static string ss;
 static double sa;
 static int w;
 
static employeeRecordT staff[MaxEmployees];
static int nEmployees;

//static void InitEmployeeTable(int numEmp);
//static payrollT GetPayroll(employeeRecordT s[], int nEmployees);
static payrollT GetPayroll(int nEmployees);
static void ListEmployees(payrollT payroll);

WeekPayroll(payrollT payroll)
{
	printf("\nWeekly Payroll\n");
	printf("Name\t\tGross - Tax = Net \n");
	printf("----------------------------------------------------------\n");
	int i;
	double tax, net;
    for (i = 0; i < payroll->nEmployees; i++) {
		tax = (((payroll->employees[i]->salary)-(payroll->employees[i]->withholding))*0.25);
		net = payroll->employees[i]->salary - tax;
        printf("%s\t\t%0.2lf - %0.2lf = %0.2lf\n", payroll->employees[i]->name, payroll->employees[i]->salary,tax,net);
    }
}

FreePayroll(int numEmp, payrollT payroll){
int i =0;
	for (i = 0; i < nEmployees; i++){
	free(payroll->employees[i]->name);
	free(payroll->employees[i]->title);
	free(payroll->employees[i]->ssnum);
	free(payroll->employees[i]);
	}
	free(payroll->employees);
	
	free(payroll);


}

/* Main program */

main()
{
   payrollT payroll;
	printf("How Many employees?\nMax is 100 ");
	nEmployees = GetInteger();
	//staff = NewArray(nEmployees,employeeRecordT);
	
    //InitEmployeeTable(nEmployees);
    //payroll = GetPayroll(staff, nEmployees); // getpayroll
    payroll = GetPayroll(nEmployees);
	ListEmployees(payroll);
	
	WeekPayroll(payroll);
	
	FreePayroll(nEmployees,payroll);
	
	
	// free
	//free(staff);
}
/*
static void InitEmployeeTable(int numEmp)
{	
employeeRecordT empRec;
	
	//char n[32];
    //char t[32];
    //char ss[32];
    //double sa;
    //int w;

int i = 0;
for(i;i<numEmp;i++){
	printf("Employee #%d:\n", (i+1));
	printf("\tName: ");
    //empRec->name = GetLine();
		//empRec.name = GetLine();
			//empRec.name = "Test";
				//frees all the memory but it leaves junk on the valgrind
				//n = GetLine(); does not work
				scanf("%s\n",n);
				empRec.name = n;
					//scanf("%s",empRec.name); not work
						
	printf("\n\tTitle: ");
    //empRec->title = GetLine();
		//empRec.title = GetLin//e();
			//empRec.title = "Tester";
				// frees all the memory but it leaves junk on the valgrind
				//t = GetLine(); does not work
				scanf("%s\n",t);
				empRec.title = t;
					//scanf("%s",empRec.title); not work
	printf("\n\tSSNum: ");
    //empRec->ssnum = GetLine();
		//empRec.ssnum = GetLine();
			//empRec.ssnum = "222222";
				// this one frees all the memory but it leaves junk on the valgrind
				//ss = GetLine(); does not work;
				scanf("%s\n",ss);
				empRec.ssnum = ss;
					//scanf("%s",empRec.ssnum); not work
	printf("\n\tSalary: ");
    //empRec->salary = GetReal();
		//empRec.salary = GetReal();
			//empRec.salary = 100.00;
				//this one frees all the memory but it leaves junk on the valgrind 
				//sa = GetReal(); does not work;
				scanf("%lf\n",&sa);
				empRec.salary = sa; 
					//scanf("lf",&empRec.salary);
	printf("\n\tWithholding exemptions: ");
    //empRec->withholding = GetInteger();
		//empRec.withholding = GetInteger();
			//empRec.withholding = 2;
				//this one frees all the memory but it leaves junk on the valgrind
				//w = GetInteger(); does not work;
				scanf("%d\n",&w);
				empRec.withholding = w;
					//scanf("d",&empRec.withholding);
	
	staff[i] = empRec;
	}

	
	
}
*/

//static payrollT GetPayroll(employeeRecordT s[], int nEmployees)
static payrollT GetPayroll(int nEmployees)
{	
    payrollT payroll;
	employeeRecordT empRec;

int i = 0;
for(i=0;i<nEmployees;i++){
	printf("Employee #%d:\n", (i+1));
	printf("\tName: ");
	//scanf("%s",n);
	n = GetLine();
	empRec.name = n;		
	
	printf("\n\tTitle: ");
	//scanf("%s",t);
	t = GetLine();
	empRec.title = t;
	
	printf("\n\tSSNum: ");
	//scanf("%s",ss);
	ss = GetLine();
	empRec.ssnum = ss;
	
	printf("\n\tSalary: ");
	//scanf("%lf",&sa);
	sa = GetReal();
	empRec.salary = sa; 
	
	printf("\n\tWithholding exemptions: ");
	//scanf("%d",&w);
	w = GetInteger();
	empRec.withholding = w;

	
	staff[i] = empRec;
	}
	

    payroll = New(payrollT);
    payroll->employees = NewArray(nEmployees, employeeT);
    payroll->nEmployees = nEmployees;
    for (i = 0; i < nEmployees; i++) {
        payroll->employees[i] = New(employeeT);
        payroll->employees[i]->name = staff[i].name;
        payroll->employees[i]->title = staff[i].title;
        payroll->employees[i]->ssnum = staff[i].ssnum;
        payroll->employees[i]->salary = staff[i].salary;
        payroll->employees[i]->withholding = staff[i].withholding;
    }
    return (payroll);
}

static void ListEmployees(payrollT payroll)
{
    int i;

    for (i = 0; i < payroll->nEmployees; i++) {
        printf("%s (%s)\n", payroll->employees[i]->name, payroll->employees[i]->title);
    }
}

