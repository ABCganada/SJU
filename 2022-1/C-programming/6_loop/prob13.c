#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n;
	int sum = 0;
	int cnt = 0;
	double avg;
	scanf("%d", &n);

	while (n > 0) {

		if (n > 100) {
			scanf("%d", &n);
			continue;
		}
		sum += n;
		cnt++;
		scanf("%d", &n);
	}
	avg = (double)sum / cnt;
	printf("%d %.2lf %d", sum, avg, cnt);

	return 0;
}