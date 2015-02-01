#include "Node.h"

node_t node_new() {
	node_t node;

	alloc_struct(sizeof(struct Node),(void **) &node);
	node->data = 0;
	node->next = 0;
	node->prev = 0;

	return node;
}

node_t node_new_data(void *data) {
	node_t node = node_new();
	node->data = data;
	return node;
}

void node_print(node_t node) {
	if(node)
		puts((char *) node->data);
}

void node_free(node_t node) {
	free(node);
}