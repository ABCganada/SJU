#include <stdio.h>
#include <stdlib.h>

// 1. 비재귀적 방식 풀이

/**
 * 배열 사용 순차힙 구현
 * 최대힙 구현
 * 배열 idx 0 사용X
 * 힙의 항목은 key만 저장
 * key들은 중복이 없는 1이상의 정수로 가정, (중복검사 필요X)
 * O(1) 공간으로 수행
 * 힙의 최대 항목 수 < 100
*/

int n;

typedef struct __heap{
    int lastIdx;
    int arr[100];
}Heap;

void initHeap(Heap *heap);
void printHeap(Heap *heap);
void downHeap(Heap *heap, int idx);
void rBuildHeap(int idx);
void buildHeap(Heap *heap);
void swap(int *a, int *b);

int main()
{
    Heap H;
    initHeap(&H);

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &H.arr[++H.lastIdx]);
    }

    buildHeap(&H);

    printHeap(&H);

    return 0;
}
void initHeap(Heap *heap){
    heap->lastIdx = 0;
}
void printHeap(Heap *heap){
    for(int i=1; i<=heap->lastIdx; i++){
        printf(" %d", heap->arr[i]);
    }
    printf("\n");
}
void downHeap(Heap *heap, int idx){
    while(idx * 2 <= heap->lastIdx){
        int bigIdx;

        if(idx*2 <= heap->lastIdx && idx*2 + 1 <= heap->lastIdx){
            bigIdx = heap->arr[idx*2] > heap->arr[idx*2 + 1] ? idx*2 : idx*2 + 1;
        } else{
            bigIdx = idx*2;
        }

        if(heap->arr[idx] > heap->arr[bigIdx]){
            break;
        } else{
            swap(&heap->arr[idx], &heap->arr[bigIdx]);
            idx = bigIdx;
        }
    }
}
void buildHeap(Heap *heap){

    for(int i=n/2; i>=1; i--){
        downHeap(heap, i);
    }
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}