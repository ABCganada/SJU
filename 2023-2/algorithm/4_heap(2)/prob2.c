#include <stdio.h>
#include <stdlib.h>

int H[100];
int n, lastIdx = 0;

void inPlaceHeapSort();
void printArray();
void downHeap(int i);
void buildHeap();
void swap(int *a, int *b);

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &H[++lastIdx]);
    }

    inPlaceHeapSort();
    printArray();

    return 0;
}
void inPlaceHeapSort(){
    buildHeap();


    for(int i = lastIdx; i>=2; i--){
        swap(&H[1], &H[i]);
        lastIdx--;
        downHeap(1);
    }

    lastIdx = n;
}
void printArray(){
    for(int i=1; i<=lastIdx; i++){
        printf(" %d", H[i]);
    }
    printf("\n");
}
void downHeap(int i){
    int leftChild, rightChild, bigChild;

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
void buildHeap(){

    for(int i=lastIdx/2; i>=1; i--){
        downHeap(i);
    }
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
