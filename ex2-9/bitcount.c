#include <stdio.h>

int bitcount(unsigned x);

int main(int argc, char const *argv[])
{
	unsigned x;
	while(1){
		printf("x: ");
		scanf("%x", &x);
		printf("r: %d\n", bitcount(x));
	}
	
	return 0;
}

int bitcount(unsigned x){
	int b = 0;
	while(x){
		x &= (x-1);
		b++;
	}
	return b;
}