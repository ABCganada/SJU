#include <stdio.h>
#include <stdlib.h>

void searchArray(int arr[], int startIdx, int endIdx, int *buffer);   // 배열 원소 순회 함수
void compareBuffer(int *buffer, int num);   // 버퍼 비교 함수

int main()
{
    int i, N;
    int buffer[2] = {0, };  // 0번째: 가장 큰 수, 1번째: 두 번째로 큰 수
    scanf("%d", &N);    // 배열 사이즈

    int *arr = (int *)malloc(sizeof(int) * N);  // 메모리 할당
    
    for(i=0; i<N; i++)
        scanf("%d", &arr[i]);   // 배열 원소 입력

    searchArray(arr, 0, N, buffer);   // 0부터 N까지 배열 원소 순회 함수 호출
    printf("%d\n", buffer[1]);  // buffer[0]: 가장 큰 수, buffer[1]: 두 번째로 큰 수

    free(arr);  // 메모리 해제

    return 0;
}

void searchArray(int arr[], int startIdx, int endIdx, int *buffer){   // 배열 순회 함수
    if(endIdx-startIdx == 1){   // 순회할 배열의 원소가 1개밖에 없다면
        compareBuffer(buffer, arr[startIdx]);   // 버퍼 비교 함수 호출
    }

    else{   // 순회할 배열의 원소가 2개 이상이라면
        int middleIdx = (startIdx+endIdx) / 2;  // 인덱스를 반으로 자름
        searchArray(arr, startIdx, middleIdx, buffer);    // start ~ middle 순회 함수 호출
        searchArray(arr, middleIdx, endIdx, buffer);      // middle ~ end 순회 함수 호출
    }
}
void compareBuffer(int *buffer, int num){   // 버퍼 비교 함수
    if(num >= buffer[0]){   // num이 버퍼의 0번째 원소보다 크거나 같다면
        buffer[1] = buffer[0];  // 0번째 원소가 1번째 원소를 밀어냄
        buffer[0] = num;    // num이 버퍼의 0번째 자리를 차지함
    }
    else if(num >= buffer[1]){  // 0번째 원소보다는 작지만 1번째 원소보다는 크거나 같다면
        buffer[1] = num;    // num이 버퍼의 1번째 자리를 차지함
    }
}