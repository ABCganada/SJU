#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n;
	int sum;
	int i;
	scanf("%d", &n);

	sum = n;

	while (sum >= 10) {
		sum = 0;
		i = 1;
		while (i <= n) {
			sum += n / i % 10;
			i *= 10;
		}

		if (sum >= 10) {
			n = sum;
		}
	}
	printf("%d\n", sum);

	return 0;
}