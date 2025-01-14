#include <stdio.h>


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ((1U << n) - 1) << (p + 1 - n);


    unsigned y_bits = (y & ((1U << n) - 1)) << (p + 1 - n);


    x &= ~mask;

    x |= y_bits;

    return x;
}

int main() {
    unsigned x = 0b10101111;
    unsigned y = 0b00110011;
    int p = 4;              
    int n = 3;              

    unsigned result = setbits(x, p, n, y);
    printf("Результат: %u (в двоичном: %08b)\n", result, result);

    return 0;
}
