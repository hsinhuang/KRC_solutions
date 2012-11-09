#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAXCHAR 10000
#define MAXLINE 1000
#define TRUE 1
#define FALSE 0
#define NOTMATCHED 'm'
#define REDUNDANT 'r'

struct error{
	char id;
	char type;// error type: NOTMATCHED or REDUNDANT
	int line;// line number
	int column;// column number
};
int errprint(struct error *e);

struct bracket{
	char id;
	int line;// line number
	int column;// column number
};

struct bracket *NewBracket(char id, int line, int column){
	struct bracket* b = (struct bracket*)malloc(sizeof(struct bracket));
	b->id = id;
	b->line = line;
	b->column = column;
	return b;
}

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
void elim_quote(char *str);
// pointer returned by this function need to __free__
// return when meets **one** error
struct error* bracketMatch(const char* str);

int main(int argc, char const *argv[]){
	char str[MAXCHAR];
	int str_i = 0;
	char line[MAXLINE];
	const char *LINE_COM = "//";
	const char *COM_S = "/*";
	const char *COM_C = "*/";
	int i, j;
	char *s;

	while(readline(line, MAXLINE) > 0){
		if((i = find(LINE_COM, line, 0)) != -1){
			s = delete(line, i, -1);
			str_i += copy(s, &str[str_i], MAXLINE) - 1;
			free((void *)s);
		} else if((i = find(COM_S, line, 0)) != -1){
			if((j = find(COM_C, line, 0)) != -1){
				s = delete(line, i, j+2);
				str_i += copy(s, &str[str_i], MAXLINE) - 1;
				free((void *)s);
			} else {
				s = delete(line, i, -1);
				printf("%s\n", s);
				free((void *)s);
				while((j = find(COM_C, line, 0)) == -1)
					readline(line, MAXLINE);
				s = delete(line, 0, j+2);
				str_i += copy(s, &str[str_i], MAXLINE) - 1;
				free((void *)s);
			}
		} else {
			str_i += copy(line, &str[str_i], MAXLINE) - 1;
		}
	}
	printf("1: %s\n", str);
	elim_quote(str);
	printf("2: %s\n", str);
	struct error *err = bracketMatch(str);
	if(err != NULL){
		errprint(err);
		free(err);
	} else {
		printf("OK\n");
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

int errprint(struct error *e){
	char* s = (e->type == NOTMATCHED) ? "Not matched" : "Redundant";
	return printf("%s '%c' in Line %d, Column %d\n",
					s, e->id, e->line, e->column);
}

struct error* bracketMatch(const char* str){
	struct bracket *b;
	struct stack *brackets = NewStack();
	struct error *err = (struct error*)malloc(sizeof(struct error*));
	err->line = 1;
	err->column = 1;

	int i = 0;
	char c;
	while((c = str[i++]) != '\0'){
		switch(c){
			case '\n':
				err->line++;
				err->column = 1;
				continue;
			case '(':
				b = NewBracket('(', err->line, err->column);
				Push(b, brackets);
				break;
			case '[':
				b = NewBracket('[', err->line, err->column);
				Push(b, brackets);
				break;
			case '{':
				b = NewBracket('{', err->line, err->column);
				Push(b, brackets);
				break;
			case ')':
				if(isEmpty(brackets)){
					goto redundant;
				} else {
					b = (struct bracket*)Pop(brackets);
					if(b->id != '('){
						goto notmatched;
					} else {
						free(b);
					}
				}
				break;
			case ']':
				if(isEmpty(brackets)){
					goto redundant;
				} else {
					b = (struct bracket*)Pop(brackets);
					if(b->id != '['){
						goto notmatched;
					} else {
						free(b);
					}
				}
				break;
			case '}':
				if(isEmpty(brackets)){
					goto redundant;
				} else {
					b = (struct bracket*)Pop(brackets);
					if(b->id != '{'){
						goto notmatched;
					} else {
						free(b);
					}
				}
				break;
		}
		err->column++;
	}

	if(!isEmpty(brackets)){
		b = (struct bracket*)Pop(brackets);
		goto notmatched;
	} else {
		free(err);
		return NULL;
	}

notmatched:
	err->type = NOTMATCHED;
	err->id = b->id;
	err->line = b->line;
	err->column = b->column;
	free(b);
	goto ret;

redundant:
	err->type = REDUNDANT;
	err->id = c;
	goto ret;

ret:
	while(!isEmpty(brackets)){
		b = (struct bracket*)Pop(brackets);
		free(b);
	}
	free(brackets);
	return err;
}

void elim_quote(char *str){
	const char *D_Q = "\"";
	const char *S_Q = "\'";

	const int length = len(str);
	char c;
	int t;
	for (int i = 0; i < length-1; ++i){
		if((c = str[i]) == '\"'){
			if((t = find(D_Q, str, i+1)) == -1){
				t = length;
				goto excep1;
			}
			while(str[t-1] == '\\'){
				int j = t-1;
				while(str[--j] == '\\');
				if((t - 1 - j) % 2 == 0)
					goto excep1;
				t = find(D_Q, str, t+1);
			}
excep1:		while(i <= t && i < length-1 && str[i] != '\n'){
				str[i++] = ' ';
			}
			i--;
		} else if(c == '\''){
			if((t = find(S_Q, str, i+1)) == -1){
				t = length;
				goto excep2;
			}
			while(str[t-1] == '\\'){
				int j = t-1;
				while(str[--j] == '\\');
				if((t - 1 - j) % 2 == 0)
					goto excep2;
				t = find(S_Q, str, t+1);
			}
excep2:		while(i <= t && i < length-1 && str[i] != '\n'){
				str[i++] = ' ';
			}
			i--;
		}
	}
}