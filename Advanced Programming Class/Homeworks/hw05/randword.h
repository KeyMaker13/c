// randword.h interface
#ifndef _randword_h
#define _randword_h

//includes
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

extern string words[20];

// export
int InitDictionary();
string ChooseRandomWord(int fileSize);

#endif