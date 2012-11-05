#include <stdio.h>

#define MAXLINE 1000
#define LEN 80

// Actually, it is getline in KRC, but when I compiled this file 
// with gcc 4.6.3, there was an error: conflicting types for ‘getline’
// so I changed the name of the function to `readline`
int readline(char line[], int maxline);

int main(int argc, char const *argv[])
{
	int len;
	char line[MAXLINE];
	while((len = readline(line, MAXLINE)) > 0){
		if(len > LEN){
			while(len == MAXLINE - 1 && line[len - 2] != '\n'){
				printf("%s", line);
				len = readline(line, MAXLINE);
			}
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
	return i;
}