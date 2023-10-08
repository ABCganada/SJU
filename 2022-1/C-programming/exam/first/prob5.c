#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n;
	int ans;
	int tmp = 0;
	int a1 = 0, a2 = 0; //a1 연속 구간 갯수, a2 그 구간 마지막 수
	int max = 0; 
	int min = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &ans);

		if (max == 0 && min == 0) {	//최댓값, 최솟값
			max = ans;
			min = ans;
		}
		if (max < ans)
			max = ans;
		if (min > ans)
			min = ans;				//

		if (ans > 1) {
			for (int j = 2; j <= ans; j++) {	//소수 계산

				if (ans != 2 && ans % j == 0) {
					tmp = 0;
					break;
				}
				else if (ans >= 100) {
					tmp = 0;
					break;
				}

				if (j == ans - 1 || ans == 2) {
					tmp++;
					if (tmp == a1 + 1) {
						a1 = tmp;
						a2 = ans;
					}
					break;
				}
				
			}
		}
	}
	if (a1 != 0) {
		printf("%d\n", a1);
		printf("%d\n", a2);
		printf("%d %d", max, min);
	}

	return 0;
}