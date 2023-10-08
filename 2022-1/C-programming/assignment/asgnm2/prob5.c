#include<stdio.h>

int main(){

	/* Type or paste your code in this area */
    //정수형 변수 선언
    int n;
    //주소를 받는다.
    scanf("%d", &n);
    
    //주소는 10000 ... 10500 6가지일 경우 올바른 출력이 가능하다.
    if (n == 10000 || n == 10100 || n == 10200 || n == 10300 || n == 10400 || n == 10500) {
        //광주 주소가 하나기 때문에 if 조건에 걸었다
        if (n == 10500)
            printf("Gwangju");
        //다음 부산의 주소를 else if문에 건다.
        else if (n == 10300 || n == 10400)
            printf("Busan");
        //마지막 서울의 주소다.
        //서울의 주소가 3개이기 때문에 else로 두었다.
        else
            printf("Seoul");
    }
    
    //주소 입력을 형식에 맞추지 않은 경우
    else
        printf("none"); //none을 출력한다.

	return 0;
}