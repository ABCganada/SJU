#include <stdio.h>
#include <stdlib.h>

void insertSort(int arr[], int n);

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    insertSort(arr, n);

    printf("\n");
    for(int i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");

    free(arr);

    return 0;
}
void insertSort(int arr[], int n){
    int j;

    for(int i=0; i<n; i++){
        int insertElem = arr[i];    // 73

        for(j=i-1; j>=0; j--){  //j=0 ~ 0

            if(arr[j] > insertElem){    // 3 > 73
                arr[j+1] = arr[j];
                continue;
            }

            break;
        }

        arr[j+1] = insertElem;

        // for(int k=0; k<n; k++){
        //     printf(" %d", arr[k]);
        // }
        // printf("\n");
    }
}