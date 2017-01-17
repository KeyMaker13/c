#include <stdio.h>
#include "genlib.h"
#include "strlib.h"
#include "buffer.h"

#define MaxCharsPerBlock 3

/* Types */
typedef struct cellT {
    char chA[MaxCharsPerBlock];
    //char ch;
	struct cellT *prev, *next;
	int count;
} cellT;

struct bufferCDT {
    cellT *start;
	//cellT *end;
    cellT *cursor;
};

/*
 * Implementation notes: NewBuffer
 * -------------------------------
 * This function allocates an empty editor buffer, represented
 * as a linked list.  To simplify the link list operation, this
 * implementation adopts the useful programming tactic of
 * keeping an extra "dummy" cell at the beginning of each list,
 * so that the empty buffer has the following representation:
 *
 *     +-------+          +------+
 *     |   o---+-----====>|      |
 *     +-------+    /     +------+
 *     |   o---+---/      | NULL |
 *     +-------+          +------+
 */

bufferADT NewBuffer(void)
{
    bufferADT buffer;
    buffer = New(bufferADT);
    buffer->start =  New(cellT *);
	buffer->cursor = New(cellT *);
	//buffer->end = New(cellT *);
	buffer->start->next = NULL;
	buffer->start->prev = buffer->start;
	buffer->cursor = buffer->start;
    return (buffer);
}

/*
 * Implementation notes: FreeBuffer
 * --------------------------------
 * FreeBuffer must free every cell in the buffer as well as
 * the buffer storage itself.  Note that the loop structure
 * is not exactly the standard idiom for processing every
 * cell within a linked list, because it is not legal to
 * free a cell and later look at its link field.  To avoid
 * selecting fields in the structure after it has been freed,
 * you have to copy the link pointer before calling FreeBlock.
 */

void FreeBuffer(bufferADT buffer)
{
/*
    cellT *cp, *next;

    cp = buffer->start;
    while (cp != NULL) {
        next = cp->next;
        FreeBlock(cp);
        cp = next;
    }
    FreeBlock(buffer);
*/
	cellT *cp, *next, *prev;
	cp = buffer->start;
	while(cp != NULL) {
		next = cp->next;
		prev = cp->prev;
		FreeBlock(cp);
		cp = prev;
		FreeBlock(cp);
		cp = next;
	}
}

void MoveCursorForward(bufferADT buffer)
{
/*
    if (buffer->cursor->next != NULL) {
        buffer->cursor = buffer->cursor->next;
    }
*/
	
	if (buffer->cursor->count == 3){
		if (buffer->cursor->next != NULL){
			buffer->cursor = buffer->cursor->next;
			}
	
	}

}

void MoveCursorBackward(bufferADT buffer)
{
/*
    cellT *cp;

    if (buffer->cursor != buffer->start) {
        cp = buffer->start;
        while (cp->next != buffer->cursor) {
             cp = cp->next;
        }
        buffer->cursor = cp;
		}
*/
	if (buffer->cursor->count == 0){
		if (buffer->cursor->prev != NULL){
			buffer->cursor = buffer->cursor->prev; 
		}
	}
}

void MoveCursorToStart(bufferADT buffer)
{
    buffer->cursor = buffer->start;
}

void MoveCursorToEnd(bufferADT buffer)
{

    while (buffer->cursor->next != NULL) {
        MoveCursorForward(buffer);
    }

//buffer->cursor = buffer->end;
}

void InsertCharacter(bufferADT buffer, char ch)
{	
	// allocate memory
	//	if (buffer->cursor == NULL ){
	//	printf("here also\n");
	//	cellT *cp;
	//	cp = New(cellT *);
	//	
	////	cp->next = buffer->cursor->next;
	//	cp->prev = buffer->cursor;
		
	//	cp->count=0;
	//	
	//	buffer->cursor->next = cp;
	//	buffer->cursor = cp;
		
		
	//	free(cp->chA);
	//	free(cp);
	//	}
		
		
		
		// link boxes 
		
		
		//cp->next = buffer->cursor->next;
		//cp->prev = buffer->cursor->prev;		
		//buffer->cursor->next = cp;
		//buffer->cursor = cp;
	
	// insert data into array
    //cp->ch = ch;
    // original
	
	//mine below
	
	
	if (buffer->cursor == NULL){
		cellT *cp;
		cp = New(cellT *);
		cp->chA[0] = ch;
		cp->count = 1;
		cp->next = NULL;
		//cp->next = buffer->cursor->next;
		cp->prev = buffer->cursor;		
		buffer->cursor->next = cp;
		buffer->cursor = cp;
	
	}else if (buffer->cursor->count == 0){
		buffer->cursor->chA[0] = ch;
		buffer->cursor->count++;
		printf("here one\n");
	}
	else if (buffer->cursor->count == 1){
		buffer->cursor->chA[1] = ch;
		buffer->cursor->count++;
		printf("here two\n");
	}
	else if (buffer->cursor->count == 2){
		buffer->cursor->chA[2] = ch;
		buffer->cursor->count++;
		printf("here three\n");
		buffer->cursor = buffer->cursor->next;
}	
	/*
	else if (buffer->cursor->count == 3){
		cellT *cp;
		cp = New(cellT *);
		
		cp->next = buffer->cursor->next;
		cp->prev = buffer->cursor;		
		cp->count=0;
		
		buffer->cursor->next = cp;
		buffer->cursor = cp;
		
		
		//free(cp->chA);
		//free(cp);
	
	
	
	
	
	
	
	
		buffer->cursor = buffer->cursor->next;
		//free(cp);
		//buffer->cursor->chA[0] = ch;
		//buffer->cursor->prev = buffer->cursor;
		//buffer->cursor->count-3;
	}
	*/
	
}

void DeleteCharacter(bufferADT buffer)
{
    cellT *cp,*cpPrev;

    if (buffer->cursor->next != NULL) {
        cp = buffer->cursor->next;
		cpPrev = buffer->cursor;
        buffer->cursor->next = cp->next;
		buffer->cursor->prev = cp->prev;
        FreeBlock(cp);
		FreeBlock(cpPrev);
		
    }
}

void DisplayBuffer(bufferADT buffer)
{
    cellT *cp;
int i = 0;
    for (cp = buffer->start; cp != NULL; cp = cp->next) {
        for(i = 0; i < 3; i++){
			printf("%c", cp->chA[i]);
		
			}
	
    }
    printf("\n");
    for (cp = buffer->start; cp != buffer->cursor; cp = cp->next) {
               for(i = 0; i < 3; i++){
			printf("  ");
		
			}
	
    }
    printf("^\n");
}