#include <stdio.h>

#define MAXLINE 1000

int readline(char line[], int maxline);

int expand(char *s1, char *s2);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	char tmp[MAXLINE];
	while(readline(line, MAXLINE) > 0){
		expand(line, tmp);
		printf("%s", tmp);
	}
	
	return 0;
}

int expand(char *s1, char *s2){
	int i = 0, j = 0;
	char b, e;
	while((b = s1[i++]) != '\0'){
		if(s1[i] == '-' && (e = s1[i+1]) != '\0'){
			s2[j++] = b;
			if('a' <= b && b <= 'z' && 'a' <= e && e <= 'z'){
				while(b++ < e)
					s2[j++] = b;
				i+=2;
			} else if('A' <= b && b <= 'Z' && 'A' <= e && e <= 'Z'){
				while(b++ < e)
					s2[j++] = b;
				i+=2;
			} else if('0' <= b && b <= '9' && '0' <= e && e <= '9'){
				while(b++ < e)
					s2[j++] = b;
				i+=2;
			} else {
				s2[j++] = '-';
				i++;
			}
		} else {
			s2[j++] = b;
		}
	}

	s2[j] = '\0';
	return j;
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