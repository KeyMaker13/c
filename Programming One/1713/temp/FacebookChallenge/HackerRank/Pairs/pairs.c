#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main() {

    int *array, N, diff, *ptr, *ptr2, count = 0;
    
    
    if(fscanf(stdin,"%d%d", &N, &diff) == 2)
        array = malloc(N*sizeof(int));
    assert(array);
    ptr = array;
    while(fscanf(stdin,"%d",ptr++) == 1);
    for(ptr=array; *ptr; ptr++)
    {
        ptr2=ptr;
        ptr2++;
        while(*ptr2)
        {
            if(abs(*ptr - *ptr2) == diff)
                count++;
            ptr2++;
        }        
    }
    fprintf(stdout,"Count: %d\n",count);
	free(array);
	return 0;
}
