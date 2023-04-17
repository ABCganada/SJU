// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!
// 중간고사 실기 대비 연습문제 풀이입니다!!!!

/*
DS - assignment2
분할 정복
*/

#include <stdio.h>
#include <stdlib.h>

void secondMax(int arr[], int *max1, int *max2, int startIdx, int endIdx);

int main()
{
    int *arr = NULL;
    int i, N, max1, max2;
    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    secondMax(arr, &max1, &max2, 0, N);
    printf("%d\n", max2);
    free(arr);

    return 0;
}
void secondMax(int arr[], int *max1, int *max2, int startIdx, int endIdx){
    if(endIdx - startIdx == 2){
        int num1 = arr[startIdx];
        int num2 = arr[startIdx+1];

        if(num1 >= num2){
            *max1 = num1;
            *max2 = num2;
        }
        else{
            *max1 = num2;
            *max2 = num1;
        }
    }
    else if(endIdx - startIdx == 3){
        int num1 = arr[startIdx];
        int num2 = arr[startIdx+1];
        int num3 = arr[startIdx+2];

        if(num1 >= num2 && num1 >= num3){
            *max1 = num1;
            if(num2 >= num3)
                *max2 = num2;
            else
                *max2 = num3;
        }
        else if(num2 >= num1 && num2 >= num3){
            *max1 = num2;
            if(num1 >= num3)
                *max2 = num1;
            else
                *max2 = num3;
        }
        else{
            *max1 = num3;
            if(num1 >= num2)
                *max2 = num1;
            else
                *max2 = num2;
        }
    }

    else{
        int fMax1, fMax2, bMax1, bMax2;
        int middleIdx = (startIdx + endIdx) / 2;
        secondMax(arr, &fMax1, &fMax2, startIdx, middleIdx);
        secondMax(arr, &bMax1, &bMax2, middleIdx, endIdx);

        if(fMax1 >= bMax1){
            *max1 = fMax1;
            if(bMax1 >= fMax2)
                *max2 = bMax1;
            else
                *max2 = fMax2;
        }
        else{
            *max1 = bMax1;
            if(fMax1 >= bMax2)
                *max2 = fMax1;
            else
                *max2 = bMax2;
        }
    }
}