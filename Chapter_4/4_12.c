#include <stdio.h>

void printNumber(int x) {
	if (x < 0){
		putchar('-');
		x = -x;
	}
	if (x / 10){
		printNumber(x / 10);
	}
	putchar(x % 10 + '0');
}

int main() {
	printNumber(1234);

}
