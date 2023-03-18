#include <stdio.h>

int changeArray(int *p, int data);

int main()
{
    int arr[100];
    int N, i, t, idx1, idx2, *p, tmp;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &t);
    scanf("%d", &idx1);
    tmp = arr[idx1];
    for(i=0; i<t-1; i++){
        scanf("%d", &idx2);
        p = arr + idx2;
        tmp = changeArray(p, tmp);
    }

    for(i=0; i<N; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");



    return 0;
}
int changeArray(int *p, int data){
    int tmp = *p;
    *p = data;

    return tmp;
}