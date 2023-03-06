#include "my_func.h"

void ShowAll(TEL **p, int N){     // 연락처 출력 함수
    for(int i=0; i<N; i++){ //출력
        printf("%s %s %s\n", p[i]->Name, p[i]->Tel_no, p[i]->Birth);
    }
}