#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void secondMax(int*, int*, int*, int, int);// 두번째로 큰 수를 찾는 재귀함수

int main()
{
    int n, * a, max = 0, max2 = 0;
    scanf("%d", &n);//n값 입력
    a = (int*)malloc(sizeof(int) * n);//동적할당
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    secondMax(a, &max, &max2, 0, n);//max=최대값, max2=두번째로 큰 값
    printf("%d\n", max2);

    free(a);//동적할당 해제
    return 0;
}

void secondMax(int* a, int* max, int* max2, int start, int end)
{
    int firstmax, firstmax2, lastmax, lastmax2;
    /*firstmax = 반으로 나누어 왼쪽에 있는 배열 중 최대값
    firstmax2= 반으로 나누어 왼쪽에 있는 배열 중 두번째로 큰 값
    lastmax= 반으로 나누어 오른쪽에 있는 배열 중 최대값
    lastmax2= 반으로 나누어 오른쪽에 있는 배열 중 두번째로 큰 값
    */
    if (end - start <=1) {//구간이 1 이하일 경우
        *max = a[start];
        *max2 = -9999999;
    }
    else if (end - start == 2) {//구간이 2일경우
        if (a[start] > a[start + 1]) {
            *max = a[start];//최대값
            *max2 = a[start + 1];//두번째로 큰 수
        }
        else {
            *max = a[start + 1];//최대값
            *max2 = a[start];//두번째로 큰 수
        }
    }
    else {//구간이 3이상일경우

        secondMax(a, &firstmax, &firstmax2, start, (end + start) / 2);//반으로 나눈 후 왼쪽 배열 재귀
        secondMax(a, &lastmax, &lastmax2, (end+start) / 2, end);//반으로 나눈 후 오른쪽 배열 재귀
        if (firstmax >= lastmax) {//왼쪽 배열의 최대값이 오른쪽 배열의 최대값보다 클때
            *max = firstmax;//최대값을 왼쪽배열의 최대값으로 저장
            if (firstmax2 >= lastmax) {//왼쪽배열의 두번째로 큰 수가 오른쪽 배열의 최대값 보다 클때
                *max2 = firstmax2;//두번째로 큰 수를 왼쪽배열의 두번째 큰 수로 저장
            }
            else {//왼쪽배열의 두번째로 큰 수가 오른쪽 배열의 최대값보다 작을때
                *max2 = lastmax;//두번째로 큰 수를 오른쪽 배열의 최대값으로 저장
            }
        }
        
        else {//왼쪽배열의 최대값 보다 오른쪽배열의 최대값이 더 클 경우
            *max = lastmax;//최대값을 오른쪽배열의 최대값으로 저장
            if (lastmax2 >= firstmax) {//오른쪽 배열의 두번째로 큰 값이 왼쪽 배열의 최대값보다 클 경우
                *max2 = lastmax2;//두번째로 큰 값을 오른쪽 배열의 두번째로 큰 값으로 저장
            }
            else {//오른쪽 배열의 두번째로 큰 값이 왼쪽배열의 최대값보다 작은 경우
                *max2 = firstmax;//두번째로 큰 값을 왼쪽 배열의 최대값으로 저장
            }
        }
    }
}