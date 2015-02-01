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

void list_inc_size(list_t list) {
	list->size++;
}

void list_set_head(list_t list, node_t node) {
	list->head = node;
	list->curr = list->head;
	list_start(list);
}

void list_add(list_t list, void *data) {
	node_t node = node_new_data(data);
	list_add_node(list, node);
}

void list_add_node(list_t list, node_t node) {
	if(!list->head) {
		list_set_head(list, node);
	} else {
		if(list->curr->next)
			list_end(list);

		node->prev = list->curr;
		list->curr->next = node;
		list_next(list);
	}

	list_inc_size(list);
}

void list_push(list_t list, void *data) {
	node_t node = node_new_data(data);
	list_push_node(list, node);
}

void list_push_node(list_t list, node_t node) {
	if(!list->head) {
		list_set_head(list, node);
	} else {
		node->next = list->head;
		list->head->prev = node;
		list_set_head(list, node);
	}

	list_inc_size(list);
}

void list_print(list_t list) {
	do {
		node_print(list_peek(list));
	} while(list_next(list));
}

void list_printall(list_t list) {
	list_start(list);
	list_print(list);
}

void list_free(list_t list) {
	list_start(list);

	do {
		node_free(list->curr->prev);
	} while(list_next(list));

	free(list);
}

node_t list_peek(list_t list) {
	return list->curr;
}

node_t list_seek(list_t list, int index) {
	int i = 1;
	if(index < 0 || index > list->size)
		return NULL;

	list_start(list);
	for(i; i != index; list_next(list), i++);

	return list_peek(list);
}

node_t list_start(list_t list) {
	if(list->head && list->curr->prev) {
		list->curr = list->head;
	}

	list->prev = NULL;

	return list_peek(list);
}

node_t list_end(list_t list) {
	while(list_next(list));

	return list_peek(list);
}

node_t list_next(list_t list) {
	if(!list->curr->next)
		return NULL;

	list->prev = list->curr;
	list->curr = list->curr->next;

	return list_peek(list);
}

node_t list_prev(list_t list) {
	if(!list->curr->prev)
		return NULL;

	list->curr = list->prev;
	list->prev = list->curr->prev;

	return list_peek(list);
}
