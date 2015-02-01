#ifndef _LIST_H_
#define _LIST_H_
#include "alloc.h"
#include "Node.h"
typedef struct List *list_t;

struct List {
	long size;
	node_t head;
	node_t prev;
	node_t curr;
};

list_t list_new();
void list_free(list_t list);

void list_add(list_t list, void *data);
void list_add_node(list_t list, node_t node);

//void list_unqueue(list_t list);

void list_push(list_t list, void *data);
void list_push_node(list_t list, node_t node);

void list_pop(list_t list);

// Common
void list_set_head(list_t list, node_t node);
void list_inc_size(list_t list);
void list_print(list_t list);
void list_printall(list_t list);

// Navigation
node_t list_peek(list_t list);
node_t list_seek(list_t list, int index);
node_t list_start(list_t list);
node_t list_end(list_t list);
node_t list_next(list_t list);
node_t list_prev(list_t list);
#endif
