#include "die.h"

void register_die_handler(die_handler dh_in, void **dataptr_in) {
	if(dh_in)
		dh = dh_in;
	if(dataptr_in)
		dataptr = dataptr_in;
}

void die(int code, char *message) {
	printf("exit (%d)", code);

	if(message)
		printf(": %s", message);
	puts("");
	
	if(dh)
		(*dh)(dataptr ? *dataptr : NULL);

	getchar();
	exit(code);
}