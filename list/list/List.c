#include "List.h"

list_t list_new(int new_pool) {
	list_t list;
	list_t pool;
	int i = 0;

	alloc_struct(sizeof(struct List), (void **) &list);
	alloc_struct(sizeof(struct List), (void **) &pool);

	if(new_pool > 0) {
		list->pool_size = new_pool;
	} else {
		list->pool_size = 32;
	}

	init_list(list);
	init_list(pool);
	list->pool = pool;
	init_pool(list);

	return list;
}

void init_list(list_t list) {
	list->head = NULL;
	list->tail = NULL;
	list->prev = NULL;
	list->size = NULL;
	list->curr = NULL;
	list->pool = NULL;
}

void init_pool(list_t list) {
	int i = 0;	

	for(i; i < list->pool_size; i++) {
		list_add_node(list->pool, node_new_data(NULL));
	}
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

node_t list_get_free_node(list_t list) {
	if(!list_peek(list->pool)) {
		init_pool(list);
	}
	
	return list_pop(list->pool);
}

void list_add(list_t list, void *data) {
	node_t node = list_get_free_node(list);
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
	node_t node = list_get_free_node(list);
	node->data = data;
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
	
	node = node_copy(list->head);
	temp = node_copy(list->head->next);		

	node_free(list->head);
	list->head = 0;
	node->next = 0;
	node->prev = 0;
	list_start(list);
	list_dec_size(list);	

	if(temp) {
		list_set_head(list, temp);
	}

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

void list_free(list_t list) {
	list_start(list);

	while(list_next(list))
		node_free(list->curr->prev);

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
