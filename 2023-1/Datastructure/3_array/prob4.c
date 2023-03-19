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
    int i = 0, j = 0;
    int num = 1, flag = 1;

    while(num <= N*M){
        if(flag == 1){
            while(arr[i][j] == 0 && j < M){
                arr[i][j++] = num++;
            }
            flag++;
            i++;
            j--;
        }
        else if(flag == 2){
            while(arr[i][j] == 0 && i < N){
                arr[i++][j] = num++;
            }
            flag++;
            i--;
            j--;
        }
        else if(flag == 3){
            while(arr[i][j] == 0 && j >= 0){
                arr[i][j--] = num++;
            }
            flag++;
            i--;
            j++;
        }
        else{
            while(arr[i][j] == 0 && i >= 0){
                arr[i--][j] = num++;
            }
            flag = 1;
            i++;
            j++;
        }
    }
}
