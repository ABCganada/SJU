#include "my_func.h"

void Registration(TEL **p, int N){    //연락처 등록 함수
    char buffer[101];
    printf("Name:");    //이름 입력
    scanf("%s", buffer);
    p[N]->Name = (char *)malloc(strlen(buffer)+1);
    strcpy(p[N]->Name, buffer);

    printf("Phone_number:");    //전화번호 입력
    scanf("%s", buffer);
    p[N]->Tel_no = (char *)malloc(strlen(buffer)+1);
    strcpy(p[N]->Tel_no, buffer);
    
    printf("Birth:");   //생일 입력
    scanf("%s", buffer);
    p[N]->Birth = (char *)malloc(strlen(buffer)+1);
    strcpy(p[N]->Birth, buffer);

    //새로운 연락처가 등록될 때마다 이름 순으로 정렬이 된 상태를 유지해야 한다
    sort(p, N);
}