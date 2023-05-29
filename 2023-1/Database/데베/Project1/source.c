#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

double *prefixAvg1(int *arr, int N);	//O(N^2)
double *prefixAvg2(int *arr, int N);	//O(N)

int main()
{
	srand(time(NULL));	
	int n, i, j, arrSize;
	int *arr;
	printf("Enter size of array N : ");
	scanf("%d", &n);	// 배열 사이즈 n 입력
	for (i = 1; i <= 10; i++) {
		arrSize = i * n;	// 테스트할 배열 사이즈는 n, 2n, ,,, 10n
		printf("Size of Array : %d\n", arrSize);

		arr = (int *)malloc(sizeof(int) * (arrSize));	// 테스트 배열 할당
		for (j = 0; j < arrSize; j++) {	
			arr[j] = rand() % 10000 + 1;	// 테스트 배열 원소에 난수 할당
		}
		LARGE_INTEGER ticksPerSec;
		LARGE_INTEGER start, end, diff;

		// 느린 함수 호출 시간 측정
		QueryPerformanceFrequency(&ticksPerSec);	//타이머 주파수 저장
		QueryPerformanceCounter(&start);	//start 시간
		prefixAvg1(arr, arrSize);			//함수 호출
		QueryPerformanceCounter(&end);		//end 시간

		diff.QuadPart = end.QuadPart - start.QuadPart;	//함수 호출 시간
		printf("Time of prefixAvg1 : %.12lf sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		// 빠른 함수 호출 시간 측정
		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		prefixAvg2(arr, arrSize);
		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("Time of prefixAvg2 : %.12lf sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		free(arr);
	}
	return 0;
}
double *prefixAvg1(int *arr, int N) {	//느린 함수
	int i, j, sum;
	double *arrAvg;
	arrAvg = (double *)malloc(sizeof(double) * N);

	for (i = 0; i < N; i++) {
		sum = 0;
		for (j = 0; j <= i; j++) {
			sum += arr[j];
		}
		arrAvg[i] = sum / (double)(i + 1);
	}
	return arrAvg;
}
double *prefixAvg2(int *arr, int N) {	//빠른 함수
	int i;
	double *arrAvg;
	int *sum = (int *)malloc(sizeof(int) * N);
	arrAvg = (double *)malloc(sizeof(double) * N);

	for (i = 0; i < N; i++) {
		if (i == 0)
			sum[i] = arr[i];

		else {
			sum[i] = arr[i] + sum[i - 1];
		}
		arrAvg[i] = sum[i] / (double)(i + 1);
	}
	return arrAvg;
}