#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
typedef struct cell 
{
int ID;
char name[20];
struct cell *next;
} cellT, *cellPtrT;

struct buffer{
	cellT *start;
}bufferADT;

void PointerSwap(int **ptr1, int **ptr2);

cellT *xor(cellT *M, cellT *S);

main(int argc, char *argv[]){
int v1 = 10, v2 = 20, dR1, dR2;
int *p1 = &v1, *p2 = &v2;

dR1 =(int) p1;
dR2 = (int)p2;
printf("The values before the swap are p1:%d, p2:%d\n",dR1,dR2);
printf("Swapping variables\n");
PointerSwap(&p1,&p2);
dR1 = (int)p1;
dR2 = (int)p2;
printf("The swapped values are now p1:%d, p2:%d\n",dR1,dR2);

printf("--------------------Question 3---------------------\n");
printf("Displaying comments\n");

FILE *in;
in = fopen(argv[1],"r");
if (in == NULL){
fclose(in);
exit(0);
}
int comments = 1;
char ss,sst;
int fs = 1, fst = 1;
while(!feof(in)){
	fscanf(in,"%c",&ss);
	if (ss == '/')
	{
		fscanf(in,"%c",&ss);
		if (ss == '*')
		{
			fscanf(in,"%c", &ss);
			comments = 0;
		}
	}
	if (ss == '*')
	{
		fscanf(in,"%c",&ss);
		if (ss == '/')
		{
			fscanf(in,"%c", &ss);
			comments = 1;
		}
	}
	if (comments == 0)
	printf("%c",ss);
}
printf("\n");
fclose(in);

printf("---------------------Question 4-----------------------\n");
bufferADT buffer;
buffer = New(bufferADT);
buffer->start = New(cellT *);
buffer->start->next = NULL;

cellT *M; 
M = New(cellT *);
M->ID = 2;
M->name[0] = 'T';
M->name[1] = '.';
M->name[2] = 'K';
M->name[3] = '.';
M->next = buffer->start->next;
buffer->start->next = M;
buffer->start = M;

cellT *N;
N = New(cellT *);
N->ID = 5;
N->name[0] = 'A';
N->name[1] = '.';
N->name[2] = 'Z';
N->name[3] = '.';
N->next = buffer->start->next;
buffer->start->next = N;
buffer->start = N;


H = New(cellT *);
H->ID = 9;
H->name[0] = 'P';
H->name[1] = '.';
H->name[2] = 'T';
H->name[3] = '.';
H->next = buffer->start->next;
buffer->start->next = H;
buffer->start = H;

cellT *cp = start;
while(cp != NULL){
printf("ID : %d\n",cp->ID);
cp = cp->next;
}


}

void PointerSwap(int **ptr1, int **ptr2){
	int ptemp;
	ptemp = (int)*ptr1;
	*ptr1 = *ptr2;
	*ptr2 = (int *)ptemp;
}

cellT *xor(cellT *M, cellT *S){

return NULL;
}