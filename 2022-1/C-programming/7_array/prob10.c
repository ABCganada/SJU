#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int arr[5], rank[5];
	int cnt = 1;
	int tmp;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			
			if (arr[i] < arr[j]) {
				cnt++;
			}
		}
		rank[i] = cnt;
		cnt = 1;
	}

	for (int i = 0; i < 5; i++) {
		printf("%d=r%d ", arr[i], rank[i]);
	}
	printf("\n");

	return 0;
}