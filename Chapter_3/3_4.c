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

void itoa(int value, char str[], int base) {
    int i = 0;
    int isNegative = 0;

    if (value < 0) {
        isNegative = 1;
    }
    do {
        int digit = value % base;

        if (digit < 0) {
            digit = -digit;
        }

        str[i++] = (digit > 9) ? (digit - 10) + 'a' : digit + '0';
        value /= base;
    } while (value != 0);

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);
}

int main() {
    char buffer[50];

    itoa(-128, buffer, 10); 
    printf("Result: %s\n", buffer);

    itoa(-2147483648, buffer, 10); 
    printf("Result: %s\n", buffer); 

    return 0;
}
