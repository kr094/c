#ifndef _NODE_H_
#define _NODE_H_
#include "alloc.h"
typedef struct Node *node_t;

struct Node {
	void *data;
	node_t prev;
	node_t next;
};

node_t node_new();
node_t node_new_data(void *data);
node_t node_copy(node_t node);

int node_print(node_t node);
void node_free(node_t node);
#endif