#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int a, b, c, ans, max, min;
	scanf("%d%d%d", &a, &b, &c);

	max = a >= b && a >= c ? a : b;				//최댓값 찾기
	max = c >= a && c >= b ? c : max;

	min = a <= b && a <= c ? a : b;				//최솟값 찾기
	min = c <= a && c <= b ? c : min;

	ans = a != max && a != min ? a : b;			//중앙값 찾기
	ans = c != max && c != min ? c : ans;

	printf("%d\n", ans);

	return 0;
}