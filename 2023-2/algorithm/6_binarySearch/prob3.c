#include <stdio.h>
#include <stdlib.h>

int a, b, k, n;

int binarySearch(char *str, int idx);

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    getchar();

    char *str = (char *)malloc(n+1);
    scanf("%s", str);

    int ans = binarySearch(str, 0);

    printf("%d\n", ans);

    free(str);

    return 0;
}
int binarySearch(char *str, int idx){
    int m = (a+b)/2;

    if(str[idx] == '\0'){
        return m;
    }

    if(str[idx] == 'N'){
        b = m;
        return binarySearch(str, idx+1);
    } else{
        a = m+1;
        return binarySearch(str, idx+1);
    }
}