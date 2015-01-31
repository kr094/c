#include "getl.h"

char* getl()
{
	const int BUFFER = 120;
	const int BUFFER_OVERFLOW = BUFFER - 1;
	
	char *str, *temp;
	long size = sizeof(char) * BUFFER;
	long pos = 0;
	
	str = malloc(size);
	if(!str)
		return 0;
		
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

