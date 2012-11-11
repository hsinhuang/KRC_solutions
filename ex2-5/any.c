#include <stdio.h>

#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int any(const char* s1, const char* s2);

int main(int argc, char const *argv[])
{
	char inwhich[MAXLINE];
	char find[MAXLINE];
	printf("Find in: ");
	scanf("%s", inwhich);
	printf("Find which: ");
	scanf("%s", find);

	printf("%d\n", any(inwhich, find));
	
	return 0;
}

int any(const char* s1, const char* s2){
	char c, t;
	for (int i = 0; (c = s1[i]) != '\0'; ++i){
		for (int j = 0; (t = s2[j]) != '\0'; ++j){
			if(c == t)
				return i;
		}
	}
	return -1;
}