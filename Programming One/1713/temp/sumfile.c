#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
	char *inf;
	FILE *fpin;
	int tot;

	char *GetFlags(int argc, char **argv);
	int sumfile(FILE *fpin);

	inf = GetFlags(argc, argv);
	fpin = fopen(inf, "r");
	assert(fpin);
	tot = sumfile(fpin);
	fclose(fpin);
	printf("Total = %d\n", tot);
	return 0;
}

/*
Print Usage and help info when commandline args are malformed, then exit
*/

void PrintUsage(char *name, int ierr, char *flag)
{
	if (ierr > 0)
		fprintf(stderr, "Bad argument #%d: '%s'\n", ierr,
					flag?flag:"OUT-OF-ARGUMENTS");
	else if (ierr < 0)
		fprintf(stderr, "ERROR: %s\n", flag);
	fprintf(stderr, "USAGE: %s [flags]:\n", name);
	fprintf(stderr, "	-i <input file>\n");

/*
Signal abnormal termination
*/
	if (ierr != 0)
		exit(ierr);
	else
		exit(-1);
}


/*
This routine parses the commandline arguments provided to the routine
in order to find out what file to read in. If no file is provided, take
the default name "num.dat"
RETURNS: file name to read numbers from
*/

char *GetFlags(int argc, char *argv[])
{
	char *infile = "num.dat";
	int i;

/*
 * Loop over all commandline arguments, and parse those that make sense. If
 * a flag is unknown or badly formed, print usage information and abort
 * program execution while returning an error code.
 * NOTE: we don't parse argv[0] since that is the name of the program, not a
 * flag!
 */

	for (i=1; i<argc; i++)
	{
/*
All flags must begin with -, or they are malformed. Notice we don't
have to prototype PrintUsage, since we put PrintUsage in the file first,
and so the routine definition serves as the prototype for following
invocations. This is more fragile than prototyping, since it depends 
on routines appearing in a fixed order in the source.
NOTE: GetUsage is never returned from since it calls exit()
*/
		if (argv[i][0] != '-')
			PrintUsage(argv[0], i, argv[i]);
		switch(argv[i][1]) 	/* legal values are M, N, n */
		{
		case 'i':	/* -i <input file name> */
			if (++i >= argc)	/* do we have required 2nd arg? */
				PrintUsage(argv[0], i-1, NULL);
			infile = argv[i];
			break;
		default:   /* any other flag is unknown! */
			PrintUsage(argv[0], i, argv[i]);
		}
	}
	return(infile);
}

/*
This routine reads all available integers from the open file fpin,
and returns the sum of all read-in integers
*/

int sumfile(FILE *fpin)
{
	int num, sum=0;
	while (fscanf(fpin, "%d", &num) == 1)
		sum+=num;
	return(sum);
}


