#include <stdio.h>
#include <stdlib.h>

/**
 * 힙 생성 단계 : 삽입식 or 상향식 사용
 * 순차힙
 * idx 0 사용X
 * 중복 처리 필요X
 * 최대 키 개수 < 100
*/

int H[100];
int n, lastIdx = 0;

void inPlaceHeapSort();
void printArray();
void downHeap(int i);
// void insertItem(int key);
void rBuildHeap(int i);
void swap(int *a, int *b);

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &H[++lastIdx]);
    }

    inPlaceHeapSort();
    lastIdx = n;
    printArray();

    return 0;
}
void inPlaceHeapSort(){
    rBuildHeap(1);

    while(lastIdx>=2){
        swap(&H[1], &H[lastIdx--]);
        downHeap(1);
    }
}
void printArray(){
    for(int i=1; i<=lastIdx; i++){
        printf(" %d", H[i]);
    }
    printf("\n");
}
void downHeap(int i){
    int leftChild;
    int rightChild;
    int bigChild;

    while(2*i <= lastIdx){
        leftChild = 2*i;
        rightChild = 2*i + 1;

        if(rightChild <= lastIdx){
            bigChild = H[leftChild] > H[rightChild] ? leftChild : rightChild;
        } else{
            bigChild = leftChild;
        }

        if(H[i] < H[bigChild]){
            swap(&H[i], &H[bigChild]);
            i = bigChild;
        } else{
            break;
        }
    }
}
void rBuildHeap(int i){
    if(i > lastIdx){
        return;
    }

    rBuildHeap(2*i);
    rBuildHeap(2*i + 1);
    downHeap(i);
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}