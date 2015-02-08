#ifndef _DIE_H_
#define _DIE_H_
#include <stdio.h>
#include <stdlib.h>

typedef void (*die_handler)(void *data);
static die_handler dh;
static void **dataptr;
void register_die_handler(die_handler dh, void **dataptr);

void die(int code, char *message);
#endif