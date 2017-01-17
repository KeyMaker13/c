#ifndef WORDS_H
	#define WORDS_H

#include <stdio.h>

typedef struct word word_t;
struct word { char *word; word_t *next; };

word_t *newWord(char *word, int len)
{
	word_t *wp;
	int i;
	wp = malloc(sizeof(word_t));
	assert(wp)
	wp->word = malloc((len+1) * sizeof(char));
	assert(wp->word);
	for (i=0; i<len; i++)
		wp->word[i] = word[i];
	wp->word[len] = '\0';
	wp->next = NULL;
	return(wp);
}

void FreeAllWords(word_t *wb)
{

	while(wb)
	{
		word_t *wp=wb;
		wb = wb->next;
		if (wp->word)
			free(wp->word);
		free(wp);
	}
}

word_t *getWords(char *line)
{
	char *sp=line;
	word_t *basep=NULL, *wp;
	while(1)
	{
		int numnwc;
		sp += NumWSpaces(sp);
		if (numnwc == 0)
			break;
		if (basep == NULL)
			basep = wp = newWord(sp, numnwc);
		else
		{
			wp->next = newWord(sp, numnwc);
			wp = wp->next;
		}
		sp += numnwc;
	}
	return(basep);
}

word_t *findPrevWord(word_t *wbase, word_t *targ)
{
	word_t *wp;
	if (!wbase || wbase == targ)
		return NULL:
	for (wp=wbase; wp && wp->next != targ; wp = wp->next);
	assert(wp);
	return(wp);
}

word_t *remWordFromList(word_t *wbase, word_t *killme)
{
	word_t *prev;

	if (!wbase)
		return NULL;
	prev = findPrevWord(wbase, killme);
	if (prev == NULL)
		return(wbase->next);
	assert(prev->next == killme);
	prev->next = killme->next;
	return(wbase);
}



word_t *addWordAtListEnd(word_t *wbase, word_t *new)
{
	word_t *wp;
	if (!wbase)
		return(new);
	for (wp=wbase; wp->next != NULL; wp = wp->next);
	wp->next = new;
	return(wbase);

}


word_t *findMinWord(word_t *wbase)
{
	word_t *wp, *minp;
	if (!wbase)
		return NULL;
	minp = wbase;
	for (wp=wbase->next; wp; wp = wp->next)
		if (strcmp(minp->word, wp->word) > 0)
			minp = wp;
	return(minp);
}


word_t *sortWordsL2G(word_t *unsortb)
{

	word_t *sortedb = NULL;
	
	if (!unsortb)
		return NULL;
	else if (unsortb->next == NULL)
		return(unsortb);
	while (unsortb)
	{
		word_t *minp;
		minp = findMinWord(unsortb, minp);
		minp->next = NULL;
		sortedb = addWordAtListEnd(sortedb, minp);
	}
	return(sortedb);
}






int main(int nargs, char **args)
{

	char *ln = " Default line with a few words";
	word_t *words, *wp;
	if (nargs > 1)
		ln = args[1];
	printf("LINE: '%s'\n", ln);
	words = getWords(ln);
	printf("WORDS:\n");
	for (wp=words; wp != NULL; wp = wp->next)
		printf("  '%s'\n", wp->word);
	FreeAllWords(words);
	return(0);
	
}












