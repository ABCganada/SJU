#include <stdio.h>  //stdio 라이브러리
#include <string.h> //string 라이브러리
#include <stdlib.h> //stdlib 라이브러리

typedef struct student{ //student 구조체
    char name[21];  //공백없이 최대 길이 20
    int kor, eng, math;    //국영수 성적
    double avg;      //세 과목의 평균 점수
}st;

void read_data(st *ptr, int n); //read_data 선언
void sort_score(st *ptr, int n);    //sort_score 선언
st *select_out(st *ptr1, st *ptr2, int n);  //select_out 선언

int main()
{  
    st s1[49], s2[49], *res;    //구조체 변수
    int n, i;   //int형 변수
    scanf("%d", &n);    //n입력
    getchar();

    read_data(s1, n);   //read_data 함수 호출
    read_data(s2, n);

    sort_score(s1, n);  //sort_score 함수 호출
    sort_score(s2, n);

    res = select_out(s1, s2, n); //res에 리턴된 주소 저장

    for(i=0; i<n; i++, res++){  //출력
        printf("%s %d %d %d %.1lf\n", res->name, res->kor, res->eng, res->math, res->avg);
    }

    
    return 0;
}
void read_data(st *ptr, int n){ //read_data 함수
    st *p;  //반복문을 위한 구조체 포인터 변수
    for(p=ptr; p<ptr+n; p++){   //이름, 국영수, 평균
        scanf("%s", p->name);   //이름 입력
        scanf("%d %d %d", &p->kor, &p->eng, &p->math);  //국영수 입력
        getchar();
        p->avg = (p->kor + p->eng + p->math) / 3.0; //평균값 저장
    }
}
void sort_score(st *ptr, int n){    //sort_score 함수
    st *p, tmp; //반복문을 위한 변수, swap을 위한 구조체 tmp
    int i;  //반복문을 위한 int형 변수
    for(i=0; i<n-1; i++){   //버블 정렬
        for(p=ptr; p<ptr+n-1; p++){
            if(p->avg < (p+1)->avg){    //평균이 다름
                tmp = *p;   //swap
                *p = *(p+1);
                *(p+1) = tmp;
            }
            else if (p->avg == (p+1)->avg){ //평균이 같음
                if(p->kor < (p+1)->kor){    //국어 점수 다름
                    tmp = *p;   //swap
                    *p = *(p+1);
                    *(p+1) = tmp;
                }
                else if(p->kor == (p+1)->kor){  //평균 같음, 국어 점수 같음
                    if(p->eng < (p+1)->eng){    //영어 점수 다름
                        tmp = *p;   //swap
                        *p = *(p+1);
                        *(p+1) = tmp;
                    }
                }
            }
        }
    }
}
st *select_out(st *ptr1, st *ptr2, int n){  //select_out 함수
    double n1 = (ptr1 + n/2)->avg;  //첫 배열 중간값
    double n2 = (ptr2 + n/2)->avg;  //두번째 배열 중간값

    if(n1 >= n2) return ptr1;   //첫 배열 중간값이 크다면
    else    return ptr2;    //두 번째 배열 중간값이 크다면
}
