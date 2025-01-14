#include <stdio.h>

int main(){
	float fahr, celcius;
	int lower, upper, step;
	printf("Fahrenheit to celcius\n");
	for (fahr = 300; fahr >= 0 ; fahr = fahr - 20){
		celcius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celcius);
	}
}



