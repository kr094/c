#include "cgetl.h"

char* cgetl()
{
const long BUFFER = 120;
const long BUFFER_OVERFLOW = BUFFER - 1;
long new_buffer = sizeof(char) * BUFFER;
char *str = (char*) malloc(new_buffer), *err;
long pos;

for(pos = 0; str != 0 && (str[pos] = getchar()) != '\n'; pos++)
{
	if(pos % BUFFER == BUFFER_OVERFLOW)
	{
		new_buffer = sizeof(char) * (BUFFER + pos + 1);
		err = (char*) realloc(str, new_buffer);
		if(err == 0)
		{
			free(str);
		}
		
		str = err;
	}
}

if(str != 0)
{
	str[pos] = '\0';
}

return str;
}
