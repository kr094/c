#include "List.h"

list_t list_new() {
	list_t list;

	alloc_struct(sizeof(struct List), (void **) &list);
	return list_init(list);
}

list_t list_init(list_t list) {
	list->head = NULL;
	list->tail = NULL;
	list->prev = NULL;
	list->curr = NULL;
	list->size = 0;

	return list;
}

void list_free(list_t list) {
	list_start(list);

	while(list_next(list))
		node_free(list->curr->prev);

	free(list);
	list = NULL;
}

void list_inc_size(list_t list) {
	list->size++;
}

void list_dec_size(list_t list) {
	list->size--;
}

void list_set_head(list_t list, node_t node) {
	list->head = node;

	if(!list->curr)
		list->curr = list->head;
}

void list_set_tail(list_t list, node_t node) {
	list->tail = node;
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
	}
	
	list_next(list);
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

node_t list_pop(list_t list) {
	node_t node = NULL;
	node_t temp = NULL;

	if(!list->head)
		return NULL;
	
	node = node_new_data(list->head->data);
	temp = list->head->next;

	if(temp)
		temp->prev = NULL;

	node_free(list->head);	
	list_set_head(list, temp);
	list_dec_size(list);
	return node;
}

void list_print(list_t list) {
	while(list_next(list))
		node_print(list_peek(list));
}

void list_printall(list_t list) {
	list_start(list);
	list_print(list);
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
	if(list->curr != list->head) {
		list->curr = list->head;
		list->prev = NULL;
	}

	return list_peek(list);
}

node_t list_end(list_t list) {
	while(list_next(list));

	return list_peek(list);
}

node_t list_next(list_t list) {
	if(!list->size)
		return NULL;

	list->prev = list->curr;
	list->curr = list->curr->next;

	return list_peek(list);
}

node_t list_prev(list_t list) {
	if(!list->size)
		return NULL;

	list->curr = list->prev;
	list->prev = list->curr->prev;

	return list_peek(list);
}
