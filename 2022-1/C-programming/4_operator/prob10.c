#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n, m;
	scanf("%d%d", &n, &m);

	printf("%d\n", n >= m ? n / m : m / n);
	printf("%d\n", n >= m ? n % m : m % n);

	return 0;
}