#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int len(char *str);
int copy(char *from, char *to, int n);
int readline(char line[], int maxline);
char* detab(char line[], int n);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	while(readline(line, MAXLINE) > 0){
		char *s = detab(line, 8);
		printf("%s", s);
		free((void*)s);
	}

	return 0;
}

char* detab(char line[], int n){
	char *tmp = (char*)malloc(len(line) * n * sizeof(line[0]));
	int i = 0;
	int t = 0;
	char c;
	while((c = line[i++]) != '\0'){
		if(c == '\t'){
			tmp[t++] = ' ';
			while(t%n != 0){
				tmp[t++] = ' ';
			}
		} else {
			tmp[t++] = c;
		}
	}
	tmp[t] = '\0';

	int length = len(tmp);
	char* s = (char*)malloc(length*sizeof(tmp[0]));
	copy(tmp, s, length);
	free((void*)tmp);
	return s;
}

int len(char *str){
	int l = 0;
	while(str[l++] != '\0');

	return l;//'\0' is counted
}


int copy(char *from, char *to, int n){
	int i = 0;
	while((to[i] = from[i]) != '\0' && i < n)
		++i;
	if(i == n)
		to[i-1] = '\0';
	return i;//'\0' is counted
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