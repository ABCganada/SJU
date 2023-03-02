#include <stdio.h>  //stdio 라이브러리
#include <string.h> //string 라이브러리
#include <stdlib.h> //stdlib 라이브러리

int main()
{
    int i, n, j, res, tmp_i, size;  //int 형 변수 선언
    char str1[21], str2[21], ans1[100], ans2[100], tmp[3];   //char형 변수 선언
    //문자열 2개 입력
    gets(str1);  
    gets(str2);

    n = (int)(str1[0] - str2[0]);   //첫 문자의 차이를 정수형 변수에 저장
    if(n < 0)
        n *= -1;

    for(i=0, size = 0; i<strlen(str1); i++){
        if(str1[i]>='A' && str1[i]<='Z')
            ans1[size++] = str1[i]+n;
        else if(str1[i]>='a' && str1[i]<='z')
            ans1[size++] = str1[i]-n;
        else if(str1[i]>='0' && str1[i]<='9'){
            if(str1[i+1]>='0' && str1[i+1]<='9'){
                tmp[0]=str1[i];
                tmp[1]=str1[i+1];
                tmp[2]='\0';
                i++;
            }
            else {
                tmp[0] = str1[i];
                tmp[1] = '\0';
            }
            tmp_i=atoi(tmp);
            for(j=0; j<n; j++)
                ans1[size++] = 'A' + tmp_i -1;
        }
        else
            ans1[size++] = ' ';
    }
    ans1[size] = 0;

    for(i=0, size = 0; i<strlen(str2); i++){
        if(str2[i]>='A' && str2[i]<='Z')
            ans2[size++] = str2[i]+n;
        else if(str2[i]>='a' && str2[i]<='z')
            ans2[size++] = str2[i]-n;
        else if(str2[i]>='0' && str2[i]<='9'){
            if(str2[i+1]>='0' && str2[i+1]<='9'){
                tmp[0]=str2[i];
                tmp[1]=str2[i+1];
                tmp[2]='\0';
                i++;
            }
            else {
                tmp[0] = str2[i];
                tmp[1] = '\0';
            }
            tmp_i=atoi(tmp);
            for(j=0; j<n; j++)
                ans2[size++] = 'A' + tmp_i -1;
        }
        else
            ans2[size++] = ' ';
    }
    ans2[size] = 0;

    if(!strcmp(ans1, str2)) res = 1;
    else if(!strcmp(ans2, str1)) res = 2;
    else    res = 0;

    printf("%d\n", res);    //최종 출력
   
    

    return 0;
}
