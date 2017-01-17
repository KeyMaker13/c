#ifndef PSLIBRARY_H
#define PSLIBRARY_H

#define READY 0
#define RUNNING 1
#define	WAITINOG 2
#define DONE 3

static char stateChars[];
void part0(char *s1, char *s2); 
void display(char *heading, char *s1, char *s2);
void fcfsa(char *s1,char *s2,int x1,int y1,int z1,int x2,int y2,int z2);
void proto(char *s1, char *s2, int quantum, int x1, int y1, int z1, int x2, int y2, int z2);
void sjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2);
void psjf(char *s1, char *s2, int x1, int y1, int z1, int x2, int y2, int z2);
void rr(char *s1, char *s2, int q, int x1, int y1, int z1, int x2, int y2, int z2);
#endif

