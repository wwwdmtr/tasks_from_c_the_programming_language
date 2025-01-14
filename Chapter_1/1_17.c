#include <stdio.h>
#define MAXLINE 1000


int get_line(char line[], int lim);
void copy(char to[], char from[]);

int main() 
{
	int len;
	int min_chars = 80;
	char line[MAXLINE];
	char enoughChars[MAXLINE];
	char allLines[MAXLINE];
	int pos = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > min_chars) 
		{
			int i = 0;
			while (line[i] != '\0' && pos < MAXLINE) 
			{
				enoughChars[pos++] = line[i++];
			}
		}
	enoughChars[pos] = '\0';
	if (pos > 0)
	{
		printf("%s%s","\nAll strings that have enough Chars: \n",  enoughChars);
	}
}
int get_line(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy (char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != EOF)
		++i;
}

