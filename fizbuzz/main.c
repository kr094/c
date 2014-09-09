#include <stdio.h>

int main(void)
{
	fizzbuzz(1);
	return 0;
}

int fizzbuzz(int n)
{
	if(n > 100)
	{
		return;
	}
	
	if(n % 5 == 0 && n % 3 == 0)
	{
		puts("fizzbuzz");
	}
	else if(n % 5 == 0)
	{
		puts("fizz");
	}
	else if(n % 3 == 0)
	{
		puts("buzz");
	}
	else
	{
		printf("%d\n", n);
	}
	
	fizzbuzz(++n);
}
