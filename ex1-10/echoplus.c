#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;

	while((c = getchar()) != EOF){
		switch(c){
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;
			default:
				putchar(c);
				break;
		}
	}
	return 0;
}