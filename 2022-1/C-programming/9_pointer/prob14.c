#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_to_k(int *a, int *b);

int main()
{
	int n;
	int d[100];
	int *p;
	int sum = 0;
	scanf("%d", &n);

	for (p = d; p < d + n; p++)
		scanf("%d", p);

	for (p = d; p < d + n; p++) {
		sum += add_to_k(d, p);
	}
	printf("%d\n", sum);

	return 0;
}

int add_to_k(int *a, int *b) {
	int s = 0;
	for (int *i = a; i <= b; i++) {
		s += *i;
	}

	return s;
}