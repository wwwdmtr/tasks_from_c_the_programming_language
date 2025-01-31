#include <stdio.h>
#include <string.h>

void reverse(char s[], int start, int end){
	if(start >= end)
		return;
	char temp = s[start];
	s[start] = s[end];
	s[end] = temp;
	reverse(s, start + 1, end - 1);

	

}

int main() {
	char s[] = "Hello World!";
	reverse(s, 0, strlen(s)-1);
	printf("%s", s);
}
