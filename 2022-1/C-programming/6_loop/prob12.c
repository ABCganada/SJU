#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n;
	scanf("%d", &n);

	int sum = 0;

	for (int i = 0; ; i++) {
		sum += i;

		if (i == n)
			break;
	}
	printf("%d\n", sum);

	return 0;
}