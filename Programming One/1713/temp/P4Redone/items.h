#ifndef ITEMS_H         /* guard against multiple inclusions */
   #define ITEMS_H

#include <stdio.h>      /* required to define FILE */

typedef struct items item_t;
struct items
{
   char name[32];
   float cost, weight;
   int dam;
   item_t *next;
};

/*
 * Prototypes for milestone 1
 */
item_t *ReadItemsFromFile(char *file);
void KillAllItems(item_t *itb);
void PrintItemTable(FILE *fpout, item_t *itb);
void WriteItemsToFile(char *file, item_t *itb);
int CountItems(item_t *itb);
float SumItemsWeight(item_t *itb);

/*
 * Prototypes for milestone 2
 */
item_t *DelItemAtPos(item_t *itb, int pos);
item_t *DupItem(item_t *ip);
item_t *AddItemAtPos(item_t *itb, item_t *new, int pos);
/*
 * Prototypes for milestone 3
 */
item_t *ReverseItemOrder(item_t *itb);
item_t *SortItemsByCost(item_t *itb);
item_t *SortItemsByWeight(item_t *itb);
item_t *SortItemsByName(item_t *itb);
#endif                  /* end guard against multiple inclusions */
