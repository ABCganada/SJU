#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tel{  //연락처 구조체
    char *Name;             //이름
    char *Tel_no;         //전화번호
    char *Birth;            //생일
}TEL;

void Registration(TEL **p, int N);    //연락처 등록 함수
void ShowAll(TEL **p, int N);         //연락처 출력 함수
int Delete(TEL **p, int N);           //연락처 삭제 함수
void FindByBirth(TEL **p, int N);     //같은 생일자 출력 함수

int main() 
{
    TEL **tel_list;   //연락처 구조체 선언
    int MAX_NUM, menu, n=0;
    printf("Max_num:");
    scanf("%d", &MAX_NUM);
    tel_list = (TEL **)malloc(MAX_NUM * sizeof(TEL *));

    while(1){   //종료조건까지 반복
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
        printf("Enter_the_menu_number:");
        scanf("%d", &menu); //메뉴 입력
        getchar();

        if(menu == 1) { //메뉴가 1이라면

            if(n == MAX_NUM){            //n이 최대 저장 개수라면
                printf("OVERFLOW\n");   //오버플로우
                continue;
            }
            else{                       //최대 저장 개수를 넘지 않았다면
                tel_list[n] = (TEL *)malloc(sizeof(TEL)*(n+1));
                Registration(tel_list, n);  //연락처 등록 함수 호출
                n++;
                printf("<<%d>>\n", n);  //현재 저장되어 있는 연락처 개수 출력
            }
        }
        else if(menu == 2){ //메뉴가 2라면
            ShowAll(tel_list, n);   //연락처 출력 함수 호출
        }
        else if(menu == 3){ //메뉴가 3이라면
            n = Delete(tel_list, n);    //연락처 삭제 함수 호출
        }
        else if(menu == 4){ //메뉴가 4라면
            FindByBirth(tel_list, n);   //같은 생일자 출력 함수 호출
        }
        else if(menu == 5){ //메뉴가 5라면

            for(int i=0; i<n; i++){         //구조체 내부멤버들의 메모리 해제
                free(tel_list[i]->Name);
                free(tel_list[i]->Tel_no);
                free(tel_list[i]->Birth);
            }
            free(tel_list);     //구조체 메모리 해제
            
            break;  //메뉴가 5라면 프로그램 종료
        }
    }
       

    return 0;
}
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
    TEL *tmp;
    int i, j;
    for(i=0; i<N; i++){ //버블 정렬
        for(j=0; j<N; j++){
            if(strcmp(p[j]->Name, p[j+1]->Name) > 0){   //이름 순으로
                tmp = p[j];             //swap
                p[j] = p[j+1];
                p[j+1] = tmp;

            }
        }
    }
}
void ShowAll(TEL **p, int N){     // 연락처 출력 함수
    for(int i=0; i<N; i++){ //출력
        printf("%s %s %s\n", p[i]->Name, p[i]->Tel_no, p[i]->Birth);
    }
}
int Delete(TEL **p, int N){   // 연락처 삭제 함수 
    if(N==0){   //등록된 연락처가 없다면
        printf("NO MEMBER\n");  //삭제할 것이 없음
        return N;   //N을 return
    }

    int i, check;
    char del[21];
    printf("Name:");
    scanf("%s", del);   //삭제할 이름을 입력

    for(i=0; i<N; i++){
        if(!strcmp(del, p[i]->Name)){    //삭제할 이름을 찾으면
            check = i;        //체크한다
            break;
        }
    }
    free(p[check]->Name);       //체크 부분 내부멤버 메모리 해제
    free(p[check]->Tel_no);
    free(p[check]->Birth);

    for(i=check; i<N-1; i++){   //체크부터 그 뒷부분 까지
        *p[i] = *p[i+1];    //앞으로 한 칸씩 당긴다
    }

    N--;    //등록 연락처 개수는 하나 줄고
    return N;   //N을 리턴
}
void FindByBirth(TEL **p, int N){     //같은 생일자 출력 함수
    int i;
    char b[3];      //각 구조체의 임시 생일
    char tmp[3];    //확인할 생일
    printf("Birth:");   //확인할 생일을 입력한다. (1~12)
    scanf("%s", tmp);

    for(i=0; i<N; i++){
        if(p[i]->Birth[4] != '0'){   //생일이 10~12라면
            b[0] = p[i]->Birth[4];
            b[1] = p[i]->Birth[5];
            b[2] = 0;
        }
        else{                       //생일이 0~9라면
            b[0] = p[i]->Birth[5];
            b[1] = 0;
        }

        if(!strcmp(b, tmp)){    //같은 생일이라면 출력
            printf("%s %s %s\n", p[i]->Name, p[i]->Tel_no, p[i]->Birth);
        }
    }
    
}



