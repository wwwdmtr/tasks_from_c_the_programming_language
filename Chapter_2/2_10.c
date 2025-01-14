#include <stdio.h>

char lower(char c) {
    return (c >= 'A' && c <= 'Z') ? (c + 32) : c;
}

int main() {
    char input;

    printf("Введите символ: ");
    scanf("%c", &input);

    char result = lower(input);
    printf("Результат: %c\n", result);

    return 0;
}

