#include <stdio.h>
#include <stdlib.h>

// 1. 비재귀적 방식 풀이: buildHeap()
// 2. 재귀적 방식 풀이: rbuildHeap()

/**
 * 배열 사용 순차힙 구현
 * 최대힙 구현
 * 배열 idx 0 사용X
 * 힙의 항목은 key만 저장
 * key들은 중복이 없는 1이상의 정수로 가정, (중복검사 필요X)
 * O(1) 공간으로 수행
 * 힙의 최대 항목 수 < 100
*/

// typedef struct __heap{
//     int lastIdx;
//     int arr[100];
// }Heap;

// 구조체 X, 전역 변수 생성
int heapArr[100];
int lastIdx = 0;
int n;

// void initHeap(Heap *heap);
void printHeap();
void downHeap(int idx);
void rBuildHeap(int idx);
void buildHeap();
void swap(int *a, int *b);

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &heapArr[++lastIdx]);
    }

    // buildHeap(&H);
    rBuildHeap(1);

    printHeap();

    return 0;
}
// void initHeap(Heap *heap){
//     heap->lastIdx = 0;
// }
void printHeap(){
    for(int i=1; i<=lastIdx; i++){
        printf(" %d", heapArr[i]);
    }
    printf("\n");
}
void downHeap(int idx){
    while(idx * 2 <= lastIdx){
        int bigIdx;

        if(idx*2 <= lastIdx && idx*2 + 1 <= lastIdx){
            bigIdx = heapArr[idx*2] > heapArr[idx*2 + 1] ? idx*2 : idx*2 + 1;
        } else{
            bigIdx = idx*2;
        }

        if(heapArr[idx] > heapArr[bigIdx]){
            break;
        } else{
            swap(&heapArr[idx], &heapArr[bigIdx]);
            idx = bigIdx;
        }
    }
}
void rBuildHeap(int idx){
    if(idx > lastIdx)
        return;
    
    rBuildHeap(idx*2);
    rBuildHeap(idx*2 + 1);
    downHeap(idx);
}
void buildHeap(){

    for(int i=n/2; i>=1; i--){
        downHeap(i);
    }
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}