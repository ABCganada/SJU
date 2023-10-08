#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arrsum(int *a, int *b);

int main()
{
	int n, s, e;
	int x[100];
	int *p;
	scanf("%d%d%d", &n, &s, &e);

	for (p = x; p < x + n; p++) {
		scanf("%d", p);
	}

	printf("%d\n", arrsum(x + s, x + e));


	return 0;
}
int arrsum(int *a, int *b) {
	int sum = 0;
	for (int *i = a; i <= b; i++) {
		sum += *i;
	}


	return sum;
}