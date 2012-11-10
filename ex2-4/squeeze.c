#include <stdio.h>

#define MAXLINE 1000

void squeeze(char s[], char del[]);

int main(int argc, char const *argv[])
{
	char orig[MAXLINE];
	char del[MAXLINE];

	printf("Original: \n");
	scanf("%s", orig);
	printf("To delete: \n");
	scanf("%s", del);

	squeeze(orig, del);
	printf("%s", orig);

	return 0;
}

void squeeze(char s[], char del[]){
	int i = 0;
	char c;
	while((c = s[i++]) != '\0'){
		if(c == del[0]){
			for (int j = 1; del[j] != '\0'; ++j){
				
			}
		}
	}
}