#include <stdio.h>
#include <stdlib.h>

typedef struct __list{
    int *arr;
    int lastIdx;
}List;

int n, k;

void init(List *plist);
void insert(List *plist, int data);
void printArr(List *plist);
int binarySearch(List *plist, int p, int r);

int main()
{
    List list;
    int data;

    scanf("%d%d", &n, &k);

    init(&list);

    for(int i=0; i<n; i++){
        scanf("%d", &data);
        insert(&list, data);
    }

    if(list.arr[0] > k){
        printf("-1\n");
    } else if(list.arr[n-1] < k){
        printf("%d\n", n-1);
    }
    else{
        printf("%d\n", binarySearch(&list, 0, n-1));
    }

    free(list.arr);

    return 0;
}
void init(List *plist){
    plist->arr = (int *)malloc(sizeof(int) * n);
    plist->lastIdx = -1;
}
void insert(List *plist, int data){
    if(plist->lastIdx == -1){
        plist->arr[++plist->lastIdx] = data;
        return;
    }

    int pos = -1;

    for(int i=0; i<=plist->lastIdx; i++){
        if(plist->arr[i] > data){
            pos = i;
            break;
        }
    }

    if(pos != -1){
        for(int i=plist->lastIdx; i>=pos; i--){
            plist->arr[i+1] = plist->arr[i];
        }

        plist->arr[pos] = data;
        plist->lastIdx++;
    } else{
        plist->arr[++plist->lastIdx] = data;
    }
}
int binarySearch(List *plist, int p, int r){
    if(p <= r){
        int q = (p+r)/2;
        
        if(plist->arr[q] == k){
            return q;
        } else if(plist->arr[q] > k){
            if(plist->arr[q-1] <= k){
                return q-1;
            }
            return binarySearch(plist, p, q-1);
        } else{
            return binarySearch(plist, q+1, r);
        }
    }

    return -99;
}
void printArr(List *plist){
    for(int i=0; i<=plist->lastIdx; i++){
        printf(" %d", plist->arr[i]);
    }
    printf("\n");
}