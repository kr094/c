#ifndef _LIST_H_
#define _LIST_H_
#include "alloc.h"
#include "Node.h"
typedef struct List *list_t;

struct List {
	node_t head;
	node_t tail;
	node_t prev;
	node_t curr;
	
	long size;
	long pool_size;
	list_t pool;
};

list_t list_new(int pool_size);
void list_free(list_t list);
void init_list(list_t list);
void init_pool(list_t list);
node_t list_get_free_node(list_t list);

void list_add(list_t list, void *data);
void list_push(list_t list, void *data);

void list_add_node(list_t list, node_t node);
//void list_unqueue(list_t list);

void list_push_node(list_t list, node_t node);
node_t list_pop(list_t list);

// Common
void list_set_head(list_t list, node_t node);
void list_set_tail(list_t list, node_t node);
void list_inc_size(list_t list);
void list_dec_size(list_t list);
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
