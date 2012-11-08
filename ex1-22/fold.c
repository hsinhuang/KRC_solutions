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
		char *s;
		while(len == MAXLINE - 1 && line[len - 2] != '\n'){
			s = fold(line, LINEN);
			printf("%s", s);
			free((void*)s);
			len = readline(line, MAXLINE);
		}
		s = fold(line, LINEN);
		printf("%s", s);
		free((void*)s);
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
	return i;// '\0' not counted
}

char* fold(char* str, int n){
	int length = len(str);
	char* s = (char*)malloc(length * (1 + 3/2) * sizeof(str[0]));
	int si = 0, oi = 0, t;
	// si is the index of first '\0'
	// oi is the index of first not copied element
	while(oi < length-1){
		t = copy(&str[oi], &s[si], n+2);
		int ts = si, to = oi;
		si += t - 1;// si is the index of first '\0'
		oi += t - 1;// oi is the index of first not copied element
		if(s[si-1] == '\n')
			continue;
		char c;
		while((c = s[--si]) != ' ' && c != '\t'){
			if(si < ts)
				goto exception;// I can't find a better way
			--oi;
		}
		if(si < n){
			goto endline;// Forgive me again
		}

		--oi;
		while((c = s[--si]) == ' ' || c == '\t'){
			if(si < ts)
				goto exception;
			--oi;
		}

endline:
		s[++si] = '\n';
		s[++si] = '\0';
		continue;

exception:
		si = ts + t - 1;
		oi = to + t - 1 - 2;
		s[si-2] = '-';
		s[si-1] = '\n';
		s[si] = '\0';
	}

	return s;
}

int copy(char *from, char *to, int n){
	int i = 0;
	while((to[i] = from[i]) != '\0' && i < n)
		++i;
	++i;
	if(i <= n)
		return i;//'\0' is counted
	if(i == n+1){
		to[n-1] = '\0';
		return n;//'\0' is counted
	}

	return -1;// Exception
}

int len(char *str){
	int l = 0;
	while(str[l++] != '\0');

	return l;//'\0' is counted
}