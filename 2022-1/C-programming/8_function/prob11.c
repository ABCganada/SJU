#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n1, n2, n3;

int conut_strike(int x, int y, int z);
int count_ball(int x, int y, int z);

int main()
{
	scanf("%d%d%d", &n1, &n2, &n3);

	int a1, a2, a3;
	int S = 0, B = 0;

	while (1) {
		scanf("%d%d%d", &a1, &a2, &a3);

		S = count_strike(a1, a2, a3);
		B = count_ball(a1, a2, a3);
		printf("%dS%dB\n", S, B);
		if (S == 3)
			break;
	}

	return 0;

}
int count_strike(int x, int y, int z) {
	int s = 0;

	if (x == n1)
		s++;
	if (y == n2)
		s++;
	if (z == n3)
		s++;
	return s;
}
int count_ball(int x, int y, int z) {
	int b = 0;

	if (x == n2 || x == n3) {
		if (x != n1)
			b++;
	}
	if (y == n1 || y == n3) {
		if (y != n2)
			b++;
	}
	if (z == n1 || z == n2) {
		if (z != n3)
			b++;
	}
	return b;
}

