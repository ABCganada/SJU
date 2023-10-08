#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_digits(int N);//정수 N의 각 자리수의 합을 return하는 함수

int main()
{
	int n, min_n;//정수 n과 디지털근이 가장 작은 수를 저장할 min_n
	int sum, min_sum = -1;//각 자릿수의 합을 나타내는 sum, sum의 최솟값 min_sum
	while (1) {
		scanf("%d", &n);//정수 n 스캔
		if (n < 0) break;//n이 음수면 while 탈출

		sum = add_digits(n);//sum 구하기
		while (sum >= 10)//sum이 두 자릿수 이상이면 sum이 한 자릿수가 될 때까지 값을 구함
			sum = add_digits(sum);

		if (min_sum == -1) {//min_sum이 초기값이라면
			min_sum = sum;//최초의 n에 대한 sum 저장
			min_n = n;//최초의 n을 min_n에 저장
		}
		if (min_sum > sum) {//min_sum이 새로 구한 디지털근보다 크다면
			min_sum = sum;//min_sum을 새로 저장
			min_n = n;//min_n을 새로 저장
		}
	}
	printf("%d %d\n", min_n, min_sum);//바깥 while문을 탈출하면 출력



	return 0;

}
int add_digits(int N) {//정수 N의 각 자리수의 합을 return하는 함수
	int sum = 0;//각 자릿수 합을 나타내는 변수
	for (int i = 1; i <= N; i *= 10)//i는 1->10->100처럼 10배씩 증가
		sum += (N / i % 10);//일의 자리부터 sum에 더해감.
	return sum;//sum을 리턴
}