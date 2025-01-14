#include <stdio.h>

int main() 
{
	int c, i, length, counter;
	int maxwordslength[20];

	for (i = 0; i < 20; ++i )
		maxwordslength[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c != ' ' && c != '\n' && c != '\t' )
		{
			++counter;
		} else
		{
			++maxwordslength[counter];
			counter = 0;
		}
	}
	printf(" word length histogram \n");
	for (i = 1; i < 20; ++i )
	{
		printf("%2d ", i);
		for (int j = 0; j < maxwordslength[i]; j++)
		{
			putchar('-');
		}
		putchar('\n');
	}
		
}
