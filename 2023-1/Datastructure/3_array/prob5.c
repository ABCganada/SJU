#include <stdio.h>

int N, M;

void insert(int arr[][100]);

int main()
{
    int i, j;
    scanf("%d%d", &N, &M);

    int arr[100][100] = { 0, };

    insert(arr);

    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }



    return 0;
}
void insert(int arr[][100]){
    int row, col, num = 1;
    int i, j;

    for(i=0; i<M; i++){
        row = 0;
        col = i;
        while(row < N && col >= 0){
            arr[row++][col--] = num++;
        }
    }
    for(i=1; i<N; i++){
        row = i;
        col = M-1;
        while(row < N && col >= 0){
            arr[row++][col--] = num++;
        }
    }
}
