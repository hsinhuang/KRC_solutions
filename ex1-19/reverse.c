#include <stdio.h>

#define MAXLINE 1000

// Actually, it is getline in KRC, but when I compiled this file 
// with gcc 4.6.3, there was an error: conflicting types for ‘getline’
// so I changed the name of the function to `readline`
int readline(char line[], int maxline);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	int len;
	while((len = readline(line, MAXLINE)) > 0){
		if(line[len-1] == '\n')
			line[len-1] = '\0';
		reverse(line);
		printf("%s\n", line);
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

void reverse(char s[]){
	int n = -1;
	while(s[++n] != '\0');
	n--;//get the maximum index n

	char tmp;
	for (int i = 0; i <= n / 2; ++i){
		tmp = s[i];
		s[i] = s[n-i];
		s[n-i] = tmp;
	}
	s[n+1] = '\0';
}