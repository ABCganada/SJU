#include "my_func.h"

int RegFromFile(TEL **ptr, int MAXNUM, int N){  //파일 read 함수
    FILE *fp = fopen("PHONE_BOOK.txt", "r");    //파일 read
    if(fp == NULL){     //파일을 열지 못했다면
        printf("Couldn't open file");   //오류 출력
        return -1;      //종료
    }
    char buf[300], *p, *q;  //char형 변수 선언

    while((fgets(buf, sizeof(buf), fp)) != NULL){   //buf가 읽어들일 때까지 반복
        if(N==MAXNUM){  //N이 MaxNum에 도달했다면
            printf("OVERFLOW\n");   //오류 출력
            break;
        }
        ptr[N] = (TEL *)malloc(sizeof(TEL)*(N+1));  //할당

        // buf 문자열 쪼개기
        q = buf;
        for(p=buf; ; p++){ 
            if(*p == ' '){    //띄어쓰기 시
                *p = 0;
                ptr[N]->Name = (char *)malloc(strlen(q)+1); //할당
                strcpy(ptr[N]->Name, q);    //복사
                q = p+1;    //q는 다음 문자 주소를 가리킴
                break;
            }
        }
        for(p=q; ; p++){
            if(*p == ' '){      //띄어쓰기 시
                *p = 0;
                ptr[N]->Tel_no = (char *)malloc(strlen(q)+1);   //할당
                strcpy(ptr[N]->Tel_no, q);  //복사
                q = p+1;    //q는 다음 문자 주소를 가리킴
                break;
            }
        }
        for(p=q; ; p++){
            if(*p == '\n'){     //개행문자라면
                *p = 0;
                ptr[N]->Birth = (char *)malloc(strlen(q)+1);    //할당
                strcpy(ptr[N]->Birth, q);   //복사
                break;
            }
        }

        
        N++;    //N 증가
    }
    fclose(fp); //파일 종료

    //새로운 연락처가 등록될 때마다 이름 순으로 정렬이 된 상태를 유지해야 한다
    sort(ptr, N);   //연락처 정렬 함수 호출

    return N;   // N 리턴
}
