#include <stdio.h>
#define IN 1
#define OUT 0
#define TRUE 1
#define FALSE 0


int main(int argc, char const *argv[])
{
	int c, state = OUT, lh = TRUE;

	while((c = getchar()) != EOF){
		if(c == ' ' || c == '\t' || c == '\n'){
			state = OUT;
			if(!lh){
				putchar('\n');
				lh = TRUE;
			}
		}else{
			if(state == OUT){
				state = IN;
			}
			putchar(c);
			lh = FALSE;
		}
	}
	return 0;
}