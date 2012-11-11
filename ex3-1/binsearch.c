#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, char const *argv[])
{
	int v[5];
	int x;
	printf("v: ");
	scanf("%d %d %d %d %d", &v[0], &v[1], &v[2], &v[3], &v[4]);
	while(1){
		printf("x: ");
		scanf("%d", &x);
		if(x == -1)
			break;
		while(getchar() != '\n');
		printf("r: %d\n", binsearch(x, v, 5));
	}
	
	return 0;
}

int binsearch(int x, int v[], int n){
	int low = 0, high = n - 1;
	int mid = (low + 1)/ 2 + high / 2;
	int t;

	while(low <= high && (t = v[mid]) != x){
		if(t < x)
			low = mid + 1;
		else
			high = mid - 1;
		mid = (low + 1)/ 2 + high / 2;
	}

	if(t == x)
		return mid;
	else
		return -1;
}