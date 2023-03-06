#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//공백을 포함하는 A를 입력받고 B와 같은 문자열일 경우 C로 치환

int main()
{   
    char ans[251], temp[251];
    char A[101], B[11], C[11];
    int i, n;
    gets(A);
    scanf("%s", B);
    scanf("%s", C);
    
    strcpy(ans, A);
    
    n = strlen(B);
    for(i=0; ans[i]; i++){  //i는 0부터 ans[i]가 0이라면 반복문 종료
        if(!strncmp(ans+i, B, n)){
            strcpy(temp, ans);  
            //1. 임시 문자열에 ans 복사
            strcpy(temp+i, C);  
            //2. i번째 요소까지는 살려 놓고 문자열 C를 복사
            strcat(temp, ans+i+n);
            //3. 임시 문자열에 ans의 i+n번째 요소를 덧붙임.
            strcpy(ans, temp);  
            //ans에 완성된 임시 문자열을 복사.
        }
    }
    printf("%s\n", ans);

    

    return 0;
}