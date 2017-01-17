
	/* Types of code in a header file (pgs 257-259) */

	/* function prototypes */
double sqrt(double x);

	/* constant definitions */
#define M_PI 3.14159265358979323846 /* pi */


	/* macros for lists of values */
#define KeyPress	2
#define KeyRelease	3
#define ButtonPress	4
#define ButtonRelease	5
#define MotionNotify	6
	/* ... list continues for 34 entries ... */


	/* library-aliases for data types */
typedef unsigned long Mask;


	/* structure definitions, sometimes combined with aliases */
struct _IO_FILE {
		int _flags;
		int _fileno;
		int _blksize;
		/* ... many additional fields not printed here ... */
		}
typedef struct _IO_FILE FILE;

