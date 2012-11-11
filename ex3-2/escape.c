#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int maxline);

int escape(char *s, char *t);
int unescape(char *s, char *t);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	char tmp[MAXLINE];
	while(readline(line, MAXLINE) > 0){
		escape(tmp, line);
		printf("%s\n", tmp);
		unescape(line, tmp);
		printf("%s", line);
	}
	
	return 0;
}

int escape(char *s, char *t){
	int i = 0, j = 0;
	char c;
	while((c = t[j++]) != '\0'){
		switch(c){
			case '\n':
				s[i++] = '\\';
				s[i++] = 'n';
				break;
			case '\t':
				s[i++] = '\\';
				s[i++] = 't';
				break;
			case '\b':
				s[i++] = '\\';
				s[i++] = 'b';
				break;
			case '\\':
				s[i++] = '\\';
				s[i++] = '\\';
				break;
			case '\'':
				s[i++] = '\\';
				s[i++] = '\'';
				break;
			case '\"':
				s[i++] = '\\';
				s[i++] = '\"';
				break;
			default:
				s[i++] = c;
				break;
		}
	}

	s[i] = '\0';
	return i;
}

int unescape(char *s, char *t){
	int i = 0, j = 0;
	char c;
	while((c = t[j++]) != '\0'){
		if(c == '\\' && (c = t[j++]) != '\0'){
			switch(c){
				case 'n':
					s[i++] = '\n';
					break;
				case 't':
					s[i++] = '\t';
					break;
				case 'b':
					s[i++] = '\b';
					break;
				case '\\':
					s[i++] = '\\';
					break;
				case '\'':
					s[i++] = '\'';
					break;
				case '\"':
					s[i++] = '\"';
					break;
				default:
					s[i++] = c;
					break;
			}
		} else {
			s[i++] = c;
		}
	}

	s[i] = '\0';
	return i;
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