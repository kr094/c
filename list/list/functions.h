#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "die.h"

int alloc(size_t size, void **retptr);
void alloc_struct(size_t size, void **retptr);
char* getl(char *prompt);
void say(char *message);
#endif