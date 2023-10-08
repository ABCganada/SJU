#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int x[5];
	int tmp;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < 4; i++) {
		if (x[i] > x[i + 1]) {
			tmp = x[i];
			x[i] = x[i + 1];
			x[i + 1] = tmp;
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d\n", x[i]);
	}

	return 0;
}