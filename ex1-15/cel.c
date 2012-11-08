#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

double f2c(double fahr);

int main(int argc, char const *argv[])
{
	int fahr;
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
		printf("%3d %6.1f\n", fahr, f2c(fahr));
	}

	return 0;
}

double f2c(double fahr){
	return (5.0/9.0) * (fahr - 32);
}