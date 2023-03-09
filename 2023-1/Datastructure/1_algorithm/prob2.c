// bitMatrix에서 최대 행렬 찾기
// O(N)
#include <stdio.h>

#define MAX_N_LEN 100

int mostOnes(int (*bitMatrix)[MAX_N_LEN], int N);

int main()
{
    int bitMatrix[MAX_N_LEN][MAX_N_LEN];
    int i, j, n;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &bitMatrix[i][j]);
        }
    }
    printf("%d\n", mostOnes(bitMatrix, n));
    

    return 0;
}
int mostOnes(int (*bitMatrix)[MAX_N_LEN], int N){
    int i = 0, j = 0;
    int maxLine;

    while(1){
        while(bitMatrix[i][j] == 1){
            j++;
            if(j == N)
                return i;
        }
        maxLine = i;
        while(bitMatrix[i][j] == 0){
            i++;
            if(i == N)
                return maxLine;
        }

    }

}