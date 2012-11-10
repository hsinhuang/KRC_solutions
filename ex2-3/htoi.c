#include <stdio.h>

#define MAXLINE 1000

int htoi(const char *s);
int len(const char *s);

int main(int argc, char const *argv[])
{
	char s[MAXLINE];
	printf(">>> ");
	scanf("%s", s);

	printf("%d\n", htoi(s));
	return 0;
}

int htoi(const char *s){
	char c;
	int i = 0, n = 0;
	if(len(s) > 2 && s[0] == '0' && ((c = s[1]) == 'x' || c == 'X')){
		i = 2;
	}
	while((c = s[i++]) != '\0'){
		if('0' <= c && c <= '9')
			n = 16 * n + (c - '0');
		else if('a' <= c && c <= 'f')
			n = 16 * n + 10 + (c - 'a');
		else if('A' <= c && c <= 'F')
			n = 16 * n + 10 + (c - 'A');
		else
			break;
	}

	return n;
}

int len(const char *s){
	int i = 0;
	while(s[i++] != '\0');
	return i;//'\0' counted
}