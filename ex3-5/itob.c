#include <stdio.h>

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(int argc, char const *argv[])
{
	char s[20];
	int n, base;
	while(1){
		printf(">>> ");
		scanf("%d", &n);
		printf("base: ");
		scanf("%d", &base);
		itob(n, s, base);
		printf("%s\n", s);
	}
	
	return 0;
}

void itob(int n, char s[], int base){
	int i = 0;
	unsigned x = n;
	int t;
	switch(base){
		case 16:
			do{
				t = x%base;
				if(t < 10)
					s[i++] = t + '0';
				else
					s[i++] = t - 10 + 'a';
			} while ((x/=base) > 0);
			s[i++] = 'x';
			s[i++] = '0';
			break;
		case 8:
			do{
				s[i++] = x%base + '0';
			} while ((x/=base) > 0);
			s[i++] = '0';
			break;
		default:
			if(n < 0)
				x = -n;
			do{
				s[i++] = x%base + '0';
			} while ((x/=base) > 0);
			if(n < 0)
				s[i++] = '-';
			break;
	}
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