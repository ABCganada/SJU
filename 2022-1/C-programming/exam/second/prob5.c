#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse_num(int x);
int del_dupnum(int x);

int main()
{
	int n;
	int M;
	int max = 0;
	int maxn = 0;
	scanf("%d", &n);

	while (n >= 0) {
		M = del_dupnum(reverse_num(n));
		printf(" %d", M);

		int tmp = n - M;
		if (tmp < 0)
			tmp = -tmp;

		if (max == 0 && maxn == 0) {
			max = tmp;
			maxn = n;
		}
		if (max < tmp) {
			max = tmp;
			maxn = n;
		}
		scanf("%d", &n);
	}
	printf("\n%d %d\n", maxn, max);
	



	return 0;

}

int reverse_num(int x) {
	int tmp;
	int num = 0;
	while (x > 0) {
		tmp = x % 10;
		x /= 10;
		num = num * 10 + tmp;
	}
	return num;
}
int del_dupnum(int x) {
	int tmp = 0;
	int num = 0;
	int str, ai, aj;

	for (int i = 1; i <= x; i *= 10)
		str = i;

	for (int i = 1; i <= x; i *= 10) {
		ai = (x / (str / i)) % 10;
		for (int j = 1; j <= i; j *= 10) {
			aj = (x / (str / j)) % 10;
			if (ai == aj)
				tmp++;
		}
		if (tmp == 1) {
			num = num * 10 + ai;
		}
		tmp = 0;
	}

	return num;
}