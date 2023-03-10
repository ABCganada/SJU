#include <stdio.h>

void printDigit(int N);

int main()
{
    int n;
    scanf("%d", &n);
    printDigit(n);

    return 0;
}
void printDigit(int N){
    if(N<10)
        printf("%d\n", N);
    
    else{
        printDigit(N/10);
        printf("%d\n", N%10);
    }
}