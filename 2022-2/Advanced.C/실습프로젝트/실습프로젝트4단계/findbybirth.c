#include "my_func.h"

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