#include "die.h"

void register_die_handler(die_handler dh_in, void **dataptr_in) {
	if(dh)
		die(1, "register_die_handler: dh already registered");
	if(dh_in)
		dh = dh_in;
	if(dataptr_in)
		dataptr = dataptr_in;
}

void die(int code, char *message) {
	if(dh)
		(*dh)(dataptr ? *dataptr : NULL);

	printf("Exit (%d)", code);

	if(message)
		printf(": %s", message);
	puts("");
	
	getchar();
	exit(code);
}