#include <ctype.h>
#include <stdio.h>


int htol(char s[]){
	int i = 0;
	int n = 0;
	int value;

	if (s[i] == '0' && (s[1] = 'x' || s[1] == 'X')){
		i = 2;
	}

	while (s[i] != '\0'){
		if(isdigit(s[i])){
			value = s[i] - '0';
		} else if (tolower(s[i]) >= 'a' && tolower(s[i])<='f'){
			value = tolower(s[i]) - 'a' + 10;
		} else {
			break;
		}
		n = 16 * n + value;
		i++;
	}
	return n;
}

int main() {
	char str[] = "0x1A3F";
	printf("%d",htol(str));
}
