#include <stdio.h>

void towerOfHanoi(int N, char from, char aux, char to);

int main()
{
    int n;
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
void towerOfHanoi(int N, char from, char aux, char to){
    if(N==1){
        printf("%c %c\n", from, to);
        return;
    }
    towerOfHanoi(N-1, from, to, aux);
    printf("%c %c\n", from, to);
    towerOfHanoi(N-1, aux, from, to);
    return;
}