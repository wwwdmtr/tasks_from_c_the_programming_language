
#include <stdio.h>

float celcius (float fahr);

float celcius (float fahr)
{
	float celcius;
	celcius = (5.0/9.0) * (fahr - 32.0);
	return celcius;
}

int main(){
	float fahr;
	int lower, upper, step;
	printf("Fahrenheit to celcius\n");
	for (fahr = 300; fahr >= 0 ; fahr = fahr - 20){
		printf("%3.0f %6.1f\n", fahr, celcius(fahr));
	}
}



