#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct infomation{  //연락처 구조체
    char Name[21];          //이름, 최대 20자
    char PhoneNum[16];      //전화번호, 최대 15자
    char Birth[9];          //생일, 최대 8자
}infomation;

void Registration(infomation *p, int N);    //연락처 등록 함수
void ShowAll(infomation *p, int N);         //연락처 출력 함수
int Delete(infomation *p, int N);           //연락처 삭제 함수
void FindByBirth(infomation *p, int N);     //같은 생일자 출력 함수

int main() 
{
    infomation info[100];   //연락처 구조체 선언, 최대 정보 100개
    int menu, n=0;

    while(1){   //종료조건까지 반복
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &menu); //메뉴 입력
        getchar();

        if(menu == 1) { //메뉴가 1이라면

            if(n > 100){                //n이 최대 저장 개수라면
                printf("OVERFLOW\n");   //오버플로우
                continue;
            }
            else{                       //최대 저장 개수를 넘지 않았다면
                Registration(info, n);  //연락처 등록 함수 호출
                n++;
                printf("<<%d>>\n", n);  //현재 저장되어 있는 연락처 개수 출력
            }
        }
        else if(menu == 2){ //메뉴가 2라면
            ShowAll(info, n);   //연락처 출력 함수 호출
        }
        else if(menu == 3){ //메뉴가 3이라면
            n = Delete(info, n);    //연락처 삭제 함수 호출
        }
        else if(menu == 4){ //메뉴가 4라면
            FindByBirth(info, n);   //같은 생일자 출력 함수 호출
        }
        else if(menu == 5)  break;  //메뉴가 5라면 프로그램 종료
    }
       

    return 0;
}
void Registration(infomation *p, int N){    //연락처 등록 함수
    printf("Name:");    //이름 입력
    scanf("%s", (p+N)->Name);
    printf("Phone_number:");    //전화번호 입력
    scanf("%s", (p+N)->PhoneNum);
    printf("Birth:");   //생일 입력
    scanf("%s", (p+N)->Birth);

    //새로운 연락처가 등록될 때마다 이름 순으로 정렬이 된 상태를 유지해야 한다
    infomation *ptr, tmp;
    int i, j;
    for(i=0; i<N; i++){ //버블 정렬
        for(ptr=p; ptr<p+N; ptr++){
            if(strcmp(ptr->Name, (ptr+1)->Name) > 0){   //이름 순으로
                tmp = *ptr;             //swap
                *ptr = *(ptr+1);
                *(ptr+1) = tmp;

            }
        }
    }
}
void ShowAll(infomation *p, int N){     // 연락처 출력 함수
    infomation *ptr;
    for(ptr=p; ptr<p+N; ptr++){ //출력
        printf("%s %s %s\n", ptr->Name, ptr->PhoneNum, ptr->Birth);
    }
}
int Delete(infomation *p, int N){   // 연락처 삭제 함수 
    if(N==0){   //등록된 연락처가 없다면
        printf("NO MEMBER\n");  //삭제할 것이 없음
        return N;   //N을 return
    }

    infomation *ptr, *check;
    char del[21];
    printf("Name:");
    scanf("%s", del);   //삭제할 이름을 입력

    for(ptr=p; ptr<p+N; ptr++){
        if(!strcmp(del, ptr->Name)){    //삭제할 이름을 찾으면
            check = ptr;        //체크한다
            break;
        }
    }

    for(ptr=check; ptr<p+N-1; ptr++){   //체크부터 그 뒷부분 까지
        *ptr = *(ptr+1);    //앞으로 한 칸씩 당긴다
    }
    N--;    //등록 연락처 개수는 하나 줄고
    return N;   //N을 리턴
}
void FindByBirth(infomation *p, int N){     //같은 생일자 출력 함수
    infomation *ptr;
    char b[3];
    char tmp[3];
    printf("Birth:");   //확인할 생일을 입력한다. (1~12)
    scanf("%s", tmp);

    for(ptr=p; ptr<p+N; ptr++){
        if(ptr->Birth[4] != '0'){   //생일이 10~12라면
            b[0] = ptr->Birth[4];
            b[1] = ptr->Birth[5];
            b[2] = 0;
        }
        else{                       //생일이 0~9라면
            b[0] = ptr->Birth[5];
            b[1] = 0;
        }

        if(!strcmp(b, tmp)){    //같은 생일이라면 출력
            printf("%s %s %s\n", ptr->Name, ptr->PhoneNum, ptr->Birth);
        }
    }
    
}



