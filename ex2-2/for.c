#include <stdio.h>

#define MAXLINE 1000

int readline(char s[], int lim);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	while(readline(line, MAXLINE) > 0){
		printf("%s", line);
	}

	return 0;
}

int readline(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1; ++i){
		if((c = getchar()) != EOF)
			if(c != '\n')
				s[i] = c;
			else
				break;
		else
			break;
	}
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;// '\0' not counted
}