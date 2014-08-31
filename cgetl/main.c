#include <stdio.h>
#include "./cgetl.h"

int main()
{
	char* str = 0;
	while(1)
	{		
		str = cgetl();
		printf("%s\n\n", str);
	}
	return 0;
}
