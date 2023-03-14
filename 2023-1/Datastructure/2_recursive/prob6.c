#include <stdio.h>

int GCD(int n1, int n2);

int main()
{
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    if(n2 > n1){
        int tmp = n1;
        n1 = n2;
        n2 = tmp;
    }

    printf("%d\n", GCD(n1, n2));

    return 0;
}
int GCD(int n1, int n2){
    if(n2 == 0)
        return n1;
    else{
        return GCD(n2, n1%n2);
    }
}