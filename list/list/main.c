#include <stdio.h>
#include <string.h>
#include "List.h"

void run();
void test();
void manual_test();

int main() {
	run();
	return 0;
}

void run() {
	list_t list = list_new();

	test(list);
	manual_test(list);
	list_free(list);
	getchar();
}

void test(list_t list) {
	size_t i = 0;
	char *elem[] = {"1", "2", "3"};

	for(i; i < 3; i++) {
		list_add(list, (void *) elem[i]);
	}
	
	list_print(list);
}

void manual_test(list_t list) {
	int i = 0;
	int total = atoi(getl("Total (#):"));

	for(i; i < total; i++) {
		list_add(list, (void *) getl("Add:"));
	}

	list_print(list);
}