#include <stdio.h>
#include <string.h>

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void itob(int n, char s[], int b) {
    int i = 0;              
    int isNegative = 0;     

    if (n < 0 && b == 10) {
        isNegative = 1;
        n = -n; 
    }

    do {
        int digit = n % b; 
	if (digit > 9) {
            s[i++] = 'a' + (digit - 10);
	} else {
            s[i++] = '0' + digit;        
	}
        n /= b; 
    } while (n > 0);

    if (isNegative) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s, i);
}

int main() {
    char buffer[50];

    itob(123, buffer, 10);
    printf("123 in base 10: %s\n", buffer); // expected: "123"

    itob(255, buffer, 16);
    printf("255 in base 16: %s\n", buffer); // expected:  "ff"

    itob(10, buffer, 2);
    printf("10 in base 2: %s\n", buffer); //  expected: "1010"

    itob(64, buffer, 8);
    printf("64 in base 8: %s\n", buffer); // expected: "100"

    itob(-42, buffer, 10);
    printf("-42 in base 10: %s\n", buffer); // expected: "-42"

    return 0;
}
