#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int x[5];
	int tmp;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &x[i]);
	}

	for (int i = 0; i < 4; i++) {
		for (int j = i; j < 5; j++) {
			
			if (x[i] > x[j]) {
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%d\n", x[i]);
	}

	return 0;
}