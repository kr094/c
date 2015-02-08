#include "functions.h"

char *getl(char *prompt) {
	const int BUFFER = 120;
	const int BUFFER_OVERFLOW = BUFFER - 1;
	
	char *str, *temp;
	long size = sizeof(char) * BUFFER;
	long pos = 0;

	str = (char *) malloc(size);

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