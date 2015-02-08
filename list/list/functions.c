#include "functions.h"

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

char *getl(char *prompt) {
	const int BUFFER = 120;
	const int BUFFER_OVERFLOW = BUFFER - 1;
	
	char *str, *temp;
	long size = sizeof(char) * BUFFER;
	long pos = 0;

	if(!alloc(size, (void **) &str))
		return 0;

	str = (char *) str;

	if(prompt) {
		say(prompt);
		say(" ");
	}
		
	for(; str && (str[pos] = getchar()) != '\n'; pos++) {		
		if(pos % BUFFER == BUFFER_OVERFLOW) {
			size = sizeof(char) * (BUFFER + pos + 1);
			temp = (char *) realloc(str, size);
			
			if(!temp)
				free(str);
				
			str = temp;
		}		
	}
	
	if(!str)
		return 0;	
	
	str[pos] = '\0';	
	return str;
}

void say(char *message) {
	fputs(message, stdout);
}