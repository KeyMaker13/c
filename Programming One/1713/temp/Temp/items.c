/*
 * Name: Abel Atkinson
 * Assignment: Items
 * CS1713
 */

#include "items.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>






/* Helper function to determine string length */
int getLength(char *in)
{
	int i=0;
	if(in)
		while(in[i])
			i++;
	return i;
}


/* This helper function allocates the space needed for each item and
 * assigns pointers to the correct value obtained when the file is read.
 */


item_t *newItem(item_t *in, char *name, int nameLength, int damage,
                float cost, float weight)
{

	int i;
	in = malloc(sizeof(item_t));
	assert(in);

	for(i=0; i<nameLength; i++)
		in->name[i] = name[i];
	in->dam = damage;
	in->cost = cost;
	in->weight = weight;
	in->name[nameLength] = '\0';
	in->next = NULL;
	return in;
}

/*
 * =========================
 * Functions for milestone 1
 * =========================
 */

/*
 * This function reads all items in file, and returns them in file-order
 * in a dynamically created list.  Each line of the file is one item, 
 * and has format:
 * '<description>' <damage> <cost> <weight>
 * RETURNS: base pointer to items in file in file order.  NULL if file does
 *          not exist, or has no validly formated lines.
 */

/*
 * fscanf(fpin, " '%[^']' %d %f %f", name &damage, &cost, &weight
 */
item_t *ReadItemsFromFile(char *file)
{
	FILE *ifp;
	int damage;
	item_t *list, *basep = NULL;
	float cost, weight;
	char name[32];

	ifp = fopen(file, "r");
	assert(ifp);

	while(1)
	{
		if(fscanf(ifp, " '%[^'] %d %f %f", name, &damage, &cost, &weight) != 4)
			break;
		else if(basep == NULL)
			basep = list = newItem(list, name, getLength(name), damage, cost, weight);
		else
			list = list->next = newItem(list, name, getLength(name), damage, cost, weight);
		fprintf(stdout, "Testing: %d\n", list->dam);
	}
	fclose(ifp);
	return basep;
}

/*
 * This routine frees all storage associated with entire list itb
 */
void KillAllItems(item_t *itb)
{	
	item_t *basep;
	
	if(itb)
		for(basep=itb; basep != NULL; basep = basep->next)
			if(basep)
				free(basep);
	free(itb);
}

/*
 * This function prints out all items in an easy-to-read table, with an item
 * on each line, each column separated by 2 spaces, and:
 *    4 digits for item number
 *    31 characters for name
 *    7 digits for damage
 *    13 characters for cost, with 2 decimal places printed
 *    9 characters for weight, with 2 decimal places printes
 */
void PrintItemTable
(
   FILE *fpout,    /* FILE stream to print to (set to stdout for screen) */
   item_t *itb     /* list of items to dump to screen */
)
{
	
	item_t *basep;
	int i=0;


   /* declarations here! */


  	fprintf(fpout, 
  	" NUM  NAME                             DAMAGE          COST    WEIGHT\n");
  	fprintf(fpout, 
  	"====  ===============================  ======  ============  ========\n");
	for(basep=itb; basep != NULL; basep = basep->next, i++)
		fprintf(fpout, "%4d  %31s  %7d  %13.2f  %9.2f\n", i, basep->name, basep->dam,
				basep->cost, basep->weight);

  	/* print all the lines */
  	 printf("\n");
	
}

/*
 * This function prints all items in itb to the a file with name file.  Each
 * line of the file is one item, and has format:
 * '<description>' <damage> <cost> <weight>
 * Output files from this routine can be read in by ReadItemsFromFile.
 */
void WriteItemsToFile
(
   char *file,     /* name of file to dump itb to */
   item_t *itb     /* list of items to be dumped to file */
)
{

	FILE *fpout;
	item_t *basep;

	fpout = fopen(file, "w");
	assert(fpout);

	for(basep=itb; basep != NULL; basep = basep->next)
		fprintf(fpout, "'%s' %d %f %f\n", basep->name, basep->dam,
				basep->cost, basep->weight);
	fclose(fpout);
}

/*
 * RETURNS: number of items in list itb
 */
int CountItems(item_t *itb)
{
	int count=0;
	item_t *basep;
	if(itb)
		for(basep=itb; basep != NULL; basep = basep->next)
			count++;
	return count;
}

/*
 * RETURNS: cumulative weight of all items in list itb
 */
float SumItemsWeight(item_t *itb)
{
	float weight = 0.0;
	item_t *basep;
	if(itb)
		for(basep=itb; basep != NULL; basep = basep->next)
			weight += basep->weight;
	return weight;
}

/*
 * =========================
 * Functions for milestone 2
 * =========================
 */

/*
 * This function deletes the item at position pos from queue.  pos must be
 * between 0 and 1 less than the number of items in the list.
 * RETURNS: possibly new base ptr for list
 */
item_t *DelItemAtPos(item_t *itb, int pos)
{
	return NULL;
}

/*
 * This function duplicates the item pointed to be old, except that
 * the new structure's next member is set to NULL.
 * RETURNS: pointer to new structure duplicating old
 */
item_t *DupItem(item_t *old)
{
	return NULL;
}

/*
 * This function adds item new at position pos in list itb.  Pos should be
 * between 0 and N (number of items in list):
 * If pos==0, then item becomes the new base pointer for list.  
 * else if pos==N, the item is added to the end of the list.
 * otherwise, it is added internal to the list.
 * RETURNS: possibly new base ptr of list with added item
 */
item_t *AddItemAtPos
(
   item_t *itb,   /* base ptr of list of items to add to */
   item_t *new,   /* item to add to list */
   int pos        /* position to add to (starting from 0) */
)
{
	return NULL;
}

/*
 * =========================
 * Functions for milestone 3
 * =========================
 */
/* 
 * This function reverses the item order in list pointed to by itb
 * RETURNS: base pointer of list in opposite order
 * NOTE: the old list is destroyed in making the new!
 */
item_t *ReverseItemOrder(item_t *itb)
{
/*
 * NOTE: Despite the fact that the list was reversed correctly,
 * and assert confirms that the name was assigned to its location,
 * the last item_t fails to show the name when printed to table.
 */
	return NULL;
}

/*
 * This function does greatest-to-least sort of list itb on cost.
 * RETURNS: base pointer of new list.
 * NOTE: old list (itb) is destroyed in process of creating new list!
 */
item_t *SortItemsByCost(item_t *itb)
{
	return NULL;
}

/*
 * This function does greatest-to-least sort of list itb on Weight
 * RETURNS: base pointer of new list.
 * NOTE: old list (itb) is destroyed in process of creating new list!
 */
item_t *SortItemsByWeight(item_t *itb)
{
	return NULL;
}



int compareName(char *x, char *y)
{
	return 0;
}

/*
 * This function does least-to-greatest (alphabetic) sort of list itb on name.
 * RETURNS: base pointer of new list.
 * NOTE: old list (itb) is destroyed in process of creating new list!
 */
item_t *SortItemsByName(item_t *itb)
{
	return NULL;
}






