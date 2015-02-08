#include <stdio.h>
#include "functions.h"
#include "List.h"

void run();
void test();
void manual_test();
void list_dh();

int main() {
	run();
	return 0;
}

void run() {
	list_t list = list_new();
	register_die_handler((die_handler) &list_dh, (void **) &list);

	test(list);
	//manual_test(list);
	list_free(list);
	getchar();
}

void test(list_t list) {
	long i = 10;
	node_t n = 0;

	for(i = 1; i <= 5; i++) {
		list_add(list, (void *) i);
	}

	while(node_print(list_pop(list)));

	//list_prev(list);
	//list_print(list);
	//node_print(list_seek(list, 3));
	//node_print(list_start(list));
	//node_print(list_end(list));

	printf("size %d", list->size);
}

void manual_test(list_t list) {
	int i = 0;
	int total = atoi(getl("Total (#):"));

	for(i; i < total; i++) {
		list_add(list, (void *) getl("Add:"));
	}

	list_printall(list);
}

void list_dh(void *data) {
	list_t list = (list_t) data;

	printf("List size: %d\n", list->size);
	list_free(list);
	run();
}
