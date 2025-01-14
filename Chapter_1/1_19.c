#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[], int len) 
{
    int c, i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) 
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

int get_line(char s[], int lim) 
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) 
    {
        s[i] = c;
    }
    if (c == '\n') 
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = get_line(line, MAXLINE)) > 0) 
    {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}
