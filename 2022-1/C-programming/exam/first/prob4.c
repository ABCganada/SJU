#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n, x;
	int tmp;
	int ans = 0;
	int cnt = 1;
	int cnt3 = 0;
	int max = 0, min = 0;
	scanf("%d", &n);

	while (n != 0) {
		for (int i = 1; i <= n; i *= 10) {
			tmp = i;
		}

		for (int i = tmp; i >= 1; i /= 10) {
			x = n / i % 10;
			ans += x * cnt;
			cnt *= 10;
			
		}
		ans += n * tmp * 10;
		if (max == 0 && min == 0) {
			max = ans;
			min = ans;
		}
		if (max < ans)
			max = ans;
		if (min > ans)
			min = ans;

		for (int i = 1; i <= ans; i *= 10) {
			x = ans / i % 10;
			if (x == 3)
				cnt3++;
		}

		printf("%d %d ", ans, cnt3);
		cnt = 1;
		cnt3 = 0;
		ans = 0;
		scanf("%d", &n);
	}
	printf("\n%d %d\n", min, max);

	return 0;
}