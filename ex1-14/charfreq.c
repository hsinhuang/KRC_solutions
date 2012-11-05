#include <stdio.h>


int main(int argc, char const *argv[])
{
	int ch[128];
	for (int i = 0; i < 128; ++i)
		ch[i] = 0;

	int c;	
	while((c = getchar()) != EOF){
		ch[c] += 1;
	}

	for (int i = 0; i < 128; ++i){
		if(ch[i] != 0){
			switch(i){
				case '\t':
					printf("'\\t'|");
					break;
				case '\n':
					printf("'\\n'|");
					break;
				default:
					printf(" '%c'| ", i);
					break;
			}
			for (int j = 0; j < ch[i]; ++j){
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}