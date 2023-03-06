#include <stdio.h>
#define ABS(a) a > 0 ? a : -a
#define MAX(a,b) a > b ? a : b


int main(){
    int MAXNUM = 0, N = 6;
    int num[N], tmp;

    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
    }

    for(int i=0; i<N; i++){
        tmp = ABS(num[i]);
        MAXNUM = MAX(MAXNUM, tmp);
    }
    printf("%d\n", MAXNUM);

    return 0;
}