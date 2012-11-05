#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
	int len[21];
	for (int i = 0; i < 21; ++i)
		len[i] = 0;

	int c, thislen = 0, state = OUT;

	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			if(state == IN)
				len[thislen] += 1;
			state = OUT;
			thislen = 0;
		} else {
			thislen ++;
			if(state == OUT){
				state = IN;
			}
		}
	}

	for (int i = 0; i < 21; ++i){
		if(len[i] != 0){
			printf("%2d| ", i);
			for (int j = 0; j < len[i]; ++j){
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}