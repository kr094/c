#include "Node.h"

node_t node_new() {
	node_t node;

	alloc_struct(sizeof(struct Node),(void **) &node);
	node->id = guid_new();
	return node_init(node);
}

node_t node_init(node_t node) {	
	node->data = NULL;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

node_t node_blank() {
	node_t node;

	alloc_struct(sizeof(struct Node),(void **) &node);
	return node_init(node);
}

node_t node_new_data(void *data) {
	node_t node = node_new();
	node->data = data;
	return node;
}

node_t node_copy(node_t node) {
	node_t copy = node_blank();	
	copy->id = node->id;
	copy->data = node->data;
	copy->next = node->next;
	copy->prev = node->prev;

	return copy;
}

node_t node_copy_public(node_t node) {
	node_t copy = node_blank();
	copy->id = node->id;
	copy->data = node->data;

	return copy;
}

int node_print(node_t node) {
	if(!node)
		return 0;

	printf("%d", node->data);
	printf("\t%s\n", node->id);
	
	return 1;
}

void node_free(node_t node) {
	free(node);
	node = NULL;
}