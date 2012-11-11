#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(int argc, char const *argv[])
{
	unsigned x;
	printf("x: ");
	scanf("%x", &x);
	int p, n;
	while(1){
		printf("p: ");
		scanf("%d", &p);
		printf("n: ");
		scanf("%d", &n);
		printf("x: %x\n", x);
		printf("r: %x\n", invert(x, p, n));
	}
	
	return 0;
}

unsigned invert(unsigned x, int p, int n){
	unsigned mask = ~((~0) << n);
	int bias = p - n + 1;
	return x ^ (mask << bias);
}