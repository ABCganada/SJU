#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void selectSort(int arr[], int n);
void insertSort(int arr[], int n);
void swap(int* a, int* b);
int findMaxIdx(int arr[], int startIdx, int endIdx);

int main_A()
{
	srand(time(NULL));
	int n, i, j, arrSize;
	int* arr;
	printf("Enter size of array N : ");
	scanf("%d", &n);	// 배열 사이즈 n
	printf("***A. 정렬이 안 된 데이터***\n\n");
	printf("A. a) 동일한 n으로 여러 번 실험\n");
	for (i = 1; i <= 10; i++) {
		arrSize = n;	// 테스트 배열 사이즈 n, 2n, ... 10n
		printf("Size of Array : %d\n", arrSize);

		arr = (int*)malloc(sizeof(int) * (arrSize));	// 테스트 배열 할당
		for (j = 0; j < arrSize; j++) {
			arr[j] = rand() % 10000 + 1;	// 테스트 배열 원소에 난수 할당
		}
		LARGE_INTEGER ticksPerSec;
		LARGE_INTEGER start, end, diff;

		QueryPerformanceFrequency(&ticksPerSec);	//타이머 주파수 저장
		QueryPerformanceCounter(&start);	//start 시간
		selectSort(arr, arrSize);			//선택 정렬 함수 호출
		QueryPerformanceCounter(&end);		//end 시간

		diff.QuadPart = end.QuadPart - start.QuadPart;	//함수 호출 시간
		printf("Time of Select Sort : %.12lf\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		// 빠른 함수 호출 시간 측정
		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		insertSort(arr, arrSize);			//삽입 정렬 함수 호출
		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("Time of Insert Sort : %.12lf\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		free(arr);
	}

	printf("A. b) 배열 사이즈 n이 증가함\n");
	for (i = 1; i <= 10; i++) {
		arrSize = i*n;	// 테스트 배열 사이즈 n, 2n, ... 10n
		printf("Size of Array : %d\n", arrSize);

		arr = (int*)malloc(sizeof(int) * (arrSize));	// 테스트 배열 할당
		for (j = 0; j < arrSize; j++) {
			arr[j] = rand() % 10000 + 1;	// 테스트 배열 원소에 난수 할당
		}
		LARGE_INTEGER ticksPerSec;
		LARGE_INTEGER start, end, diff;

		QueryPerformanceFrequency(&ticksPerSec);	//타이머 주파수 저장
		QueryPerformanceCounter(&start);	//start 시간
		selectSort(arr, arrSize);			//선택 정렬 함수 호출
		QueryPerformanceCounter(&end);		//end 시간

		diff.QuadPart = end.QuadPart - start.QuadPart;	//함수 호출 시간
		printf("Time of Select Sort : %.12lf\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		// 빠른 함수 호출 시간 측정
		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		insertSort(arr, arrSize);			//삽입 정렬 함수 호출
		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("Time of Insert Sort : %.12lf\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

		free(arr);
	}

	return 0;
}
void selectSort(int arr[], int n) {
	int pos = n - 1;

	for (int i = 0; i < n - 1; i++) {
		int swapPos = findMaxIdx(arr, 1, n - i);
		swap(&arr[swapPos], &arr[pos]);
		pos--;
	}
}
void insertSort(int arr[], int n) {
	int j;

	for (int i = 0; i < n; i++) {
		int insertElem = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insertElem) {
				arr[j + 1] = arr[j];
				continue;
			}

			break;
		}

		arr[j + 1] = insertElem;
	}
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int findMaxIdx(int arr[], int startIdx, int endIdx) {
	int max = arr[0];
	int ret = 0;

	for (int i = startIdx; i < endIdx; i++) {
		if (max < arr[i]) {
			max = arr[i];
			ret = i;
		}

		return ret;
	}
}

