#include <stdio.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	char s[20];
	int n, w;
	while(1){
		printf(">>> ");
		scanf("%d", &n);
		printf("width: ");
		scanf("%d", &w);
		itoa(n, s, w);
		printf("%s\n", s);
	}
	
	return 0;
}

void itoa(int n, char s[], int w){
	int i = 0;
	unsigned x = n;
	if(n < 0)
		x = -n;
	do{
		s[i++] = x%10 + '0';
	} while ((x/=10) > 0);
	if(n < 0)
		s[i++] = '-';
	while(i < w)
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s);
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