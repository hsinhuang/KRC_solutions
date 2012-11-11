#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(int argc, char const *argv[])
{
	unsigned x, y;
	printf("x: ");
	scanf("%x", &x);
	printf("y: ");
	scanf("%x", &y);
	int p, n;
	while(1){
		printf("p: ");
		scanf("%d", &p);
		printf("n: ");
		scanf("%d", &n);
		printf("x: %x\n", x);
		printf("r: %x\n", setbits(x, p, n, y));
	}
	
	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned mask = ~((~0) << n);
	int bias = p - n + 1;
	return (x & ~(mask << bias)) | ((y & mask) << bias);
}