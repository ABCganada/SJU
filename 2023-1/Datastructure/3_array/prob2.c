#include <stdio.h>

int reverseArray(int *arr, int idx1, int idx2);

int main()
{
    int arr[100];
    int N, i, t, idx1, idx2, *p, *q;
    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &t);
    scanf("%d", &idx1);
    p = arr + idx1;

    for(i=0; i<t-1; i++){
        scanf("%d", &idx2);
        q = arr + idx2;
        idx1 = reverseArray(arr, idx1, idx2);
    }

    for(i=0; i<N; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");



    return 0;
}
int reverseArray(int *arr, int idx1, int idx2){
    int tmp;
    int *p, *q;
    p = arr + idx1;
    q = arr + idx2;
    
    tmp = *p;
    *p = *q;
    *q = tmp;

    return idx2;
}