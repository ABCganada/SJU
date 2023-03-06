#include "my_func.h"    //my_func 헤더파일

int main() 
{ 
    TEL **tel_list = NULL;   //연락처 구조체 선언
    int MAX_NUM, menu, n=0;
    printf("Max_num:");
    scanf("%d", &MAX_NUM);
    tel_list = (TEL **)malloc(MAX_NUM * sizeof(TEL *));

    while(1){   //종료조건까지 반복
        printf("*****Menu*****\n");
        printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
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
        else if(menu == 5){
            n = RegFromFile(tel_list, MAX_NUM, n);
        }
        else if(menu == 6){ //메뉴가 6이라면
            FILE *fp = fopen("PHONE_BOOK.txt", "w");    //파일 write
            for(int i=0; i<n; i++){ //구조체 -> 파일 입력
                fprintf(fp, "%s %s %s\n", tel_list[i]->Name, tel_list[i]->Tel_no, tel_list[i]->Birth);
            }
            fclose(fp); //파일 닫기

            for(int i=0; i<n; i++){         //구조체 내부멤버들의 메모리 해제
                free(tel_list[i]->Name);
                free(tel_list[i]->Tel_no);
                free(tel_list[i]->Birth);
            }
            free(tel_list);     //구조체 메모리 해제
            
            break;  //메뉴가 6이라면 프로그램 종료
        }
    }
       

    return 0;
}