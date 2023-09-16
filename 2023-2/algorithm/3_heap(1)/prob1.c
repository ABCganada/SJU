#include <stdio.h>
#include <stdlib.h>

/**
 * 배열 사용 순차힙 구현
 * 최대힙 구현
 * 배열 idx 0 사용X
 * 힙의 항목은 key만 저장
 * key들은 중복이 없는 1이상의 정수로 가정, (중복검사 필요X)
 * O(1) 공간으로 수행
 * 힙의 최대 항목 수 < 100
*/

typedef struct __heap{
    int lastIdx;
    int arr[100];
}Heap;

void initHeap(Heap *heap);
void insertItem(Heap *heap, int key);
int removeMax(Heap *heap);
void printHeap(Heap *heap);
void swap(int *a, int *b);

int main()
{
    Heap H;
    initHeap(&H);

    char cmd;
    int key;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'q'){
            break;
        } else if(cmd == 'i'){
            scanf("%d", &key);
            getchar();

            insertItem(&H, key);
            printf("0\n");
        } else if(cmd == 'd'){
            printf("%d\n", removeMax(&H));
        } else if(cmd == 'p'){
            printHeap(&H);
        }
    }





    return 0;
}
void initHeap(Heap *heap){
    heap->lastIdx = 0;
}
void insertItem(Heap *heap, int key){
    heap->arr[++heap->lastIdx] = key;

    int parentIdx = heap->lastIdx / 2;
    int childIdx = heap->lastIdx;

    while(parentIdx > 0){
        if(heap->arr[parentIdx] < heap->arr[childIdx]){
            swap(&heap->arr[parentIdx], &heap->arr[childIdx]);
            childIdx = parentIdx;
            parentIdx /= 2;
        } else{
            break;
        }
    }
}
int removeMax(Heap *heap){
    int ret = heap->arr[1];

    heap->arr[1] = heap->arr[heap->lastIdx--];

    int i = 1;
    while(2*i <= heap->lastIdx){
        int bigIdx;
        if(2*i <=heap->lastIdx && 2*i + 1 <= heap->lastIdx){
            bigIdx = heap->arr[2*i] > heap->arr[2*i +1] ? 2*i : 2*i + 1;
        } else{
            bigIdx = 2*i;
        }
        
        if(heap->arr[i] > heap->arr[bigIdx]){
            break;
        } else{
            swap(&heap->arr[i], &heap->arr[bigIdx]);
            i = bigIdx;
        }
    }

    return ret;
}
void printHeap(Heap *heap){
    for(int i=1; i<=heap->lastIdx; i++){
        printf(" %d", heap->arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}