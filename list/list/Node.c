#include "Node.h"

node_t node_new() {
	node_t node;

	alloc_struct(sizeof(struct Node),(void **) &node);
	node->data = NULL;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

node_t node_new_data(void *data) {
	node_t node = node_new();
	node->data = data;
	return node;
}

node_t node_copy(node_t node) {
	node_t copy = NULL;

	if(node) {
		copy = node_new();
		copy->data = node->data;
		copy->next = node->next;
		copy->prev = node->prev;
	}

	return copy;
}

void node_print(node_t node) {
	if(node) {
		//puts((char *) node->data);
		printf("%d\n", node->data);
	}
}

void node_free(node_t node) {
	free(node);
	node = NULL;
}