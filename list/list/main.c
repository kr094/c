#include <stdio.h>

#include "alloc.h"
#include "List.h"

int main() {
	printf("%d", run());
	getchar();
	return 0;
}

int run() {
	struct List *list;
	if(!alloc(sizeof(struct List), (void *) &list))
			return 1;

	return 0;
}