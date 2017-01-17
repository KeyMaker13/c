#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"

typedef struct Rect
{
double x;
double y;
char color;
double w; // width
double h; // height
} RectT;

int chk_overlap(RectT *r1, RectT *r2);
void InitRect(RectT *init);
void InitRandRect(RectT **init, int size);
void FreeMem(RectT **f);

main(){
// declaring RectT a, b, *recs;
RectT a, b, *recs;
InitRect(&a);
InitRect(&b);
//recs = (struct Rect)malloc(50*sizeof(RectT));
recs =(RectT*) malloc(50*sizeof(RectT));
//assert(recs);
int i = 0;

 while(i < 50){
   recs[i].x = rand()%20;
   recs[i].y = rand()%20;
   recs[i].w = rand()%20;
   recs[i].h = rand()%20;
   i++;
}

//if (recs == NULL) Error("No memory available");
//    printf("not enough memory can not run program");
//InitRandRect(&recs, 50);

int overLapA = 0;
int overLapB = 0;  
  for (i = 0; i < 50; i++){
    overLapA += chk_overlap(&a,&recs[i]);
    overLapB += chk_overlap(&b,&recs[i]);
  }

  printf("This many blocks overlap A %d\n",overLapA);
  printf("This many blocks overlap B %d\n",overLapB);
free(recs);
  
//FreeMem(&recs);

//testing
int t = chk_overlap(&a,&b);
printf("testing here %d",t);
}

void InitRect(RectT *init){
 printf("Enter x value : ");
  //pointer to structure 
  init->x = GetReal();
 printf("Enter y value : ");
  init->y = GetReal();
 printf("Enter w value : ");
  init->w = GetReal();
 printf("Enter h value : ");
  init->h = GetReal();
}

int chk_overlap(RectT *r1, RectT *r2){
double ax1,ax2,ax3,ax4,ay1,ay2,ay3,ay4,bx1,bx2,bx3,bx4,by1,by2,by3,by4;

ax1 = (*r1).x;
ay1 = (*r1).y;
ax2 = (*r1).x + (*r1).w;
ay2 = (*r1).y;
ax3 = (*r1).x;
ay3 = (*r1).y - (*r1).h;
ax4 = (*r1).x + (*r1).w;
ay4 = (*r1).y - (*r1).h;
bx1 = (*r2).x;
by1 = (*r2).y;
bx2 = (*r2).x + (*r2).w;
by2 = (*r2).y;
bx3 = (*r2).x;
by3 = (*r2).y - (*r2).h;
bx4 = (*r2).x + (*r2).w;
by4 = (*r2).y - (*r2).h;

if ((ax2 > bx3 ) && (ay2 > by3 )){
  return 1;
  }
if ((ax1 < bx4) && (ay1 > by4)){
  return 1;
  }
if ((ax4 > bx1) && (ay4 < by1)){
  return 1;
  }
if ((ax3 < bx2) && (ay3 < by2) ){
  return 1;
  }

  return 0;
}


void InitRandRect(RectT **init, int size){
  int i = 0;
  while(i < size){
   init[i]->x = rand()%20;
   init[i]->y = rand()%20;
   init[i]->w = rand()%20;
   init[i]->h = rand()%20;
   i++;
  }
  free(init);
}

void FreeMem(RectT **f){

free(f);
} 


