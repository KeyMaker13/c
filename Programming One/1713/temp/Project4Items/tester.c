#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "items.h"

item_t *AddItemFromTestFile(item_t *itb)
{
   int pos, N;
   item_t *new;
   new = ReadItemsFromFile("testadd.dat");
   assert(new);
   if (new->next)
      KillAllItems(new->next);

   N = CountItems(itb);
   printf("Enter position to put new item in (between 0 and %d): ", N-1);
   assert(scanf("%d", &pos) == 1);
   assert(pos >= 0 && pos <= N);

   itb = AddItemAtPos(itb, new, pos);
   return(itb);
}

item_t *DupItemInList(item_t *itemb)
{
   int i, n, N, pos;
   item_t *ip, *new;

   N = CountItems(itemb);
   printf("Enter item number to duplicate (between 0 and %d): ", N-1);
   assert(scanf("%d", &n)==1);
   assert(n >= 0 && n < N);
/*
 * Find the item to dupe
 */
   for (i=0, ip=itemb; i < n; i++, ip = ip->next);
/*
 * Duplicate item
 */
   new = DupItem(ip);
   assert(new && new->next == NULL);
/*
 * Add it at a specified location
 */
   printf("Enter position to put new item in (between 0 and %d): ", N);
   assert(scanf("%d", &pos) == 1);
   assert(pos >= 0 && pos <= N);
   itemb = AddItemAtPos(itemb, new, pos);
   return(itemb);
}

int main(int nargs, char **args)
{
   item_t *ip=NULL;
   while(1)
   {
      int i;
      float f;
      char file[256];
      char ch;

      printf("\n\nEnter command:\n");
      printf("   r : read in a item list from file\n");
      printf("   w : write current item list to file\n");
      printf("   k : kill current list\n");
      printf("   d : delete item from current list\n");
      printf("   p : print item table\n");
      printf("   c : count number of items\n");
      printf("   f : find total weight of entire list\n");
      printf("   a : add item from keyboard\n");
      printf("   D : duplicate an item already in the list\n"); 
      printf("   A : add item from file testadd.dat\n");
      printf("   W : sort list (greatest-to-least) by Weight\n");
      printf("   C : sort list (greatest-to-least) by Cost\n");
      printf("   N : sort list (least-to-greatest) by Name\n");
      printf("   R : reverse order of current list\n");
      printf("   q : quit\n");
      assert(scanf(" %c", &ch) == 1);
      switch(ch)
      {
      case 'r':
      case 'w':
         printf("Enter file name (<= 255 chars): ");
         assert(scanf("%255s", file) == 1);
         if (ch == 'r')
         {
            if (ip)
               KillAllItems(ip);
            ip = ReadItemsFromFile(file);
         }
         else if (ch == 'w')
            WriteItemsToFile(file, ip);
         break;
      case 'A':                 /* add item from testadd.dat */
         ip = AddItemFromTestFile(ip);
         break;
      case 'k':                 /* k : kill current list */
         KillAllItems(ip);
         ip = NULL;
         break;
      case 'd':                 /* delete item at position */
         printf("Enter item number to delete: ");
         assert(scanf("%d", &i)==1);
         ip = DelItemAtPos(ip, i);
         break;
      case 'D':                 /* d : duplicate current list */
         ip = DupItemInList(ip);
         break;
      case 'p':                 /* p : print item table */
         PrintItemTable(stdout, ip);
         break;
      case 'c':                 /* c : count number of items */
         i = CountItems(ip);
         printf("Number of items in list: %d\n", i);
         break;
      case 'f':                 /* f : find total weight of entire list */
         f = SumItemsWeight(ip);
         printf("Total weight of items in list: %.2f\n", f);
         break;
      case 'W':                 /* W : sort list by Weight */
         ip = SortItemsByWeight(ip);
         break;
      case 'C':                 /* C : sort list by Cost */
         ip = SortItemsByCost(ip);
         break;
      case 'N':                 /* N : sort list by Name */
         ip = SortItemsByName(ip);
         break;
      case 'R':                 /* R : reverse order of current list */
         ip = ReverseItemOrder(ip);
         break;
      case 'q':                 /* q : quit */
         if (ip)
            KillAllItems(ip);
         return(0);
      default:
         printf("Ignoring unknown command '%c'!\n", ch);
      }
      
   }
   return(0);
}
