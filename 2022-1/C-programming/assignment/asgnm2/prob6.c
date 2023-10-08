#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
    //정수형 변수 선언
    int n;
    //cnt 변수를 따로 준비. 입력을 제대로 했는지 안 했는지 식별하기 위해서다.
    int cnt = 0;    //입력을 제대로 했다면 1일 것이고, 아니면 0 그대로 일 것이다.
    //주소를 받는다.
    scanf("%d", &n);

    //주소에 대한 switch문을 연다.
    switch (n) {
            
    case 10500: //10500일 경우
        printf("Gwangju\n");    //광주를 출력
        cnt++;  //입력을 제대로 했기 때문에 cnt를 하나 올린다.
        break;
    case 10400:
    case 10300: //10400과 10300일 경우
        printf("Busan\n");  //부산을 출력한다.
        cnt++;  //입력을 제대로 했다
        break;
    
    case 10200:
    case 10100:
    case 10000: //10200, 10100, 10000일 경우
        printf("Seoul\n");  //서울을 출력한다.
        cnt++;  //입력을 제대로 했다.
        break;
    }

    if (cnt == 0)   //만약 입력을 제대로 하지 않아서 cnt가 0이라면
        printf("none\n");   //none을 출력한다.

	return 0;
}