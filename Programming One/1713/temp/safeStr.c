/*


*/



/*
Only allowed to use fgets, malloc, free, and assert library functions.
*/

/*
This function safely reads a complete line of unknown length from the
open file pointed to by fpin. It returns a line that is at most CHUNKSZ-1
characters longer than the minimum needed to hold the line.
It initially allocates an array of DEFLEN characters to hold the string,
and if this space is inadequate to hold the string, it will iteratively
create a new string that is CHUNKSZ larger, copy the old string to it
release the old string, and then read in more characters from the file,
and continue this until the entire line of arbitrary length can be returned.

RETURNS: NULL if no characters are left in fpin, otherwise:
			pointer to allocated array at most CHUNKSZ-1 characters
			longer than minimum necessary to hold an arbitrarily long
			line from file fpin.
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define DEFLEN 1
#define CHUNSZ 1


/*
 *	This function obtains the length of the string in question.
 */

int getLength(char *string)
{
	int i=0;
	if(string)
		while (string[i] != '\0')
			i++;
	return i;
}

/*
 *	This function copies the string coming in to the pointer.
 *	out.
 */

void copyString(char *in, char *out)
{
	int i=0,N = getLength(in);
	for (i=0; i<N; i++)
		out[i] = in[i];

}

/*
 *	This function gets strings from files and returns a pointer.
 */
char *getStrFromFile(FILE *fpin)
{
	char *string, *temp, *hold;
	int i=0, length, size = DEFLEN;


	string = malloc(size * sizeof(char));
	temp = malloc(size * sizeof(char)); 
	assert(string && temp); 


	if (fgets(string, size, fpin) == NULL)
		return NULL;
	printf("Checkpoint1\n");
	printf("%s\n",string);


	printf("String Checkpoint\n\n\n");

	copyString(string, temp);


	printf("Temp: %s\n", temp);

	while(1)
	{
		fgets(temp,DEFLEN,fpin);
		if (temp[0] == '\n')
			break;
		
		hold = malloc(size * sizeof(char));
		copyString(string, hold);
		printf("After string was copied");
		printf("%s\n", hold);
		free(string);
		printf("This is the hold checkpoint: %s\n",hold);
		size += CHUNSZ;
		string = malloc(size * sizeof(char));
		string = hold;
		string[size-1] = temp[0];
	}


/*
	size = size + CHUNSZ;
	string = malloc(size * sizeof(char));
	assert(string);
	string = temp;	
	
	
	
	printf("%s\n", string);
	printf("CP5\n");

	length = getLength(string);

	while(1)
	{
		if(string[length-1] == '\n')
			break;
		fgets(string,size,fpin);
		printf("%s\n", string);
		printf("This is right before temp is freed.");
		free(temp);
		temp = malloc(size * sizeof(char));
		
	}




	printf("Before the loop\n");
	if (&string[length-1] != '\n')
	{
		printf("Checkpoint2");
		while(1)
		{
			
			fgets(hold,1,fpin);
			string[i+1] = hold[0];
			if (hold[0] == '\n')
				break;
			temp = malloc(size * sizeof(char));
			*temp = *string;
			free(string);
			size += CHUNSZ;
			string = malloc(size * sizeof(char));
			for (i=0; i<size-1; i++)
				string[i] = temp[i];
		}
	}


	free(temp);

















	
	if(string[length-1] != '\n' || string[length-1] != '\0')
		while(string[length-1] != '\n' || string[length-1] != '\0')
		{
			for(i=0; i<length; i++)
				printf("%s\n", &string[i]);
			if(i==(length-1))
				break;
		}

*/
/*
	while (1)
	{
		printf("Checkpoint2\n");
		if (string[length-1] != '\n' || string[length-1] != '\0')
		{
			temp = malloc(size * sizeof(char));
			while(temp[i] = string[i])
				i++;


			free(string);
			size += CHUNSZ;
			string = malloc(size * sizeof(char));
			string = temp;


			while(temp[i])
				string[i]=temp[i];
			printf("Temp: %s\n", temp);
			free(temp);

			fgets(string, size, fpin);
			printf("Checkpoint3\n\n");
			printf("%s\n", string);
		}
		if (string[length-1] != '\n')
			break;
	}
*/

	free(hold);
	free(temp);
	printf("%s\n", string);


	return string;
}


/*
 * This is the main method of the program that will be executed.
 */
int main(int nargs, char *args[])
{
	FILE *fpin;

	if (nargs != 2)
	{
		fprintf(stderr, "USAGE: %s <file>\n", args[0]);
		exit(1);
	}

	fpin = fopen(args[1], "r");
	while(1)
	{

		char *ln;	

		ln = getStrFromFile(fpin);

		if (!ln)
			break;
		printf("%s", ln);
		free(ln);
	}

	fclose(fpin);
	return 0;
rge carlin
}
