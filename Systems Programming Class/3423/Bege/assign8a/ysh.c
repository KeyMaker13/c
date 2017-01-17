#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#include <unistd.h>

#include <string.h>

#include <fcntl.h>

#include <sys/stat.h>

void err_sys (char *);


struct cmd
{

  int redirect_in;		/* Any stdin redirection?         */

  int redirect_out;		/* Any stdout redirection?        */

  int redirect_append;		/* Append stdout redirection?     */

  int background;		/* Put process in background?     */

  int piping;			/* Pipe prog1 into prog2?         */

  char *infile;			/* Name of stdin redirect file    */

  char *outfile;		/* Name of stdout redirect file   */

  char *argv1[10];		/* First program to execute       */

  char *argv2[10];		/* Second program in pipe         */

};



int cmdscan (char *cmdbuf, struct cmd *com);



int
main ()
{

  char buf[1024];

  struct cmd command;

  int i,fd[2],fdin,fdout;

  pid_t ppid, cpid;

  printf (">");

  fflush (stdout);

  while ((fgets (buf, sizeof (buf), stdin) != NULL))
    {

      if (buf[strlen (buf) - 1] == '\n')	// replacing the \n with \0 in order to avoid cmdscan problems

	buf[strlen (buf) - 1] = '\0';

      if (cmdscan (buf, &command) || (strcmp (buf, "exit") == 0))
	{

	  exit (-1);

	}
      if (pipe (fd) == -1)	// Create pipe to execute prog 1 or prog1 and prog2
	err_sys ("pipe error");

      switch (ppid = fork ())
	{
	case -1:
	  err_sys ("Fork Error");
	case 0:
	  if (command.piping) // we detect that the command line has a pipe we fork a second time
	    {
	     
	      switch (cpid = fork ())
		{
		case -1:

		  err_sys ("Fork error");

		case 0:
		  dup2 (fd[1], STDOUT_FILENO);	

		  close (fd[1]);

		  close (fd[0]);	



		  if (command.redirect_in) //check if the comamnd line has redirect in
		    {
	if((fdin = open(command.infile, O_RDONLY) == -1))  // open the file for read

                err_sys("redirect in file error");


            dup2(fdin, STDIN_FILENO); // Set the input to INFILE

            close(fdin);
}


		  if (execvp (command.argv1[0], command.argv1))	// execute  prog 1 as child, prog 2 (parent 2) will execute after this.

		    err_sys ("error executing program 1");


		default:
		  dup2 (fd[0], STDIN_FILENO);	// prog 2 read from pipe

		  close (fd[0]);

		  if (command.redirect_out)
		    {		//set STDOUT to OUTFILE

		      if (command.redirect_append)
			{	// APPEND to OUTFILE

			  if ((fdout = open (command.outfile, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
			    err_sys ("redirect out append error");

			}

		      else
			{	// NO APPEND

			  if ((fdout = open (command.outfile, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) == -1)	
			    err_sys ("redirect out error");

			}

		      dup2 (fdout, STDOUT_FILENO);	// prog 2 output to file

		      close (fdout);

		    }

		  close (fd[1]);

		  if (execvp (command.argv2[0], command.argv2))	// exec prog 2 as parent of child 2

		    err_sys ("error executing program 2");

		  if (!command.background)
		    {
		      if (waitpid (cpid, NULL, 0) != cpid)
			{
			  err_sys ("backgrounding error");
			}
		    }


		}		/*fork for the 2nd time */




	    }			/*end of piping condition */
	  else
	    {			// When there is no piping.

	      if (command.redirect_out)
		{		//set STDOUT to OUTFILE

		  if (command.redirect_append)
		    {		// APPEND to OUTFILE

		      if ((fd[1] = open (command.outfile, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR)) == -1)	// open the file for append with read/write permission for user

			err_sys ("redirect out append error");

		    }

		  else
		    {		// NO APPEND

		      if ((fd[1] = open (command.outfile, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR)) == -1)	// open the file with read/write permission for user

			err_sys ("redirect out error");


		    }

		  dup2 (fd[1], STDOUT_FILENO);	// prog 1 output to file

		  close (fd[1]);

		}

	      if (command.redirect_in)
		{

		  if ((fd[0] = open (command.infile, O_RDONLY) == -1))	// open the file for read

		    err_sys ("redirect infile error");

		  dup2 (fd[0], STDIN_FILENO);	// set the input to INFILE

		  close (fd[0]);

		}



	      if (execvp (command.argv1[0], command.argv1))	// exec prog 1

		err_sys ("error executing program 1");

	      if (command.redirect_in)

		close (STDIN_FILENO);

	    }			/*end of prog1 */



	}			/*end first fork */
      sleep (1);
      printf (">");

      fflush (stdout);


    }				/*end reading while loop */
  return (0);
}				/*end main */


void
err_sys (char *str)
{
  perror (str);
  exit (-1);

}
