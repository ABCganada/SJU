#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);

	if (n == 1) {
		printf("Americano\n");
		m -= 500;
		printf("%d ", m / 500);

		m = m - 500 * (m / 500);
		printf("%d\n", m / 100);
	}

	else if (n == 2) {
		printf("Cafe Latte\n");
		m -= 400;
		printf("%d ", m / 500);

		m = m - 500 * (m / 500);
		printf("%d\n", m / 100);
	}

	else if (n == 3) {
		printf("Lemon Tea\n");
		m -= 300;
		printf("%d ", m / 500);

		m = m - 500 * (m / 500);
		printf("%d\n", m / 100);
	}

	return 0;
}