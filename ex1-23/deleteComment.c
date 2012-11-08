#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

// string is empty when it contains nothing or only '\n'
int isEmpty(const char* str);
int len(const char *str);
int readline(char line[], int maxline);
// find string `target` in the string `inwhich`
// beginning at index start;
// return the index in the string `inwhich`
// of the first element of string `target`
int find(const char* target, const char* inwhich, int start);
// delete the characters in string `str`
// which the indices range from `start` to `end`(exclusive);
// if `end` = -1, it will
// delete from `start` to the end of string;
// return the new string which need to __free__
char* delete(const char* str, int start, int end);
int copy(const char *from, char *to, int n);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	const char *LINE_COM = "//";
	const char *COM_S = "/*";
	const char *COM_C = "*/";
	int i, j;
	char *s;

	while(readline(line, MAXLINE) > 0){
		if((i = find(LINE_COM, line, 0)) != -1){
			s = delete(line, i, -1);
			if(!isEmpty(s))
				printf("%s\n", s);
			free((void *)s);
		} else if((i = find(COM_S, line, 0)) != -1){
			if((j = find(COM_C, line, 0)) != -1){
				s = delete(line, i, j+2);
				if(!isEmpty(s))
					printf("%s\n", s);
				free((void *)s);
			} else {
				s = delete(line, i, -1);
				if(!isEmpty(s))
					printf("%s\n", s);
				free((void *)s);
				while((j = find(COM_C, line, 0)) == -1)
					readline(line, MAXLINE);
				s = delete(line, 0, j+2);
				if(!isEmpty(s))
					printf("%s", s);
				free((void *)s);
			}
		} else {
			printf("%s", line);
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
	return i;// '\0' not counted
}

int find(const char* target, const char* inwhich, int start){
	int i = start-1;
	char match = FALSE, t, s, t0 = target[0];
	while((s = inwhich[++i]) != '\0'){
		if(s == t0){
			match = TRUE;
			for (int j = 1; (t = target[j]) != '\0'; ++j){
				if (t != (s = inwhich[i+j]) || s == '\0'){
					match = FALSE;
					break;
				}
			}
		}
		if(match == TRUE)
			return i;
	}

	return -1;
}

char* delete(const char* str, int start, int end){
	int length = len(str);
	char *s;
	if(end == -1){
		s = (char*)malloc((start+1) * sizeof(str[0]));
		copy(str, s, start+1);
	} else if(end >= 0){
		s = (char*)malloc((length+end-start) * sizeof(str[0]));
		copy(str, s, start+1);
		copy(&str[end], &s[start], length);
	}
	return s;
}

int len(const char *str){
	int l = 0;
	while(str[l++] != '\0');

	return l;//'\0' is counted
}

int copy(const char *from, char *to, int n){
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

int isEmpty(const char* str){
	if(str[0] == '\0' || (str[0] == '\n' && str[1] == '\0'))
		return 1;
	else
		return 0;
}