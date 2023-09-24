#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * findKthSmallest()의 인자 L은 buildList한 L이어야만 함 
 * O(n) + O(k logn)
 * 힙 생성 : O(n)
 * k번째 작은 원소 찾기 : O(k logn)
*/

int miniTestSize = 10;      //미니 테스트의 배열 사이즈
int testSize = 100000;      //테스트의 배열 사이즈

int findKthSmallest(int arr[], int *n, int k);
int *buildList(int n, int min, int max);
void printList(int arr[], int n);
void buildHeap(int arr[], int i, int n);
void downHeap(int arr[], int i, int n);
void swap(int *a, int *b);

int main()
{
    int *L = buildList(miniTestSize, 1, 100);     //1~100까지 10개의 정수 무순리스트 생성

    buildHeap(L, 1, miniTestSize);    //힙 생성

    printList(L, miniTestSize);       //L 출력

    int output[4];
    for(int k=1; k<=3; k++){
        //전역 변수 size가 findKthSmallest 함수 상에서 변동되기 때문에 
        //함수 호출 전 size 고정시킴
        miniTestSize = 10;

        output[k] = findKthSmallest(L, &miniTestSize, k);  //10개 원소의 정수 무순리스트 L의 k번째 작은 원소 찾기
        printf(" %d", output[k]);   
    }
    printf("\n");

    free(L);

    L = buildList(testSize, 1, 1000000);

    int kArray[4] = {1, 100, 99900, 99999};
    int e, t;
    for(int k=0; k<4; k++){
        testSize = 100000;

        e = findKthSmallest(L, &testSize, kArray[k]);
        printf(" %d\n", e);
    }

    return 0;
}
int findKthSmallest(int arr[], int *n, int k){

    buildHeap(arr, 1, *n);  //힙 생성 함수 : O(N)

    int small;      //return값
    int cnt = 0;

    while(cnt < k){ //cnt가 k가 될 때까지 최소힙을 정렬한다.
        cnt++;
        small = arr[1];
        swap(&arr[1], &arr[(*n)--]);
        downHeap(arr, 1, *n);   //downHeap() : O(logN)
    }

    return small;
}
int *buildList(int n, int min, int max){

    int *arr = (int *)malloc(sizeof(int) * (n+1));
    
    srand(time(NULL));  //난수 생성 초기화

    for(int i=1; i<=n; i++){
        arr[i] = rand()%max + min;  //min ~ max까지 난수 생성
    }

    return arr;
}
void printList(int arr[], int n){

    for(int i=1; i<=n; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}
void buildHeap(int arr[], int i, int n){

    if(i <= n){
        buildHeap(arr, 2*i, n);
        buildHeap(arr, 2*i+1, n);
        downHeap(arr, i, n);
    }
}
void downHeap(int arr[], int i, int n){

    // k번째 원소를 찾을 때, O(k logn) 시간에 찾기 위해 최소힙으로 구현
    
    int leftChild, rightChild, bigChild;

    while(2*i <= n){
        leftChild = 2*i;
        rightChild = 2*i+1;

        if(rightChild <= n){
            bigChild = arr[leftChild] < arr[rightChild] ? leftChild : rightChild;
        } else{
            bigChild = leftChild;
        }

        if(arr[i] > arr[bigChild]){
            swap(&arr[i], &arr[bigChild]);
            i = bigChild;
        } else{
            break;
        }
    }
}
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}