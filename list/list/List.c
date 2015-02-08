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

	return list;
}

void list_free(list_t list) {
	list_start(list);

	while(list_next(list))
		node_free(list->curr->prev);

	free(list);
	list = NULL;
}

node_t list_clean(list_t list) {
	list_init(list);
	return NULL;
}

void list_set_head(list_t list, node_t node) {
	list->head = node;

	if(!list->curr) {
		list->curr = list->head;
		list->prev = NULL;
	}
}

void list_set_tail(list_t list, node_t node) {
	list->tail = node;	

	if(!list->curr) {
		list->curr = list->head;
		list->prev = NULL;
	}
}

void list_add(list_t list, void *data) {
	node_t node = node_new_data(data);
	list_add_node(list, node);
}

void list_add_node(list_t list, node_t node) {
	if(!list->head) {
		list_set_head(list, node);
	} else if(!list->tail) {
		node->prev = list->head;
		list->head->next = node;
		list->tail = node;
	} else {
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
}

void list_push(list_t list, void *data) {
	node_t node = node_new_data(data);
	list_push_node(list, node);
}

void list_push_node(list_t list, node_t node) {
	if(!list->head) {
		list_set_head(list, node);
		list_set_tail(list, node);
	} else {
		node->next = list->head;
		list->head->prev = node;
		list_set_head(list, node);
	}
}

node_t list_pop(list_t list) {
	node_t node = NULL;
	node_t temp = NULL;

	if(!list->head)
		return list_clean(list);
	
	node = node_copy_public(list->head);
	temp = list->head->next;

	if(temp)
		temp->prev = NULL;

	node_free(list->head);	
	list_set_head(list, temp);
	return node;
}

node_t list_unqueue(list_t list) {
	node_t node = NULL;
	node_t temp = NULL;

	if(!list->tail)
		return list_clean(list);

	node = node_copy_public(list->tail);
	temp = list->tail->prev;

	if(temp) 
		temp->next = NULL;

	node_free(list->tail);
	list_set_tail(list, temp);
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
	if(index < 0) //|| index > list->size)
		return list_clean(list);

	list_start(list);
	for(i; i != index; list_next(list), i++);

	return list_peek(list);
}

void list_start(list_t list) {
	if(!list->head)
		list_clean(list);

	if(list->curr != list->head)
		list->curr = list->head;
}

void list_end(list_t list) {
	if(!list->head)
		list_clean(list);

	if(list->curr != list->tail)
		list->curr = list->tail;
}

node_t list_next(list_t list) {
	if(!list->head)
		return list_clean(list);

	if(!list->curr->next) {
		list->curr = NULL;
	} else {
		list->prev = list->curr;
		list->curr = list->curr->next;
	}

	return list_peek(list);
}

node_t list_prev(list_t list) {
	if(!list->head)
		return list_clean(list);

	if(!list->curr) {
		list->curr = list->prev;
	} else if(!list->curr->prev) {
		list->prev = list->curr;
		list->curr = NULL;
	} else {
		list->prev = list->curr;
		list->curr = list->curr->prev;
	}

	return list_peek(list);
}
