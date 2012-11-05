#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c, space = 0, tab = 0, nl = 0;

	while((c = getchar()) != EOF)
	{
		switch(c){
			case ' ':
				space++;
				break;
			case '\t':
				tab++;
				break;
			case '\n':
				nl++;
				break;

		}
	}

	printf("space:%d\ttab:%d\tnewline:%d\n", space, tab, nl);
	return 0;
}