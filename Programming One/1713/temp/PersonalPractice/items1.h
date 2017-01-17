#ifndef ITEMS1_H
	#define ITEMS1_H

#include <stdio.h>

typedef struct items item_t;
struct items
{
	char name[32];
	float cost, weight;
	int dam;
	item_t *next;
};
