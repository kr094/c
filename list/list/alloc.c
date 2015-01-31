#include "alloc.h"

int alloc(int size, void **retptr) {
	void *target = 0;
	
	target = malloc(size);
	if(!target)
		return 0;
		
	*retptr = target;
	return 1;
}
