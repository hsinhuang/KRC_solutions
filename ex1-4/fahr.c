#include <stdio.h>

int main(int argc, char const *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -50;
	upper = 100;
	step = 10;

	celsius = lower;
	printf("celsius fahr\n");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32.0;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}