#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(int argc, char const *argv[])
{
	unsigned x;
	printf("x: ");
	scanf("%x", &x);
	int n;
	while(1){
		printf("n: ");
		scanf("%d", &n);
		printf("r: %x\n", rightrot(x, n));
	}
	
	return 0;
}

unsigned rightrot(unsigned x, int n){
	int bits = 8 * sizeof(x);
	return (x >> n) | (x << (bits - n));
}