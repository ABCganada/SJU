#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/**
 * findKthSmallest()의 인자 L은 buildList한 L이어야만 함
 * O(n) + O(k logn)
 * 힙 생성 : O(n)
 * k번째 작은 원소 찾기 : O(k logn)
*/

int miniTestSize = 10;      //미니 테스트의 배열 사이즈
int testSize = 100000;      //테스트의 배열 사이즈


//mini test와 test 모두에서 함수 사용이 가능하도록 배열 사이즈 n을 파라미터로 받도록 한다.
int findKthSmallest(int arr[], int* n, int k);  //O(N + klogN) 시간에 k번째 작은 원소를 반환하는 함수
int* buildList(int n, int min, int max);    //n개의 정수를 min~max 사이의 값에 생성해 무순리스트 생성하는 함수
void printList(int arr[], int n);
void buildHeap(int arr[], int i, int n);    //최소힙 생성 함수
void downHeap(int arr[], int i, int n);
void swap(int* a, int* b);

int main()
{
    srand(time(NULL));  //난수 생성 초기화

    //배열 사이즈 100의 mini test
    int* L = buildList(miniTestSize, 1, 100);     //1~100까지 10개의 정수 무순리스트 생성
    int output[4];

    buildHeap(L, 1, miniTestSize);    //힙 생성
    printList(L, miniTestSize);       //L 출력

    for (int k = 1; k <= 3; k++) {
        //전역 변수 size가 findKthSmallest 함수 상에서 변동되기 때문에 
        //함수 호출 전 size 고정시킴
        miniTestSize = 10;

        output[k] = findKthSmallest(L, &miniTestSize, k);  //10개 원소의 정수 무순리스트 L의 k번째 작은 원소 찾기
        printf(" %d", output[k]);
    }
    printf("\n");

    //배열 사이즈 100,000의 test
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, t;
    int kArray[4] = { 1, 100, 99900, 99999 };
    int e;

    L = buildList(testSize, 1, 1000000);        //1~1,000,000까지 100,000개의 정수 무순리스트 생성

    for (int k = 0; k < 4; k++) {
        //전역 변수 size가 findKthSmallest 함수 상에서 변동되기 때문에
        //함수 호출 전 size 고정시킴
        testSize = 100000;

        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);    //findKthSmallest 호출 직전

        e = findKthSmallest(L, &testSize, kArray[k]);

        QueryPerformanceCounter(&end);      //findKthSmallest 호출 직후
        t.QuadPart = end.QuadPart - start.QuadPart; //함수 호출 시간 계산
        printf("%d번째 원소: %d / CPU time : %.12lf ms\n", kArray[k], e, 1000*((double)t.QuadPart / (double)ticksPerSec.QuadPart));
    }

    return 0;
}
int findKthSmallest(int arr[], int* n, int k) {

    buildHeap(arr, 1, *n);  //힙 생성 함수 : O(N)

    int smallKey = arr[1];      //return값
    int cnt = 0;

    while (cnt < k) { //cnt가 k가 될 때까지 최소힙을 정렬한다.
        cnt++;
        smallKey = arr[1];
        swap(&arr[1], &arr[(*n)--]);    //맨 앞과 last idx의 원소를 swap 후 last idx 1개 감소 
        downHeap(arr, 1, *n);   //downHeap() : O(logN) -> 따라서 O(logN)을 k번 하게되므로 O(k logN)
    }

    return smallKey;
}
int* buildList(int n, int min, int max) {

    int* arr = (int*)malloc(sizeof(int) * (n + 1));

    if (arr == NULL)
        return 0;
    else {
        arr[0] = -1;

        for (int i = 1; i <= n; i++) {
            /**
            * rand() 함수는 15비트 이하의 값을 리턴한다.
            * 리턴값의 범위는 0~32767로 정확히 2의 15제곱까지 리턴을 한다.
            * max가 100만의 경우 1~100만까지 범위의 원소값을 받을 수 없다.
            * 따라서 rand함수를 2번 사용해서 15비트 이상의 값을 난수로 돌릴 수 있도록 했다.
            */
            arr[i] = (((long)rand() << 15) | rand()) % max + min;  //min ~ max까지 난수 생성
        }
    }

    return arr;
}
void printList(int arr[], int n) {

    for (int i = 1; i <= n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}
void buildHeap(int arr[], int i, int n) {   //재귀적 Heap 생성

    if (i <= n) {   //idx가 배열 사이즈가 넘지 않으면
        buildHeap(arr, 2 * i, n);
        buildHeap(arr, 2 * i + 1, n);
        downHeap(arr, i, n);
    }
}
void downHeap(int arr[], int i, int n) {

    // k번째 원소를 찾을 때, O(k logn) 시간에 찾기 위해 최소힙으로 구현

    int leftChild, rightChild, smallChild;

    while (2 * i <= n) {    //왼쪽 자식이 있을 때까지
        leftChild = 2 * i;
        rightChild = 2 * i + 1;

        if (rightChild <= n) {  //오른쪽 자식도 있다면
            smallChild = arr[leftChild] < arr[rightChild] ? leftChild : rightChild;
        }
        else {  //왼쪽 자식만 있다면
            smallChild = leftChild;
        }

        if (arr[i] > arr[smallChild]) {   //idx의 원소가 자식 중 작은 놈보다 크다면 swap
            swap(&arr[i], &arr[smallChild]);
            i = smallChild;
        }
        else {  //idx원소가 자식보다 작으면 downHeap loop 탈출한다.
            break;
        }
    }
}
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}