#include <stdio.h>
#include <stdlib.h>

void findMaxMin(int arr[], int *max, int *min, int startIdx, int endIdx);

int main() 
{
	int *arr = NULL;
	int i, N, max, min;
	scanf("%d", &N);

	arr = (int *)malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	findMaxMin(arr, &max, &min, 0, N);

	printf("%d %d\n", max, min);

	free(arr);	//메모리해제



	return 0;
}
void findMaxMin(int arr[], int *max, int *min, int startIdx, int endIdx) {
	// Max, Min 찾기
	if (endIdx - startIdx == 1) {
		*max = arr[startIdx];
		*min = arr[startIdx];
	}
	else if (endIdx - startIdx == 2) {
		if (arr[startIdx] > arr[startIdx + 1]) {
			*max = arr[startIdx];
			*min = arr[startIdx + 1];
		}
		else {
			*max = arr[startIdx + 1];
			*min = arr[startIdx];
		}
	}
	else {
		int fMax, bMax;
		int fMin, bMin;
		int middleIdx = (startIdx + endIdx) / 2;
		findMaxMin(arr, &fMax, &fMin, startIdx, middleIdx);
		findMaxMin(arr, &bMax, &bMin, middleIdx, endIdx);

		if (fMax >= bMax)
			*max = fMax;
		else
			*max = bMax;

		if (fMin <= bMin)
			*min = fMin;
		else
			*min = bMin;
	}
}