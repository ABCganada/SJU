#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

/**
 * 에어텔
 * DC, DP 구현, 실행 시간 비교
 * 정방향 or 역방향 버전 선택
 * 가이드라인의 main()을 따를 것
 * n=6으로 테스트 결과가 수작업 실행 결과와 일치하는지 확인 후 n=MAX로 본실행 진행할 것
 * 최소비용을 구하는 문제, 최소비용이 2개 이상이면 아무거나 출력해라
 * 본실행 단계에서 DC 호출이 너무 느리거나 빠르면, DP와 비교하기에 적당한 MAX를 15나 60으로 한다.
*/

#define MAX 30

LARGE_INTEGER ticksPerSec;
LARGE_INTEGER start, end, t;

int A[MAX], H[MAX]; //A: 공항비용, H: 숙박비용
int M[MAX];         //시작위치에서 각 인덱스까지의 최소비용을 저장하는 배열
int testS[3] = { 0,2,2 };
int testD[3] = { 4,5,4 };

int airtelDC(int start, int dest);  //분할통치 정방향 최소비용 계산 함수
int airtelDP(int start, int dest);  //동적프로그래밍 정방향 최소비용 계산 함수
void printCPUTime(int n, int s, int d, int mincost, char *version, double time);  //출력 함수

int main()
{
    A[0] = 0, A[1] = 1;             //A 배열 초기화
    for (int i = 2; i < MAX; i++) {
        A[i] = A[i - 1] + A[i - 2] % 5 + 3;
    }

    H[0] = 1, H[1] = 5;             //H 배열 초기화
    for (int i = 2; i < MAX; i++) {
        H[i] = (H[i - 1] + i) % 9 + 1;
    }
    printf("n\ts\td\tmincost\t\tversion\t\tcputime\n");

    //test run
    int n = 6;
    for (int i = 0; i < 3; i++) {       //0~2까지 testS, testD의 인덱스를 돌면서 최소비용 구하기 테스트 진행
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        int mincost = airtelDC(testS[i], testD[i]); //분할통치 방식 실행
        QueryPerformanceCounter(&end);

        t.QuadPart = end.QuadPart - start.QuadPart;
        double cpuTimeDC = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;
        printCPUTime(n, testS[i], testD[i], mincost, "DC", cpuTimeDC);  //분할통치 cpu time 출력

        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        mincost = airtelDP(testS[i], testD[i]);     //동적프로그래밍 방식 실행
        QueryPerformanceCounter(&end);

        t.QuadPart = end.QuadPart - start.QuadPart;
        double cpuTimeDP = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;
        printCPUTime(n, testS[i], testD[i], mincost, "DP", cpuTimeDP);  //동적프로그래밍 cpu time 출력
    }

    //main run (size = 30)
    n = MAX;
    int s = 1, d = n - 2;
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    int mincost = airtelDC(s, d);       //분할통치 실행
    QueryPerformanceCounter(&end);

    t.QuadPart = end.QuadPart - start.QuadPart;
    double cpuTimeDC = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;
    printCPUTime(n, s, d, mincost, "DC", cpuTimeDC);    //분할통치 cpu time 출력

    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    mincost = airtelDP(s, d);           //동적프로그래밍 방법 실행
    QueryPerformanceCounter(&end);

    t.QuadPart = end.QuadPart - start.QuadPart;
    double cpuTimeDP = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;
    printCPUTime(n, s, d, mincost, "DP", cpuTimeDP);    //동적프로그래밍 cpu time 출력

    //main run (size = 15)
    //n이 30인 경우의 시간 차이가 매우 커서 사이즈를 절반으로 줄여서도 실행해봄
    n = 15, s = 1, d = 13;
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    mincost = airtelDC(s, d);       //분할통치 실행
    QueryPerformanceCounter(&end);

    t.QuadPart = end.QuadPart - start.QuadPart;
    cpuTimeDC = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;
    printCPUTime(n, s, d, mincost, "DC", cpuTimeDC);    //분할통치 cpu time 출력

    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    mincost = airtelDP(s, d);       //동적프로그래밍 실행
    QueryPerformanceCounter(&end);

    t.QuadPart = end.QuadPart - start.QuadPart;
    cpuTimeDP = (double)t.QuadPart / (double)ticksPerSec.QuadPart * 1000;
    printCPUTime(n, s, d, mincost, "DP", cpuTimeDP);    //동적프로그래밍 cpu time 출력


    return 0;
}
void printCPUTime(int n, int s, int d, int mincost, char *version, double time) {   //cpu time 출력 함수
    printf("%d\t%d\t%d\t%d\t\t%s\t\t%lf\n", n, s, d, mincost, version, time);
}
int airtelDC(int start, int dest) { //분할통치 정방향 최소비용 계산 함수
    if (dest == start) {    //출발과 목적지가 같다면 비용이 없음
        return 0;
    }
    int cost;
    int mincost = 99999999; //최소비용을 아주 큰 값으로 초기화
    for (int i = start; i < dest; i++) {    //출발과 목적지 사이에서 i index가 반복문을 수행
        //출발점부터 i 지점 전까지의 최소 비용을 재귀적으로 계산 후,
        //i지점에 대한 비용을 더해줌.
        cost = airtelDC(start, i) + H[i] + A[dest - i]; 
        if (mincost > cost) {
            mincost = cost;
        }
    }
    return mincost;
}
int airtelDP(int start, int dest) { //동적프로그래밍 정방향 최소비용 계산 함수
    M[start] = 0;   //출발지점의 비용을 0으로 초기화하고 시작
    for (int i = start + 1; i <= dest; i++) {   //출발점 + 1 부터 목적지까지 반복
        M[i] = 99999999;    //i번째의 최소비용은 아주 큰 값으로 초기화하고 시작
        for (int k = start; k < i; k++) {   //출발점부터 i의 전까지 반복
            int cost = M[k] + H[k] + A[i - k];  //최소비용을 저장한 배열로부터 cost를 계산하고 최소비용을 비교하여 갱신 작업
            if (M[i] > cost) {
                M[i] = cost;
            }
        }
    }
    return M[dest];
}
