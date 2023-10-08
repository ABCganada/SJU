#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int count_3(int x);

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", count_3(n));

	return 0;

}
int count_3(int x) {
	int cnt = 0;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= i; j *= 10) {
			if (i / j % 10 == 3)
				cnt++;
		}
	}
	return cnt;
}