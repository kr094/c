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

void list_dh(void *data) {
	list_t list = (list_t) data;

	printf("List size: %d\n", list->size);

	if(list)
		list_free(list);
}

void test(list_t list) {
	long i = 100000;
	node_t n = 0;

	for(i = 0; i < ULLONG_MAX; i++) {
		list_push(list, (void *) rand());
	}

	//while(i--) {
	//	list_push(list, (void *) rand());
	//}

	//list_printall(list);

	//while(n = list_pop(list))
	//	node_print(n);

	//for(i = 0; i < 3; i++) {		
	//	node_print(list_pop(list));
	//}

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
