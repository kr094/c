#ifndef _LIST_H_
#define _LIST_H_

#include "alloc.h"
#include "Node.h"
typedef struct List *list_t;

struct List {
	long size;
	node_t head;
	node_t curr;
	node_t prev;
};

list_t list_new();
void list_add(list_t list, void *data);
void list_add_node(list_t list, node_t node);
void list_print(list_t list);
void list_free(list_t list);

// Navigation
node_t list_peek(list_t list);
void *list_curr(list_t list);
node_t list_start(list_t list);
node_t list_end(list_t list);
node_t list_next(list_t list);
node_t list_prev(list_t list);
#endif
