#ifndef _ALLOC_H_
#define _ALLOC_H_
#include <stdlib.h>
#include "functions.h"

int alloc(size_t size, void **retptr);
void alloc_struct(size_t size, void **retptr);
#endif
