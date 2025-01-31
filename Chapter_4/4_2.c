#include <ctype.h>
#include <math.h>

double atof(char s[])
{
	double val, power;
	int i, sign, exp_sign = 1, exponent = 0;;
	
	for(i = 0;  isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1:1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E'){
		i++;

		if (s[i] == '-'){
			exp_sign = -1;
			i++;
		} else if (s[i] == '+'){
			i++;
		}

		for (exponent = 0; isdigit(s[i]); i++)
			exponent = 10 * exponent + (s[i] - '0');
		val *= pow(10, exp_sign * exponent);
	}
	return val;
}


//test 

#include <stdio.h>

int main() {
    char s1[] = "123.45e-6";
    char s2[] = "-0.00456E3";
    char s3[] = "3.14159";
    char s4[] = "2.71e2";

    printf("string: %s => number: %g\n", s1, atof(s1));
    printf("string: %s => number: %g\n", s2, atof(s2));
    printf("string: %s => number: %g\n", s3, atof(s3));
    printf("string: %s => number: %g\n", s4, atof(s4));

    return 0;
}
