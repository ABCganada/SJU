#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n, min;
	scanf("%d", &n);

	min = n / 100 % 10 >= n / 10 % 10 ? n / 10 % 10 : n / 100 % 10;
	min = min >= n % 10 ? n % 10 : min;

	printf("%d\n", min);

	return 0;
}