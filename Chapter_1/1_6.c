#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if ((c = getchar()) != EOF){
			printf("True \n");
		} else {printf("False \n");}

	}
}
