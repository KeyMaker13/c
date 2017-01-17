#include <stdio.h>
#include <math.h>

//prototypes
void SetArrayRand(int x[], int n);
int RandInt(int a, int b);
void SelectionSort(int x[], int n);
void Merge(int a[], int na, int b[], int nb, int c[], int nc);
void PrintArray(char *name, int x[], int nx);

main(){
// 1.  Declare three integer arrays as follows */
int  a[50], b[70], c[120];

// 2. implement a function set_array_rand(int x[], int n) and  call it to generate the values in array a and b randomly. */
SetArrayRand(a, 50); 
SetArrayRand(b, 70);

/* 3. using the selection_sort(double x[], int n) function we implemented in class, sort the elements in a and b arrays.  */
SelectionSort(a, 50);
SelectionSort(b, 70);

/* 4. implement a MERGE function and call it as follows tomerge the values in arrays a and b into array c such that the values in c will be sorted after merging */ 
Merge(a, 50, b, 70, c, 120);

/* 5. print the values in array c */
PrintArray("Array c", c, 120);
}

void SetArrayRand(int x[], int n){
//1. Randomly generate elements of x array, e.g, */
int i = 0;
for (i; i < n ; i++){
	x[i] = RandInt(30,100);
	}
}

int RandInt(int a, int b){
return rand()%(b-a+1) + a;
}

void SelectionSort(int x[], int n){
int k,j,m;
double temp;
for(k=0; k<=n-2; k++){
m = k;
	for (j = k+1; j<=n-1; j++){
	if (x[j] < x[m])
	m = j;
	}
temp = x[k];
x[k] = x[m];
x[m] = temp;
}
}

void Merge(int a[], int na, int b[], int nb, int c[], int nc)
{
//  merge the values in a and b into c while keeping the values sorted. For example, suppose we have the following two Arrays a = { 3, 7, 9, 12} and b = {4, 5, 10}
//When we merge these two arrays, we will get  
//c = {3, 4, 5, 7, 9, 10, 12}

/* YOUR CODE */

//not yet the programming God so yes I will be using two for loops
// this loops fill the array with all values
int i = 0;
for (i ; i < nc; i++){
	if (i<na){
		c[i] = a[i];
		}
		else{
		c[i] = b[i];
		}
	}
//this already sorts it, the instructions were not clear about duplicate values so I just used the method already given to us
SelectionSort(c,nc);
}

void PrintArray(char *name, int x[], int nx)
{
   /* YOUR CODE */
printf("%s\n",name);
int i = 0;
for (i;i<nx;i++){
	printf("%d\n", x[i]);
}
}


