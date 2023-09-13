#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int findMaxIdx(int *arr, int startIdx, int endIdx);
void selectSort(int arr[], int n);

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    selectSort(arr, n);

    for(int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int findMaxIdx(int *arr, int startIdx, int endIdx){
    int max = arr[0];
    int ret = 0;

    for(int i=startIdx; i<endIdx; i++){
        if(max < arr[i]){
            max = arr[i];
            ret = i;
        }
    }
    return ret;
}
void selectSort(int arr[], int n){
    int pos = n-1;

    for(int i=0; i<n-1; i++){
        int swapPos = findMaxIdx(arr, 1, n-i);
        swap(&arr[swapPos], &arr[pos]);
        pos--;
    }
}