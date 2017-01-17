// Recitation07
// I stopped using prototypes because a friend of mine taking data structure said its a waste of cpu computation time or something.
// for some reason this recitation took longer than expected but i cranked out everything just fine

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include "string.h"

// checks to see how many arguements and exits the program if there isn't the right amount
CheckArg(int c){
if (c != 5){
printf("Too many or too few arguements\n");
printf("You need to run the program like this example below\n");
printf("main212> myprog –input critical1.txt –output output1.txt\n");
printf("or like this\n");
printf("main212> myprog –output output1.txt –input critical1.txt\n");
printf("Try again funny guy!\n");
exit(0);
}
}

// this method makes sure that check[] has -input and -output
// and it puts the next strings in the array as the file names
string *FindFiles(int count ,char *check[]){
// returning two strings
static string r[2];
// make sure to free
string input = "-input";
string output = "-output";
/*
string uInputOne = strcpy(uInputOne,check[1]);
string uOutputOne = strcpy(uOutputOne,check[3]);
string uInputTwo = strcpy(uInputTwo,check[3]);
string uOutputTwo = strcpy(uOutputTwo,check[1]);
*/

// if not in here exit program
/*
if ((strcmp(input,check[1]) != 0 || strcmp(output,check[3]) != 0 ) || (strcmp(input,check[3]) != 0 || strcmp(output,check[1]!= 0 ) ){
free(input);
free(output);
exit(1);
}
*/

//if ((strcmp(input,uInputOne) != 0 && strcmp(output,uOutputOne) != 0 ) || (strcmp(input,uInputTwo) != 0 && strcmp(output,uOutputTwo)!= 0 ) ){
if ((strcmp(input,check[1]) != 0 && strcmp(output,check[3]) != 0 ) && (strcmp(input,check[3]) != 0 && strcmp(output,check[1])!= 0 ) ){
//if ((strcmp(input,check[1]) != 0 || strcmp(output,check[3]) != 0 ) || (strcmp(input,check[3]) != 0 || strcmp(output,check[1])!= 0 )){
printf("You didn't type files in correctly so don't forget to include .txt\n");
printf("You need to run the program like this example below\n");
printf("main212> myprog –input critical1.txt –output output1.txt\n");
printf("or like this\n");
printf("main212> myprog –output output1.txt –input critical1.txt\n");
printf("Try again funny guy!\n");
//free(input);
//free(output);
//free(uInputOne);
//free(uOutputOne);
//free(uInputTwo);
//free(uOutputTwo);
exit(1);
}
//check input first
if (strcmp(input,check[1]) == 0){
r[0] = check[2];
r[1] = check[4];
}else{
r[0] = check[4];
r[1] = check[2];
}

//free(input);
//free(output);
//free(uInputOne);
//free(uOutputOne);
//free(uInputTwo);
//free(uOutputTwo);
return r;
}
// this method will check to see if the string holding the name of the file is right or it will exit the program
// it will also open the file
FILE *OpenUserFile(string fName, string mode){
string filename;
FILE *result;
    //while (TRUE) {
        filename = fName;
        result = fopen(filename, mode);
        if (result != NULL){
			return(result);
		}
		else{
        printf("Can't open the file \"%s\"\n", filename);
		printf("You need to run the program like this example below\n");
		printf("main212> myprog –input critical1.txt –output output1.txt\n");
		printf("or like this\n");
		printf("main212> myprog –output output1.txt –input critical1.txt\n");
		printf("Try again funny guy!\n");
		//free(filename);
		exit(1);
		}
    return (result);
}
// checks to see if the event is already in the array
// if its in the array it updates tasks and will only replace the higher number of days

CheckEvent(int eventData[70][3], int currEvent, int task, int numberOfDays){
int i, notInArray = 1;

eventData[currEvent - 1][0] = (currEvent - 1);
//if (eventData[--currEvent][0] == (--currEvent)){
if (numberOfDays > eventData[currEvent - 1][2]){
		eventData[currEvent - 1][2] = numberOfDays;
		}
		eventData[currEvent - 1][1] = (1 + eventData[currEvent - 1][1]);
//}
//else{

//eventData[--currEvent][1] =  1 ;
//eventData[--currEvent][2] = numberOfDays;

//


/*
for (i = 0; i < 70; i++){
	if (eventData[i][0] == (currEvent - 1)){
	notInArray = 0;
		if (numberOfDays > eventData[i][2]){
		eventData[i][2] = numberOfDays;
		}
		eventData[i][1] = (1 + eventData[i][1]);
		break;
	}
}
if (notInArray){ 
eventData[currEvent - 1][0] = (currEvent - 1);
eventData[currEvent - 1][1] =  1 ;
eventData[currEvent - 1][2] = numberOfDays;
}
*/

}

//ok here i was a little confused on the logic
// so i made two arrays, one that holds the event information a long with the highest numofday number
// and another one that holds the information regarding all the numofdays read in
MakeCriticalPath(FILE *infile, FILE *outfile){
//no more than
int i,ci, count = 1, cEvent, event[70][3], task, numberOfDays[70],day, totalDays = 0, e=0,t=0,nD=0;
//init the arrays
for(i = 0; i <70; i++){
event[i][0] = 0;
event[i][1] = 0;
event[i][2] = 0;
numberOfDays[i] = 0;
}


fprintf(outfile,"Project completion timetable\n");
fprintf(outfile,"-------------------------------------------\n");
fprintf(outfile,"Event\tNum Of Tasks\tMax Num of Days\n");
fprintf(outfile,"-----\t------------\t---------------\n");
    
	//here i read in all the lines until end of file
	// i keep track of how many lines i read via int ci
	//i add all the numberofdays into its array
	//then run the checkevent method to make sure i don't add duplicate event numbers in the array
	ci = 0;
	//char buffer[128];// max line size
	//while(fgets(line,sizeof line, infile) != NULL){
	//while (fscanf(infile, "%d %d %d\n",&cEvent, &task, &day)== 3){
	while((fscanf(infile, "%d %d %d\n",&cEvent,&task,&day) != EOF) ){
	
	
	
	
	//totalDays = (totalDays + numberOfDays);
	numberOfDays[ci] = day;
	CheckEvent(event,cEvent,task,day);
	//count++;
	ci++;
	}
	//checks to see how many events are in the array
	while(event[count][0] != 0)
	count++;
	//adds all the total days
	for (i = 0; i < ci; i++){
	totalDays = (totalDays + event[i][2]);
	}
	//writes the information into the output file
	for (i = 0; i < count; i++){
	if (i == 0){
	e = event[i][0] + 1;
	t = event[i][1];
	nD = event[i][2];
	fprintf(outfile,"%d\t\t%d\t\t%d\t\n",e,t,nD);
	}
	
	// this if statement checks for when an array was never filled with data
	// skipped event number
	if(i > 0 && event[i][0] != 0){
	e = event[i][0]+1;
	t = event[i][1];
	nD = event[i][2];
	//fprintf(outfile,"%d\t%d\t%d\n",event[i][2],event[i][0],event[i][1]);
	fprintf(outfile,"%d\t\t%d\t\t%d\t\n",e,t,nD);
	}
	}
	
	fprintf(outfile,"-------------------------------------------\n");
	fprintf(outfile,"Total number of days to finish the project: %d days\n",(int)totalDays);
}

main(int argc, char *argv[]){
//check then quit
CheckArg(argc);
int i = 0;
FILE *inf, *outf;

string *files; 
files = FindFiles(argc,argv);

inf = OpenUserFile(files[0],"r");
outf = OpenUserFile(files[1],"w");

MakeCriticalPath(inf,outf);
fclose(inf);
fclose(outf);
//free(files[0]);
//free(files[1]);
//free(files);
}

/*




*/