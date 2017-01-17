#include<stdio.h>
#include<stdlib.h>


char_exchange(char *s, int i, int j){
char *si = s;
char *sj = s;
int ci = 0, cj = 0;
/*
	while (*s++){
		*si++;
		ci++;
		//*s = 't';
	}
	si = 't';
	//s = si;
	//*s = 'T';
	/*
	while (cj < j){
		*sj++;
		cj++;
	}
	*si = *sj;
	
	//s = si;
	*/
	
}



main(){
printf("Midterm Two\n");
printf("Practicing chapter 3 reading in a file\n");
printf("--------------------------------------\n");
printf("Reading in hw grades and writing out the average\n");
printf("\n");


FILE *in, *out;
int studentNumber, studentNumberRef,grade, i = 0;
double avgGrade;
	
	if((in = fopen("open.txt", "r")) == NULL){
		printf("The file name is incorrect, could not open file\n");
		exit(-1);
	}
	if((out = fopen("close.txt", "w")) == NULL){
		printf("The file name is incorrect, could not open file\n");
		exit(-1);
	}
	while(feof(in) == 0){	
		fscanf(in,"%d",&studentNumber);
			for (i = 0; i < 5; i++){
				fscanf(in, " %d",&grade);
				studentNumberRef = studentNumber;
				avgGrade +=grade;
			}	
		fprintf(out,"Student number: %d; Average Grade %0.1lf\n",studentNumberRef, avgGrade/5);
		avgGrade = 0;
	}	
	
fclose(in);
fclose(out);

//fall 2011 - midterm2
//char *course1 = "cs2213";
char course2[] = "CS2213";
//course1[3] = 'x';
course2[3] = 'x';
//printf("%s ",course1);
printf("%s",course2);




//spring 2012midterm 2 i c
char *s;
s = "abcde";
printf("%s\n",s);
printf("doing exchange\n");
char_exchange(s, 0, 3);
printf("%s",s);


}