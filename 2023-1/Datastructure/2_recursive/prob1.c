#include <stdio.h>

int sum(int N);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));

    return 0;
}
int sum(int N){
    if(N==1)
        return 1;

    else{
        return N + sum(N-1);
    }
}