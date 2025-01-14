#include <stdio.h>

int bitcount(int x) {
    int count = 0;
    while (x) {
        x &= (x - 1); 
	count++;
    }
    return count;
}

int main() {
    int number;

    printf("Введите число: ");
    scanf("%d", &number);

    int result = bitcount(number);
    printf("Количество единиц в двоичной записи числа %d: %d\n", number, result);

    return 0;
}
