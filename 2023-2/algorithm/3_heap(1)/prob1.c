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

// typedef struct __heap{
//     int lastIdx;
//     int arr[100];
// }Heap;

// 구조체 X, 전역 변수 생성
int heapArr[100];
int lastIdx = 0;
int n;

// void initHeap(Heap *heap);
void insertItem(int key);
int removeMax();
void printHeap();
void swap(int *a, int *b);
void upHeap(int idx);
void downHeap(int idx);

int main()
{
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

            insertItem(key);
            printf("0\n");
        } else if(cmd == 'd'){
            printf("%d\n", removeMax());
        } else if(cmd == 'p'){
            printHeap();
        }
    }





    return 0;
}
// void initHeap(Heap *heap){
//     heap->lastIdx = 0;
// }
void insertItem(int key){
    heapArr[++lastIdx] = key;

    upHeap(lastIdx);
}
int removeMax(){
    int ret = heapArr[1];

    heapArr[1] = heapArr[lastIdx--];
    downHeap(1);

    return ret;
}
void printHeap(){
    for(int i=1; i<=lastIdx; i++){
        printf(" %d", heapArr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void upHeap(int idx){
    int parentIdx = idx/2;

    while(parentIdx > 0){
        if(heapArr[parentIdx] < heapArr[idx]){
            swap(&heapArr[parentIdx], &heapArr[idx]);
            idx = parentIdx;
            parentIdx /= 2;
        } else{
            break;
        }
    }
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