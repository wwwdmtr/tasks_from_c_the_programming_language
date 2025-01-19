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

void itoa(int n, char s[], int width) {
    int i = 0;              
    int isNegative = 0;    

    if (n < 0) {
        isNegative = 1;
        n = -n; 
    }

    do {
        s[i++] = (n % 10) + '0'; 
        n /= 10;                 
    } while (n > 0);

    if (isNegative) {
        s[i++] = '-';
    }

    while (i < width) {
        s[i++] = '-'; 
    }

    s[i] = '\0';

    reverse(s, i);
}

int main() {
    char buffer[50];

    itoa(123, buffer, 5);
    printf("Result: '%s'\n", buffer); 
    itoa(-42, buffer, 7);
    printf("Result: '%s'\n", buffer); 
    itoa(12345, buffer, 3);
    printf("Result: '%s'\n", buffer);   
    itoa(0, buffer, 4);
    printf("Result: '%s'\n", buffer); 
    return 0;
}
