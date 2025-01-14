#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim)
{
	int c, i, lastChar = 0;
	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (!((c == ' ' || c == '\t') &&
		(lastChar == ' ' || lastChar == '\t')))
		{
			s[i] = c;
			lastChar = c;
		} else {
			--i;
		}
	}
	s[i++] = '\0';
	return i;
	
}

int main()
{
	int len;
	char line[MAXLINE];
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > 0)
		{
			printf("%s", line);
			putchar('\n');
		}
	
	return 0;
}
