#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define LINEN 10

int len(char *str);
int readline(char line[], int maxline);
char* fold(char* str, int n);
int copy(char *from, char *to, int n);

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];
	while((len = readline(line, MAXLINE)) > 0){
		for (int i = 0; i < LINEN; ++i){
			putchar('*');
		}
		putchar('\n');
		char *s = fold(line, LINEN);
		printf("%s", s);
		free((void*)s);
		while(len == MAXLINE - 1 && line[len - 2] != '\n'){
			char *s = fold(line, LINEN);
			printf("%s", s);
			free((void*)s);
			len = readline(line, MAXLINE);
		}
	}
	
	return 0;
}

int readline(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

char* fold(char* str, int n){
	int length = len(str);
	char* s = (char*)malloc(length * (1 + 3/2) * sizeof(str[0]));
	int si = 0, oi = 0, t;
	// si is the index of first '\0'
	// oi is the index of first not copied element
	while(oi < length){
		// printf("%s\n", s);
		t = copy(&str[oi], &s[si], n);// bias of '\0'
		si += t - 1;
		oi += t - 1;
		while(s[--si] != ' ')
			--oi;
		--oi;
		while(s[--si] == ' ')
			--oi;
		s[++si] = '\n';
		s[++si] = '\0';
	}

	return s;
}

int copy(char *from, char *to, int n){
	int i = 0;
	while((to[i] = from[i]) != '\0' && i < n)
		++i;
	if(i == n)
		to[i-1] = '\0';
	return i;//'\0' is counted
}

int len(char *str){
	int l = 0;
	while(str[l++] != '\0');

	return l;//'\0' is counted
}