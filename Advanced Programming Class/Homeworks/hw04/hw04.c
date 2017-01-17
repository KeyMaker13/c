#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "strlib.h"
#include "simpio.h"


typedef struct Emp {
    string name;
    string title;
    string ssnum;
    double salary;
    int withholding;
} employeeRecordT;

typedef struct {
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

static employeeRecordT *staff;
//payrollT GetPayroll(int numEmp, employeeRecordT *staff)
payrollT GetPayroll(int numEmp)
{
  payrollT payroll = GetBlock(sizeof(payrollT));
 // payrollT payroll = malloc(sizeof(payrollT));
  payroll->employees = GetBlock(sizeof(employeeT));
   payroll->nEmployees =  numEmp;
  //payroll->employees = malloc(numEmp*sizeof(struct Emp));
  if (payroll->employees == NULL){
  printf("not enough memory");
	exit(1);
  }
  
  //creating employees of struct Emp
  int i = 0;
  
  //employeeRecordT staff[numEmp];
	for (i = 0; i < numEmp; i++){
	//staff[i]= GetBlock(sizeof(empoyeeRecordT));
	printf("Employee #%d:\n", (i+1));
	printf("\tName: ");
	staff[i].name = GetLine();
	printf("\tTitle: ");
	staff[i].title = GetLine();
	printf("\tSSNum: ");
	staff[i].ssnum = GetLine();
	printf("\tSalary: ");
	staff[i].salary = GetReal();
	printf("\tWithholding exemptions: ");
	staff[i].withholding = GetInteger();
	
	payroll->employees[i] = GetBlock(sizeof(employeeRecordT));
	payroll->employees[i]->name = staff[i].name;
	payroll->employees[i]->title = staff[i].title;
	payroll->employees[i]->ssnum = staff[i].ssnum;
	payroll->employees[i]->salary = staff[i].salary;
	payroll->employees[i]->withholding = staff[i].withholding;
  } 

  
	
    return (payroll);
}

FreePayroll(int numEmp, payrollT payroll){
int i;
for (i = 0; i <numEmp; i++){
	FreeBlock(payroll->employees[i]);
}
//free(payroll->employees[i]);
FreeBlock(payroll->employees);
FreeBlock(payroll);


}

FreeStaff(int numEmp, employeeRecordT *record){
//int i;
//for (i = 0; i <numEmp; i++){
//free(*(record+i))	;


//}
FreeBlock(record);

}

WeekPayroll(payrollT payroll)
{
	printf("\nWeekly Payroll\n");
	printf("Name\t\tGross Tax Net \n");
	printf("----------------------------------------------------------\n");
	int i;
	double tax, net;
    for (i = 0; i < payroll->nEmployees; i++) {
		tax = (((payroll->employees[i]->salary)-(payroll->employees[i]->withholding))*0.25);
		net = payroll->employees[i]->salary - tax;
        printf("%s\t\t%0.2lf - %0.2lf = %0.2lf\n", payroll->employees[i]->name, payroll->employees[i]->salary,tax,net);
    }
}


/* Main program */

main()
{
	// asks for number of employees
	int numberOfEmployees;
	printf("How many employees? ");
	numberOfEmployees = GetInteger();
	
	// creates staff array
	//employeeRecordT *staff;
	staff = GetBlock(sizeof(employeeRecordT));
	//employeeRecordT staff = NewArray(numberOfEmployees,employeeRecordT);
	//employeeRecordT *staff = malloc(numberOfEmployees*sizeof(employeeRecordT));
	
  	//payrollT payroll = GetPayroll(numberOfEmployees, staff);
	payrollT payroll = GetPayroll(numberOfEmployees);
	WeekPayroll(payroll);

	FreePayroll(numberOfEmployees,payroll);
	
	
	//FreeStaff(numberOfEmployees,staff);
	
	
}


