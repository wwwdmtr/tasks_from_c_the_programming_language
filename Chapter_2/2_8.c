#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    int word_length = sizeof(unsigned) * 8; 
    n = n % word_length;

 
    unsigned rotated_bits = (x & ((1U << n) - 1)) << (word_length - n);

    x = (x >> n) | rotated_bits;

    return x;
}

int main() {
    unsigned x = 0b10101111; 
    int n = 3;             

    unsigned result = rightrot(x, n);
    printf("Результат: %u (в двоичном: %08b)\n", result, result);

    return 0;
}
