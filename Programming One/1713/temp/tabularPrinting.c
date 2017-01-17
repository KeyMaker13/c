#include <stdio.h>

int main(void)
{
	char *first_name = "The LAST name";
	char *last_name = "The FIRST name";
	double cash = 128.73, debt = 0.8595371e12;
	char *space = " ";

	printf("%9s%2c%6s%2c%9s%2c%12s\n","LAST NAME",' ',"FIRST",' ',"CASH",' ',"DEBT");
	printf("=========%2s======%2s=========%2s============\n",space,space,space);
	printf("%.9s%2s%.6s%2s%9.2f%2s%12e\n\n\n",last_name,space,first_name,space,cash,space,debt);

	return 0;

}
