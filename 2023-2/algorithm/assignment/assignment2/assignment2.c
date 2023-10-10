#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

/**
 * 퀵 정렬
 * pivot 선정 4가지 비교 실험
 * 1. 결정 1개
 * 2. 결정 3개 중 중간값
 * 3. 랜덤 1개
 * 4. 랜덤 3개 중 중간값
*/

int n = 100000;      //create array 시 배열 사이즈
int limits[4] = {1, 100, 500, 1000};      //퀵 정렬 limit size
int limitIdx;
char mode[4][20] = { "determinant1", "determinant3", "random1", "random3" };    //pivot mode 배열
int modeIdx;
double cpuTime[4][4];   //cpu time 저장 배열

typedef struct __partitionIdx { //partition() idx 저장할 구조체
    int frontEQ, rearEQ;
}PartitionIdx;

PartitionIdx partitionIdx;

int* createArray();                                     //배열 생성 함수
int* copyArray(int ary[]);                              //배열 카피 함수
void sort(int ary[], int n);                            //정렬 함수 : 퀵정렬 + 삽입정렬
void qSort(int ary[], int p, int r);                    //퀵정렬 함수
void insertSort(int ary[], int p, int r);               //삽입정렬 함수
int findPivot(int ary[], int p, int r, char *mode);     //mode에 따른 pivot index 리턴 함수
void partition(int ary[], int p, int r, int pivotIdx);  //퀵정렬 시 pivot 기준으로 정렬하고 partitionIdx 구조체에 값을 리턴하는 함수
int findMidIdx(int ary[], int a, int b, int c);         //a, b, c index 중 중간 값을 리턴하는 함수
void swap(int* a, int* b);                              //swap 함수
void printCpuTime();                                    //cpu time 출력 함수

int main()
{
    srand(time(NULL));  //난수 생성 초기화

    int* arr = createArray();   //기준 배열 생성

    for (limitIdx = 0; limitIdx < 4; limitIdx++) {  //limit size 1, 100, 500, 1000
        for (modeIdx = 0; modeIdx < 4; modeIdx++) { //pivot mode det1, det3, random1, random3
            int* cpyArr = copyArray(arr);   //기준 배열 복사

            LARGE_INTEGER ticksPerSec;
            LARGE_INTEGER start, end, t;
            
            QueryPerformanceFrequency(&ticksPerSec);
            
            QueryPerformanceCounter(&start);    //sort 직전
            sort(cpyArr, n);    //복사 배열 정렬
            QueryPerformanceCounter(&end);      //sort 직후

            t.QuadPart = end.QuadPart - start.QuadPart;
            cpuTime[limitIdx][modeIdx] = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;  //cpu time 2차원 배열에 ms 기준 소요 시간 저장

            for (int k = 0; k < 10; k++) {
                printf(" %d", cpyArr[k]);
            }
            printf("\n");

            free(cpyArr);   //복사 배열 메모리 해제
        }
    }

    printCpuTime(); //cpu time 출력
    free(arr);  //기준 배열 메모리 해제

    return 0;
}
int *createArray() {
    int* ary = (int*)malloc(sizeof(int) * n);   //n(10만)만큼 int 배열 메모리 할당

    for (int i = 0; i < n; i++) {
        /**
        * rand()는 15비트 이하의 값을 리턴함.
        * 리턴의 범위가 0~32767, 2의 15제곱까지임.
        * 1~10만까지의 값을 random으로 배열에 저장하고 싶기 때문에
        * rand() 함수를 2번 사용해 15비트 이상의 값을 가능하게 함.
        */
        ary[i] = (((long)rand() << 15) | rand()) % n + 1;
    }

    return ary;
}
int* copyArray(int ary[]) {
    int* cpyAry = (int*)malloc(sizeof(int) * n);    //복사 배열 메모리 할당

    for (int i = 0; i < n; i++) {   //값 복사
        cpyAry[i] = ary[i];
    }

    return cpyAry;
}
void sort(int ary[], int n) {
    qSort(ary, 0, n - 1);   //ary에 대한 0부터 n-1 index까지 퀵정렬 

    if (limits[limitIdx] > 1) { //만약 limit size가 1이상일 경우
        for (int i = 0; i < n; i += limits[limitIdx]) { //i부터 i + limit size의 삽입 정렬을 n/limit size 만큼 반복한다.
            insertSort(ary, i, i + limits[limitIdx]);
        }
    }
}
void qSort(int ary[], int p, int r) {
    if (r - p >= limits[limitIdx]) {    //마지막 idx - 시작 idx가 limit size보다 크다면 퀵정렬을 한다.
        int pivotIdx = findPivot(ary, p, r, mode[modeIdx]); //전역 변수 mode에 따른 pivot idx를 찾는다.
        partition(ary, p, r, pivotIdx); //ary에 대해 p부터 r idx까지 pivot idx를 기준으로 partition을 해나간다.
        qSort(ary, p, partitionIdx.frontEQ - 1);    //p부터 partition()후 갱신된 EQ idx-1까지 퀵정렬 재귀 호출 
        qSort(ary, partitionIdx.rearEQ + 1, r);     //partition()후 갱신된 EQ idx+1부터 r까지 퀵정렬 재귀 호출
    }
}
void insertSort(int ary[], int p, int r) {
    int i, j;
    for (i = p; i < r; i++) {   //p부터 r-1까지
        int insertElem = ary[i];    //새로운 삽입 원소값은 ary[i]
        for (j = i - 1; j >= p; j--) {  //j는 i-1부터 p까지 내려감
            if (ary[j] > insertElem) {  //ary[j]가 삽입 원소값보다 크면 뒤로 한 칸씩 땡기는 작업을 함
                ary[j + 1] = ary[j];
                continue;
            }
            break;      //ary[j]가 삽입 원소값보다 작으면 반복문을 빠져나감
        }
        ary[j + 1] = insertElem;    //j의 1칸 뒤에 삽입 원소값을 삽입함.
    }
}
int findPivot(int ary[], int p, int r, char *mode) {
    if (strcmp(mode, "determinant1") == 0) {    //mode가 결정적1이면 마지막 idx 리턴
        return r;
    }
    else if (strcmp(mode, "random1") == 0) {    //mode가 무작위1이면 p~r까지 중 1가지 idx 리턴
        return (((long)rand() << 15) | rand()) % (r - p + 1) + p;
    }
    else if (r - p == 1) {  //r-p가 1이면 시작 idx 리턴
        return p;
    }

    int a, b, c;

    if (strcmp(mode, "determinant3") == 0) {    //mode가 결정적3이면
        a = p;              //a는 시작 인덱스
        b = (p + r) / 2;    //b는 가운데 인덱스
        c = r;              //c는 마지막 인덱스
    }
    else {  //mode가 무작위3
        a = (((long)rand() << 15) | rand()) % (r - p + 1) + p;      //p~r까지 중 1가지 idx
        b = (((long)rand() << 15) | rand()) % (r - p + 1) + p;
        c = (((long)rand() << 15) | rand()) % (r - p + 1) + p;
    }

    return findMidIdx(ary, a, b, c);    //a,b,c 중 중간값 인덱스 찾아서 리턴
}
void partition(int ary[], int p, int r, int pivotIdx) {
    int pivot = ary[pivotIdx];      //pivot 저장
    swap(&ary[pivotIdx], &ary[r]);  //마지막과 pivot idx 위치 교환
    int i = p;      //i는 시작 인덱스
    int j = r - 1;  //j는 마지막 바로 앞 인덱스

    while (i <= j) {
        while (i <= j && ary[i] <= pivot) { //ary[i]가 pivot보다 작거나 같을 때까지
            if (ary[i] == pivot && ary[i+1] != pivot && i+1 != j) { //ary[i]가 pivot과 같고 ary[i+1]은 pivot과 다르고 i 뒤가 j가 아닐 경우
                swap(&ary[i], &ary[i + 1]); //pivot과 값이 똑같은 ary[i]를 한 칸 뒤와 교환
                continue;
            }
            i++;    //ary[i]가 pivot보다 작으면 i위치 1칸 뒤로
        }

        while (i <= j && ary[j] >= pivot) { //ary[j]가 pivot보다 크거나 같을 때까지
            if (ary[j] == pivot && ary[j-1] != pivot && j-1 != i) { //ary[j]가 pivot과 같고 ary[j-1]은 pivot과 다르고 j 앞이 i가 아닐 경우
                swap(&ary[j], &ary[j - 1]); //pivot과 값이 똑같은 ary[j]를 한 칸 앞과 교환
                continue;
            }
            j--;    //ary[j]가 pivot보다 크면 j위치 1칸 앞으로
        }

        if (i < j) {
            swap(&ary[i], &ary[j]); //i와 j에 대한 while문 2가지를 빠져나오면 i와 j를 교환
        }
    }
    swap(&ary[i], &ary[r]); //i와 j가 역전되면 i위치와 pivot을 저장했던 r을 교환

    while (i >= p && ary[i] == pivot) { //i에서 시작해 pivot값과 같을 때까지 앞으로 전진
        i--;
    }
    partitionIdx.frontEQ = ++i; //partitionIdx 구조체의 frontEQ값을 갱신

    while (i <= r && ary[i] == pivot) { //frontEQ에서 시작해 pivot값과 같을 때까지 뒤로 후진
        i++;
    }
    partitionIdx.rearEQ = --i;  //partitionIdx 구조체의 rearEQ값을 갱신

}
int findMidIdx(int ary[], int a, int b, int c) {    //ary에 대해 a, b, c 중 중간값을 찾는 함수
    if (ary[a] > ary[b] && ary[a] < ary[c] || ary[a] < ary[b] && ary[a] > ary[c]) {
        return a;
    }
    else if (ary[b] > ary[a] && ary[b] < ary[c] || ary[b] < ary[a] && ary[b] > ary[c]) {
        return b;
    }

    return c;
}
void swap(int* a, int* b) { //배열 원소 교환 함수
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void printCpuTime() {   //cpu time 출력 함수
    printf("Limit\t\t결정적1\t\t결정적3\t\t무작위1\t\t무작위3\n");
    for (int i = 0; i < 4; i++) {
        printf("%-4d\t", limits[i]);

        for (int j = 0; j < 4; j++) {
            printf("\t%8lf", cpuTime[i][j]);
        }
        printf("\n");
    }
}