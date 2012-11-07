#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TAB 8

int len(char *str);
int copy(char *from, char *to, int n);
int readline(char line[], int maxline);
char* entab(char line[], int n);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	while(readline(line, MAXLINE) > 0){
		char *s = entab(line, TAB);
		printf("line: %s", line);
		printf("%s", s); 
		free((void*)s);
	}
	
	return 0;
}

char* entab(char line[], int n){
	int i = len(line);
	char *tmp = (char*)malloc(i * sizeof(line[0]));
	int t = i - 2;
	char c;
	for(i = t; i >= 0; i--){
		c = line[i];
		if(c == ' ' && (i+1)%n == 0){
			tmp[t--] = '\t';
			for (int j = 0; j < n && line[--i] == ' '; ++j);
			i++;
		} else {
			tmp[t--] = c;
		}
	}
	char* newt = &tmp[t+1];
	printf("tmp[t]: %s", &tmp[t]);
	printf("newt: %s", newt);

	int length = len(newt);
	char* s = (char*)malloc(length*sizeof(newt[0]));
	copy(newt, s, length);
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