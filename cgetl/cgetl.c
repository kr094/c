#include "cgetl.h"
char *cgetl()
{
 const int BUFFER = 120;
 const int BUFFER_OVERFLOW = BUFFER - 1;
 char *str = (char*)malloc(sizeof(char) * BUFFER), *err;
 int pos;
  
 for(pos = 0; str != 0 && (str[pos] = getchar()) != '\n'; pos++)
 {
	if(pos % BUFFER == BUFFER_OVERFLOW)
    {
	       if((err = (char*)realloc(str, sizeof(char) * (BUFFER + pos + 1))) == 0)
		      free(str);
        str = err;
    }
 }
 if(str != 0)
	str[pos] = '\0';
	
 return str;
}
