#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Node.h"

//without typedef ... Name, the literal 'struct List' would have to be used.
typedef 
	struct List
	{
		Node* head;
		int size;
	} 
List;

void add(List *list, int val);
void add_b(List *list, int val);
void addToHead(List *list, int val);
void printList(List *list);
void cleanUp(List *list);
#endif
