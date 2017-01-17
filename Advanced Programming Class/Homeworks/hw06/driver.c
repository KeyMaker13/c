#include <stdio.h>
#include <stdlib.h>
#include "mnemonics.h"

//This will start the for loop
void PrintCombinations(int ac, char *av[]){
int i = 1;
	for (i; i < ac; i++){
		ListMnemonics(av[i]);
	}
}

main(int argc, char *argv[]){
PrintCombinations(argc,argv);
}