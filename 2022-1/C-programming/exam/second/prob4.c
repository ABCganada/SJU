#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n;
	int num[20], scr1[20], scr2[20], rank[20];
	int cnt = 0;
	double avg[20];
	char pnp[20];

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		num[i] = i + 1;
		scanf("%d", &scr1[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &scr2[i]);
		avg[i] = (scr1[i] * 0.4) + (scr2[i] * 0.6);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (avg[i] < avg[j]) {
				cnt++;
			}
			else if (avg[i] == avg[j]) {
				if (i == j)
					cnt++;
			}
		}
		rank[i] = cnt;
		cnt = 0;
	}
	for (int i = 0; i < n; i++) {
		if (rank[i] <= n * 0.7 || scr2[i] >= 80)
			pnp[i] = 'P';
		else
			pnp[i] = 'F';
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d %d %.1lf %d %c\n", num[i], scr1[i], scr2[i], avg[i], rank[i], pnp[i]);
	}

	return 0;
}