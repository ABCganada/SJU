#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int x);
int next_prime(int x);

int main()
{
	int n, m;
	int cnt = 0;
	int ans;
	scanf("%d%d", &n, &m);
	while (cnt != m) {
		ans = next_prime(n);
		if (ans != 0) {
			printf(" %d", ans);
			cnt++;
		}
		n++;
	}

	return 0;

}
int is_prime(int x) {
	int tmp = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0)
			tmp++;
	}
	if (tmp == 2)
		return 1;
	else
		return 0;
}
int next_prime(int x) {

	for (int i = x + 1; ; i++) {
		if (is_prime(i)) 
			return i;
		else
			return 0;
	}
}