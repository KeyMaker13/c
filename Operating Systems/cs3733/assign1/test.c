#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[] ){
	
	argv++;
        int t = atoi(*argv);

	printf("%d",t);
	
	char c = '{'; // or whatever

	if (isalpha(c)) {
    		puts("it's a letter");
	} else if (isdigit(c)) {
    		puts("it's a digit");
	} else {
		puts("something else?");
	}
	
	return 0;
}
