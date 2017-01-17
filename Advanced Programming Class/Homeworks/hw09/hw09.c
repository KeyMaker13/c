// I took a avl tree and did the assignment
// using scanadt i was not able to free all the memory
// when i type this combination of insert values 10 30 15 or similar values in length
// I get segmentation faults, but when i insert any other number it works fine
#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "strlib.h"
#include "string.h"
#include "simpio.h"
#include "scanadt.h"

typedef struct nodeT {
    int key;
	struct nodeT *left, *right;
    int bf;
} nodeT, *treeT;

static treeT FindNode(treeT t, int key);
static void InsertNode(treeT *tptr, int key);
static int InsertAVL(treeT *tptr, int key);
static void FixLeftImbalance(treeT *tptr);
static void FixRightImbalance(treeT *tptr);
static void RotateLeft(treeT *tptr);
static void RotateRight(treeT *tptr);
static void DisplayTree(treeT t);
static void DisplayStructure(treeT t);
static void RecDisplayStructure(treeT t, int depth, string label);

//methods I added
static int Find(treeT t,int f);
static void ListInorder(treeT t);
static void ListPreorder(treeT t);
static void ListPostorder(treeT t);
static void ListLevelorder(treeT t);
static void Max(treeT t);
static void Min(treeT t);
static int Height(treeT t);
static int Count(void);
static int Sum(treeT t);
static void DeleteNode(treeT *p);
static int Delete(treeT *t, int k);
static int count;


//main program
main()
{

printf("\nTest");
	treeT t;
    t = NULL;
	count = 0;
	int h; 
	int c;
	int s;
	
	// scanadt not good
	scannerADT scanner;
    string line, cmd, key;
	int keyInt;
    scanner = NewScanner();
    SetScannerSpaceOption(scanner, IgnoreSpaces);
    while (TRUE) {
        printf(">");
        line = GetLine();
        SetScannerString(scanner, line);
        cmd = ConvertToLowerCase(ReadToken(scanner));
        if (StringEqual(cmd, "find")) {
            key = ReadToken(scanner);
			keyInt = atoi(key);
			printf("\nSearching for %s, did we find it? : %d\n", key, Find(t,keyInt)); 
			//free(line);
        } else if (StringEqual(cmd, "insert")) {
			key = ReadToken(scanner);
			keyInt = atoi(key);
			InsertNode(&t, keyInt);
			count++;
			DisplayStructure(t);
			//free(line);			
        } else if (StringEqual(cmd, "delete")) {
            key = ReadToken(scanner);
			keyInt = atoi(key);
			Delete(&t, keyInt);
			count--;
			DisplayStructure(t);
			//free(line);
        } else if (StringEqual(cmd, "inorder")) {
           ListInorder(t);
		   printf("\n");
		   //free(line);
        } else if (StringEqual(cmd, "preorder")) {
           ListPreorder(t);
		   printf("\n");
		   //free(line);
        } else if (StringEqual(cmd, "postorder")) {
           ListPostorder(t);
		   printf("\n");
		   //free(line);
        } else if (StringEqual(cmd, "levelorder")){
			ListLevelorder(t);
			printf("\n");
			//free(line);
		} else if (StringEqual(cmd, "max")) {
			printf("\nMax value is:");
			Max(t);
			printf("\n");
			//free(line);
		}
		else if (StringEqual(cmd, "min")) {
			printf("\nMin value is:");
			Min(t);
			printf("\n");
			//free(line);
		}
		
		else if (StringEqual(cmd, "height")) {
			h = Height(t);
			printf("\nHeight is: %d", h);
			//free(line);
		}
		
	    else if (StringEqual(cmd, "count")) {
			c = Count();
			printf("\nCount is: %d", c);
			//free(line);
		}
		 else if (StringEqual(cmd, "sum")) {
			s = Sum(t);
			printf("\nSum is: %d", s);
			//free(line);
		}
		else if (StringEqual(cmd, "quit")) {
			//free(line);
            break;
        } else {
            printf("Unrecognized command: %s\n", line);
			//free(line);
        }
    }
	
	//free(line);
	//free(cmd);
	//free(key);
	FreeScanner(scanner);
}

static treeT FindNode(treeT t, int key)
{
    int sign;

    if (t == NULL) return (NULL);
    //sign = StringCompare(key, t->key);
    if (key > t->key)
	{
		sign = 1;
	} 
	else if (key == t->key)
	{
		sign = 0;
	}
	else
	{
		sign = -1;
	}
	
	if (sign == 0) return (t);
    if (sign < 0) 
	{
        return (FindNode(t->left, key));
    }
	else
	{
        return (FindNode(t->right, key));
    }
}

static void InsertNode(treeT *tptr, int key)
{
    (void) InsertAVL(tptr, key);
}

static int InsertAVL(treeT *tptr, int key)
{
    treeT t;
    int sign, delta;

    t = *tptr;
    if (t == NULL)
	{
        t = New(treeT);
        //t->key = CopyString(key);
        t->key = key;
		t->bf = 0;
        t->left = t->right = NULL;
        *tptr = t;
        return (+1);
    }
   // sign = StringCompare(key, t->key);
    if (key > t->key)
	{
		sign = 1;
	} 
	
	else if (key == t->key){
		sign = 0;
	}
	else
	{
		sign = -1;
	}
	
	if (sign == 0) return (0);
    if (sign < 0)
	{
        delta = InsertAVL(&t->left, key);
        if (delta == 0) return (0);
        switch (t->bf)
		{
          case +1: t->bf =  0; return (0);
          case  0: t->bf = -1; return (+1);
          case -1: FixLeftImbalance(tptr); return (0);
        }
    } 
	else 
	{
        delta = InsertAVL(&t->right, key);
        if (delta == 0) return (0);
        switch (t->bf)
		{
          case -1: t->bf =  0; return (0);
          case  0: t->bf = +1; return (+1);
          case +1: FixRightImbalance(tptr); return (0);
        }
    }
}

static void FixLeftImbalance(treeT *tptr)
{
    treeT t, parent, child, *cptr;
    int oldBF;

    parent = *tptr;
    cptr = &parent->left;
    child = *cptr;
    if (child->bf != parent->bf) 
	{
        oldBF = child->right->bf;
        RotateLeft(cptr);
        RotateRight(tptr);
        t = *tptr;
        t->bf = 0;
        switch (oldBF)
		{
          case -1: t->left->bf = 0; t->right->bf = +1; break;
          case  0: t->left->bf = t->right->bf = 0; break;
          case +1: t->left->bf = -1; t->right->bf = 0; break;
        }
    } 
	else 
	{
        RotateRight(tptr);
        t = *tptr;
        t->right->bf = t->bf = 0;
    }
}

static void RotateLeft(treeT *tptr)
{
    treeT parent, child;

    parent = *tptr;
    child = parent->right;
    parent->right = child->left;
    child->left = parent;
    (*tptr) = child;
}

static void FixRightImbalance(treeT *tptr)
{
    treeT t, parent, child, *cptr;
    int oldBF;

    parent = *tptr;
    cptr = &parent->right;
    child = *cptr;
    if (child->bf != parent->bf) 
	{
        oldBF = child->right->bf;
        RotateRight(cptr);
        RotateLeft(tptr);
        t = *tptr;
        t->bf = 0;
        switch (oldBF) 
		{
          case -1: t->left->bf = 0; t->right->bf = +1; break;
          case  0: t->left->bf = t->right->bf = 0; break;
          case +1: t->left->bf = -1; t->right->bf = 0; break;
        }
    } 
	else 
	{
        RotateLeft(tptr);
        t = *tptr;
        t->left->bf = t->bf = 0;
    }
}

static void RotateRight(treeT *tptr)
{
    treeT parent, child;

    parent = *tptr;
    child = parent->left;
    parent->left = child->right;
    child->right = parent;
    (*tptr) = child;
}

static void DisplayTree(treeT t)
{
    if (t != NULL) {
        DisplayTree(t->left);
        printf("%d\n", t->key);
        DisplayTree(t->right);
    }
}

static void DisplayStructure(treeT t)
{
    RecDisplayStructure(t, 0, NULL);
}

static void RecDisplayStructure(treeT t, int depth, string label)
{
    if (t == NULL) return;
		printf("%*s", 3 * depth, "");
    if (label != NULL) printf("%s: ", label);
		printf("%d (%s%d)\n", t->key, (t->bf > 0) ? "+" : "", t->bf);
	RecDisplayStructure(t->left, depth + 1, "L");
	RecDisplayStructure(t->right, depth + 1, "R");
}

static void ListInorder(treeT t){
	if(t != NULL)
	{
		ListInorder(t->left);
		printf(" %d ",t->key);
		ListInorder(t->right);
	}
}

static void ListPreorder(treeT t){
	if (t != NULL)
	{
		printf(" %d ", t->key);
		ListPreorder(t->left);
		ListPreorder(t->right);
	}
}

static void ListPostorder(treeT t)
{
	if ( t != NULL)
	{
		ListPostorder(t->left);
		ListPostorder(t->right);
		printf(" %d " , t->key);
	}
}
static void ListLevelorder(treeT t)
{
	if (t != NULL)
	{
		printf(" %d ", t->key);
		ListLevelorder(t->left);
		ListLevelorder(t->right);
	}	
}

static void Max(treeT t)
{
	if (t == NULL){
		return;
	}
	if (t->right == NULL){
		printf("\nMax is: %d ", t->key); 
		return;
	}
	else if (t->right != NULL)
	{
		nodeT *tp = t->right;
	
	while(tp->right !=NULL){
		tp = tp->right;
	}
		printf("\nMax is : %d ",tp->key);
		//free(tp);
	}
}

static void Min(treeT t)
{
	if (t == NULL){
		return;
	}
	if (t->left == NULL){
		printf("\nMin is: %d ", t->key);
		return;
	}
	else if (t->right != NULL)
	{
		nodeT *tp = t->left;
		
		while(tp->left != NULL){
			tp = tp->left;
		}
		printf("\nMin is: %d ", tp->key);
		//free(tp);
	}
}

static int Height(treeT t)
{
	int l = 0;
	int r = 0;
	if (t == NULL)
	{
		return 0;
	}
	{
		l = Height(t->left);
		r = Height(t->right);
		if (l > r || l == r)
		{
			return (l+1);
		}
		else
		{
			return (r+1);
		}
	}
}

static int Count(void)
{
	return count;
}
static int Sum(treeT t)
{
	if (t == NULL)	
	{
		return 0;
	}	
	else if (t->right == NULL && t->left == NULL)
	{	
		return (t->key) + Sum(t->right);
	}
	else if (t->right == NULL && t->left !=NULL)
	{
		return (t->key) + Sum(t->left);
	}
	else if (t->left == NULL && t->right !=NULL)
	{
		return (t->key) + Sum(t->right);
	}
	else if (t->right != NULL && t->left != NULL)
	{
		return (t->key) + (Sum(t->right)) + (Sum(t->left));
	}
}

static int Find(treeT t, int f)
{
	if (t == NULL)
		return 0;
	else if (0 == (t->key - f))
	{
		return f;
	}
	else 
	{
		
	 return Find(t->left,f) + Find(t->right,f);
	}
}


static void DeleteNode(treeT *p)
{
nodeT *q, *t, **s;
q = *p;
if(q->left == NULL && q->right == NULL)
*p = NULL;
else if(q->left == NULL)
*p = q->right;
else if(q->right == NULL)
*p = q->left;
else
{
s = &(q->left);
while( (*s)->right != NULL )
s = &((*s)->right);
t = *s;
*s = t->left;
t->right = q->right;
t->left = q->left;
*p = t;
}
free(q);
}

static int Delete(treeT *t, int k)
{
nodeT **p;
p = t;
while( *p != NULL && (*p)->key != k )
{
if(k < (*p)->key)
p = &((*p)->left);
else
p = &((*p)->right);
}
if( *p == NULL )
return (-1);
DeleteNode(p);
return 0;
}
