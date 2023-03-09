// 누적 평균
// O(N^2), O(N) 비교

#include <stdio.h>
#include <stdlib.h>

double *prefixAvg1(int *ary, int N);
double *prefixAvg2(int *ary, int N);

int main()
{
    int n, i;
    scanf("%d", &n);
    int *arr;
    double *arrAvg1, *arrAvg2;
    arr = (int *)malloc(sizeof(int) * n);

    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    //prefixAverages1 O(n^2)
    arrAvg1 = prefixAvg1(arr, n);
    for(i=0; i<n; i++){        
        arrAvg1[i] += 0.5;
        printf("%d ", (int)arrAvg1[i]);
    }
    printf("\n");

    //prefixAverages2 O(n)
    arrAvg2 = prefixAvg2(arr, n);
    for(i=0; i<n; i++){
        arrAvg2[i] += 0.5;
        printf("%d ", (int)arrAvg2[i]);
    }
    printf("\n");

    free(arr);


    return 0;
}
double * prefixAvg1(int *ary, int N){   //O(n^2)
    int i, j, sum;
    double *aryAvg;
    aryAvg = (double *)malloc(sizeof(double) * N);

    for(i=0; i<N; i++){
        sum = 0;
        for(j=0; j<=i; j++){
            sum += ary[j];
        }
        aryAvg[i] = sum / (double)(i+1);
    }
    return aryAvg;
}
double * prefixAvg2(int *ary, int N){
    int i;
    double *aryAvg;
    int sum[N];
    aryAvg = (double *)malloc(sizeof(double) * N);

    for(i=0; i<N; i++){
        if(i == 0){
            sum[i] = ary[i];
        }
        
        else{
            sum[i] = ary[i] + sum[i-1];
        }
        aryAvg[i] = sum[i] / (double)(i+1);
    }
    return aryAvg;
}