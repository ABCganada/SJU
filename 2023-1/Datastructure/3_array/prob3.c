#include <stdio.h>

int N;

void insert(int arr[][N], int col, int *num);

int main()
{
    int i, j;
    int num = 1;
    scanf("%d", &N);
    
    int arr[N][N];

    for(i=0; i<N; i++){
        insert(arr, i, &num);
    }
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }




    return 0;
}
void insert(int arr[][N], int col, int *num){
    if(col % 2 == 0){
        for(int i=0; i<N; i++){
            arr[col][i] = *num;
            (*num)++;
        }
    }
    else{
        for(int i=N-1; i>=0; i--){
            arr[col][i] = *num;
            (*num)++;
        }
    }
}