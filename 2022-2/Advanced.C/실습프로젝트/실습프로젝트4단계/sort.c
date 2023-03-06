#include "my_func.h"

void sort(TEL **p, int N){      //연락처 정렬 함수
    //새로운 연락처가 등록될 때마다 이름 순으로 정렬이 된 상태를 유지해야 한다
    TEL *tmp;
    int i, j;
    for(i=0; i<N-1; i++){ //버블 정렬
        for(j=0; j<N-1; j++){
            if(strcmp(p[j]->Name, p[j+1]->Name) > 0){   //이름 순으로
                tmp = p[j];             //swap
                p[j] = p[j+1];
                p[j+1] = tmp;

            }
        }
    }
}