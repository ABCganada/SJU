#include <stdio.h>
#include <string.h>

int checkString(char *str, char *check, int cnt);

int main()
{
    char str[101], check[101];
    int cnt = 0;
    scanf("%s", str);
    scanf("%s", check);
    printf("%d\n",checkString(str, check, cnt));

    return 0;
}
int checkString(char *str, char *check, int cnt){
    if(*str == 0){
        return cnt;
    }

    if(!strncmp(str, check, strlen(check))){
        cnt++;
        return checkString(str+1, check, cnt);
    }
    else{
        return checkString(str+1, check, cnt);
    }
}