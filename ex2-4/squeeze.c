#include <stdio.h>

#define MAXLINE 1000

#define TRUE 1
#define FALSE 0

void squeeze(char s[], char del[]);

int main(int argc, char const *argv[])
{
	char orig[MAXLINE];
	char del[MAXLINE];

	printf("Original: ");
	scanf("%s", orig);
	printf("To delete: ");
	scanf("%s", del);

	squeeze(orig, del);
	printf("%s\n", orig);

	return 0;
}

void squeeze(char s[], char del[]){
	int i = -1;
	int j = 0;
	char c, t, match = FALSE;
	while((c = s[++i]) != '\0'){
		if(c == del[0]){
			match = TRUE;
			int k = 1;
			for (; (t = del[k]) != '\0'; ++k){
				if(t != s[i+k]){
					match = FALSE;
					break;
				}
			}
			if(match){
				i += k;
			} else {
				s[j++] = c;
			}
		} else {
			s[j++] = c;
		}
	}
	s[j] = '\0';
}