#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;

typedef struct __idx{
    int frontEQ, rearEQ;
}Idx;

Idx idx;

int findPivot(int arr[], int l, int r);
void inPlacePartition(int arr[], int l, int r, int k);
void inPlaceQuickSort(int arr[], int l, int r);
void swap(int *a, int *b);
void printArr(int arr[], int n);

int main()
{
    srand(time(NULL));

    scanf("%d", &N);

    int *arr = (int *)malloc(sizeof(int) * N);

    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    inPlaceQuickSort(arr, 0, N-1);
    printArr(arr, N);

    // inPlacePartition(arr, 0, N-1, 4);


    free(arr);

    return 0;
}
int findPivot(int arr[], int p, int r){
    int pivotIdx = rand() % (r-p+1) + p;

    return pivotIdx;
}
void inPlacePartition(int arr[], int p, int r, int pivotIdx){
    int pivot = arr[pivotIdx];
    // printf("pivot Idx : %d, pivot : %d\n", pivotIdx, pivot);
    int LT = pivot - 1;
    int GT = pivot + 1;

    swap(&arr[pivotIdx], &arr[r]);

    int i = p;
    int j = r-1;

    while(i<=j){
        while(i<=j && arr[i] <= pivot){
            if(arr[i] == pivot && arr[i+1] != pivot && i+1 != j){
                swap(&arr[i], &arr[i+1]);
                continue;
            }
            i++;
        }
        while(i<=j && arr[j] >= pivot){
            if(arr[j] == pivot && arr[j-1] != pivot && j-1 != i){
                swap(&arr[j], &arr[j-1]);
                continue;
            }
            j--;
        }
        if(i < j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[r]);

    while(i<=r && arr[i] == pivot){
        i++;
    }
    idx.rearEQ = --i;

    while(i>=p && arr[i] == pivot){
        i--;
    }
    idx.frontEQ = ++i;

    // printf("%d %d\n", idx.frontEQ, idx.rearEQ);
}
void inPlaceQuickSort(int arr[], int p, int r){
    if(p >= r)
        return;

    int pivot = findPivot(arr, p, r);
    inPlacePartition(arr, p, r, pivot);
    inPlaceQuickSort(arr, p, idx.frontEQ-1);
    inPlaceQuickSort(arr, idx.rearEQ+1, r);
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}