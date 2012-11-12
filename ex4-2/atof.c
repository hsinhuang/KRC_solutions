#include <stdio.h>
#include <math.h>

#define MAXLINE 1000

double atof(char s[]);

int main(int argc, char const *argv[])
{
	char line[MAXLINE];
	while(1){
		printf(">>> ");
		scanf("%s", line);
		printf("%f\n", atof(line));
	}
	
	return 0;
}

double atof(char s[]){
	double val = 0.0;
	int i = 0;
	char c;
	while((c = s[i]) == ' ')
		i++;
	int sign = (c == '-') ? -1 : 1;
	if(c == '+' || c == '-')
		i++;
	while('0' <= (c = s[i++]) && c <= '9')
		val = 10.0 * val + (c - '0');
	if(c == '.'){
		double p = 10.0;
		while('0' <= (c = s[i++]) && c <= '9'){
			val += (c - '0') / p;
			p *= 10.0;
		}
	}

	double power = 0.0;
	if(c == 'e' || c == 'E'){
		c = s[i];
		int sg = (c == '-') ? -1 : 1;
		if(c == '+' || c == '-')
			i++;
		while('0' <= (c = s[i++]) && c <= '9')
			power = 10.0 * power + (c - '0');
		power *= sg;
	}

	return sign * val * pow(10.0, power);
}