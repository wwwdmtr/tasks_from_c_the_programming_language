#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {

    	unsigned mask = ((1U << n) - 1) << (p + 1 - n);

 
    x ^= mask;

    return x;
}

int main() {
    unsigned x = 0b10101111; 
    int p = 4;             
    int n = 3;              

    unsigned result = invert(x, p, n);
    printf("Результат: %u (в двоичном: %08b)\n", result, result);

    return 0;
}

