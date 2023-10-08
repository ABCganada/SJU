#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
	int n, x;	//정수 n, x는 자릿수
	int cnt;	//정수 n의 최대 자릿수
	int tmp = 1;	//조건에 부합할 때마다 자릿수와 계산해주고, 10을 곱해줌
	int even = 0;	//짝수 역수
	int odd = 0;	//홀수 역수
	scanf("%d", &n);	//정수 n 입력 받음

	for (int i = 1; i <= n; i *= 10)	//정수 n의 최대 자릿수 계산
		cnt = i;
	
	for (int i = cnt; i >= 1; i /= 10) {	//짝수의 역순을 계산
		x = n / i % 10;	//각 자릿수를 의미하는 x

		if (x % 2 == 0) {	//조건에 부합한다면
			even += x * tmp;	//가장 낮은 자리부터 차근차근 더해간다
			tmp *= 10;
		}
	}
	printf("%d ", even);	//짝수 역순 출력
	tmp = 1;	//tmp 초기화

	for (int i = cnt; i >= 1; i /= 10) {	//홀수의 역순을 계산
		x = n / i % 10;	//각 자릿수를 의미하는 x

		if (x % 2 == 1) {	//x가 홀수라면
			odd += x * tmp;	//가장 낮은 자리부터 차근차근 더해간다
			tmp *= 10;
		}
	}
	printf("%d\n", odd);	//홀수 역순 출력
	
	return 0;
}