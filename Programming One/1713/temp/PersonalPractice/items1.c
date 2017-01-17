#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct items item_t;
struct items
{
	char name[32];
	float cost, weight;
	int dam;
	item_t *next;
};





void FreeAllItems(item_t *in)
{

}

item_t *newItem(item_t *in, char *name, int length)
{

	int i;
	in = malloc(sizeof(item_t));
	assert(in);

	for(i=0; i<length; i++)
		in->name[i] = name[i];
	in->name[length] = '\0';
	in->cost = 1.50;
	in->dam = 4;
	in->weight = 12.00;
	in->next = NULL;
	return in;
}

int getLength(char *in)
{
	int i;
	if(in)
		while(in[i])
			i++;
	return i;
}



int main(int nargs, char *argv[])
{
	item_t *list, *basep;
	char *string;
	string = malloc(32 * sizeof(char));
	string = "testing";


/*
	basep = list = newItem(list, string, getLength(string));
	string = "TestingAgain";
	list = list->next = newItem(list, string, getLength(string));
	string = "LastTest";
	list = list->next = newItem(list, string, getLength(string));
	list = list->next = NULL;
*/

	basep = list = newItem(list, string, getLength(string));
	string = "LastTest";
	list = list->next = newItem(list, string, getLength(string));
	string = "JustKidding";
	list = list->next = newItem(list, string, getLength(string));
	for(; basep != NULL; basep = basep->next)
		printf("\nName: %s\nDamage: %d\nCost: %.2f\nWeight: %.2f\n\n",
				basep->name, basep->dam, basep->cost, basep->weight);


	return 0;
}


















