#include "my_func.h"

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