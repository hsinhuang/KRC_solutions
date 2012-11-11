#include <stdio.h>

int lower(int c);

int main(int argc, char const *argv[])
{
	char x;
	while(1){
		printf("x: ");
		x = getchar();
		while(getchar() != '\n');
		printf("r: %c\n", lower(x));
	}
	
	return 0;
}

int lower(int c){
	return ('A' <= c && c <= 'Z') ? (c + 'a' - 'A') : c;
}