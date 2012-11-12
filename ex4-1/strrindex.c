#include <stdio.h>

#define MAXLINE 1000

int len(char *str);
int strrindex(char *s, char *t);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	char tofind[MAXLINE];
	printf(">>> ");
	scanf("%s", line);
	while(1){
		printf("find: ");
		scanf("%s", tofind);
		printf("%d\n", strrindex(line, tofind));
	}
	
	return 0;
}

int strrindex(char *s, char *t){
	int tl = len(t)-1;
	int i, j, n;
	if(tl < 0)
		return -1;
	for (n = len(s)-1; n >= 0; --n){
		for (i = n, j = tl; i >= 0 && j >= 0 && s[i] == t[j]; i--, j--)
			;
		if(j == -1)
			return i+1;
	}

	return -1;
}

int len(char *str){
	int l = -1;
	while(str[++l] != '\0');

	return l;//index of '\0'
}