#include <stdio.h>




void copyString(char *outString, char *inString)
{
	int i=0;
	while(1)
	{
		if (inString[i] == '\0')
			break;
		else
			outString[i] = inString[i];
		i++;
	}	
	while(outString[i] != '\0')
		outString[i] = '\0';

}


void strCopy(char *out, char *in)
{
	int i=0;
	if (in)
		while (out[i] = in[i]) i++;
}





int main(int nargs, char *argv[])
{
	
	char array1[80];
	int i;

	for (i=0; i<nargs; i++)
	{
		copyString(array1,argv[i]);
/*		strCopy(array1,argv[i]); */
		printf("\nCopied String: %s\n", array1);
		printf("Argv[%d]: %s\n",i,argv[i]);
	}
		
	return 0;
}
