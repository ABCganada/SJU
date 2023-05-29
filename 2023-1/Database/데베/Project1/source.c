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
	scanf("%d", &n);	// �迭 ������ n �Է�
	for (i = 1; i <= 10; i++) {
		arrSize = i * n;	// �׽�Ʈ�� �迭 ������� n, 2n, ,,, 10n
		printf("Size of Array : %d\n", arrSize);

		arr = (int *)malloc(sizeof(int) * (arrSize));	// �׽�Ʈ �迭 �Ҵ�
		for (j = 0; j < arrSize; j++) {	
			arr[j] = rand() % 10000 + 1;	// �׽�Ʈ �迭 ���ҿ� ���� �Ҵ�
		}
		LARGE_INTEGER ticksPerSec;
		LARGE_INTEGER start, end, diff;

		// ���� �Լ� ȣ�� �ð� ����
		QueryPerformanceFrequency(&ticksPerSec);	//Ÿ�̸� ���ļ� ����
		QueryPerformanceCounter(&start);	//start �ð�
		prefixAvg1(arr, arrSize);			//�Լ� ȣ��
		QueryPerformanceCounter(&end);		//end �ð�

		diff.QuadPart = end.QuadPart - start.QuadPart;	//�Լ� ȣ�� �ð�
		printf("Time of prefixAvg1 : %.12lf sec\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		// ���� �Լ� ȣ�� �ð� ����
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
double *prefixAvg1(int *arr, int N) {	//���� �Լ�
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
double *prefixAvg2(int *arr, int N) {	//���� �Լ�
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