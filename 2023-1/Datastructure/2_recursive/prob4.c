#include <stdio.h>

int maxNum(int arr[], int N);

int main()
{
    int n, i;
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("%d\n", maxNum(arr, n));

    return 0;
}
int maxNum(int arr[], int N){

    if(N == 1){
        return *arr;
    }
    else{
        int max = maxNum(arr, N-1);
        if(arr[N-1] > max)  // 마지막 원소가 max보다 크면
            return arr[N-1];
        else                // 마지막 원소가 max보다 크지 않으면
            return max;
    }
}