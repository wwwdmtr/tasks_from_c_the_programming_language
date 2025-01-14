#include <stdio.h>

#define ASCII_RANGE 128
int main() 
{
	int c;
	int quantity[ASCII_RANGE];
	
	for (int i = 0; i < ASCII_RANGE; i++)
	{
		quantity[i] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c >= 0 && c < ASCII_RANGE)
		{
			++quantity[c];
		}
	}
	printf("Chars quantity histogram\n");
	for (int i = 32; i < ASCII_RANGE - 2; i++) //all visible characters in 
						   //ASCII have ids from 32 to 
						   //126
		
	{
		putchar(i);
		if (quantity[i] > 0 ) 
		{
			printf(": ");
			for (int j = 0; j < quantity[i]; j++)
				putchar('-');
		}
		putchar('\n');
	}
		
}
