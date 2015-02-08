#include "alloc.h"

int alloc(size_t size, void **retptr) {
	void *target = NULL;
	
	target = malloc(size);
	if(!target)
		return 0;
		
	*retptr = target;
	return 1;
}

void alloc_struct(size_t size, void **retptr) {
	if(!alloc(size, retptr))
		die(1, "alloc_struct: No memory");
}
