#include <stdio.h>  //stdio 라이브러리
#include <string.h> //string 라이브러리
#include <stdlib.h> //stdlib 라이브러리

typedef struct parking_info{ //student 구조체
    int CarNum;
    int PhoneNum;
    char Product;
    char Subscribe;
    int Subscribe_day;
    int time;
    double charge;
}info;

void input(info *p, int N);
void compute(info *p);
void display(info *p, int N);
void parking_info_sort(info *p, int N);

int main()
{  
    info parking[100];

    int n, i;
    scanf("%d", &n);
    input(parking, n);
    printf("\n");
    // for(i=0; i<n; i++){
    //     printf("%d %d %c %d\n", parking[i].CarNum, parking[i].PhoneNum, parking[i].Product, parking[i].time);
    // }
    for(i=0; i<n; i++){
        compute(&parking[i]);
    }
    if(n > 1)
        parking_info_sort(parking, n);
    display(parking, n);

    return 0;
}
void input(info *p, int N){
    info *ptr;
    for(ptr=p; ptr<p+N; ptr++){
        scanf("%d %d", &ptr->CarNum, &ptr->PhoneNum);
        getchar();
        scanf("%c", &ptr->Product);
        if(ptr->Product == 'S'){
            getchar();
            scanf("%c", &ptr-> Subscribe);
            scanf("%d", &ptr->Subscribe_day);
        }
        scanf("%d", &ptr->time);
    }
}
void compute(info *p){
    p->charge = 0;
    if(p->Product == 'S' && p->Subscribe == 'N'){
        if(p->Subscribe_day == 7)   p->charge = 30000;
        else if(p->Subscribe_day == 30) p->charge = 100000;
        else p->charge = 500000;
    }
    else if(p->Product == 'D'){
        p->charge = 5000;
    }
    p->time -= 240;
    if(p->time > 0){
        int tmp = p->time / 10;
        p->charge += (tmp)*200;
    }
}
void display(info *p, int N){
    info *ptr;
    double totalCharge;
    double ChargeD = 0;
    double ChargeS = 0;


    for(ptr=p; ptr<p+N; ptr++){
        printf("%d %d %c %.0lf\n", ptr->CarNum, ptr->PhoneNum, ptr->Product, ptr->charge);
        if(ptr->Product == 'D') ChargeD += ptr->charge;
        else ChargeS += ptr->charge;
    }
    totalCharge = ChargeD + ChargeS;
    printf("%.lf %.lf %.lf\n", ChargeD, ChargeS, totalCharge);
}
void parking_info_sort(info *p, int N){
    info *ptr, tmp, *check;
    int i;
    for(i=0; i<N-1; i++){
        for(ptr=p; ptr<p+N-1; ptr++){
            if(ptr->Product > (ptr+1)->Product){
                tmp = *ptr;
                *ptr = *(ptr+1);
                *(ptr+1) = tmp;
            }
        }
    }
    //D 정렬
    ptr = p;
    while(ptr->Product != 'S'){
        if(ptr->CarNum > (ptr+1)->CarNum && (ptr+1)->Product != 'S'){
            tmp = *ptr;
            *ptr = *(ptr+1);
            *(ptr+1) = tmp;
            ptr = p;
            continue;
        }
        ptr++;
    }
    check = ptr;
    //S 정렬
    while(ptr != p+N-1){
        if(ptr->CarNum > (ptr+1)->CarNum){
            tmp = *ptr;
            *ptr = *(ptr+1);
            *(ptr+1) = tmp;
            ptr = check;
            continue;
        }
        ptr++;
    }
}

