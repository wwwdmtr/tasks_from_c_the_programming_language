#include <stdio.h>

int main() {
	int c, lim = 100;
	for (int i = 0; i < lim-1; ++i){
		c = getchar();
		if (c == EOF){
			break;
		}
		if (c == '\n'){
			break;
		}
	}
}
