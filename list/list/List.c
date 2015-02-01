#include "List.h"

list_t list_new() {
		list_t list;

		alloc_struct(sizeof(struct List), (void **) &list);
		list->head = 0;
		list->prev = 0;
		list->size = 0;
		list->curr = 0;

		return list;
}

void list_add(list_t list, void *data) {
	node_t node = node_new_data(data);
	list_add_node(list, node);
}

void list_add_node(list_t list, node_t node) {
	if(!list->head) {
		list->head = node;
		list->curr = list->head;
	} else {
		if(list->curr->next)
			list_end(list);

		node->prev = list->curr;
		list->curr->next = node;
		list_next(list);
	}

	list->size++;
}

void list_print(list_t list) {
	list_start(list);
	do {
		puts((char *) list_curr(list));
	} while(list_next(list));
}

void list_free(list_t list) {
	list_start(list);

	do {
		free(list->curr->prev);
	} while(list_next(list));

	free(list);
}

node_t list_peek(list_t list) {
	return list->curr;
}

void *list_curr(list_t list) {
	return list->curr->data;
}

node_t list_start(list_t list) {
	if(list->curr->prev)
		list->curr = list->head;

	return list_peek(list);
}

node_t list_end(list_t list) {
	if(list->curr->next) {
		do {
			list_next(list);
		} while(list->curr->next); 
	}

	return list_peek(list);
}

node_t list_next(list_t list) {
	list->prev = list->curr;

	if(!list->curr->next)
		return NULL;

	list->curr = list->curr->next;
	return list_peek(list);
}

node_t list_prev(list_t list) {
	list->curr = list->prev;

	if(!list->curr->prev)
		return NULL;

	list->prev = list->curr->prev;
	return list_peek(list);
}
