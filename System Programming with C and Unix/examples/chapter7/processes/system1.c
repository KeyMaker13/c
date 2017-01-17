
	/* system() can be used to combine the effects of fork(),
	** exec() and wait() (pg 228) */

#include <stdio.h>
#include <stdlib.h>

main()
{
char text[80];

printf("Ready to system()...\n");
sprintf(text,"date -u");
system(text);
printf("Did it work?\n");
sleep(4);
printf("Indeed it did.\n");
}

