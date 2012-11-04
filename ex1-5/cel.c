#include <stdio.h>

int main(int argc, char const *argv[])
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("fahr celsius\n");
	for(fahr = upper; fahr >= lower; fahr -= step){
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
	}
	return 0;
}