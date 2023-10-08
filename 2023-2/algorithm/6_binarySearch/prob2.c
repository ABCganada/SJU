#include <stdio.h>
#include <stdlib.h>

int n, k;

typedef struct __list{
    int *arr;
    int lastIdx;
}List;

void init(List *plist);
void insert(List *plist, int data);
int binarySearch(List *plist, int p, int r);

int main()
{
    scanf("%d%d", &n, &k);

    List list;
    init(&list);

    int data;
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        insert(&list, data);
    }

    if(list.arr[list.lastIdx] < k){
        printf("%d\n", n);
    } else if(list.arr[0] >= k){
        printf("0\n");
    } else{
        printf("%d\n", binarySearch(&list, 0, list.lastIdx));
    }

    free(list.arr);

    return 0;
}
void init(List *plist){
    plist->arr = (int *)malloc(sizeof(int) * n);
    plist->lastIdx = -1;
}
void insert(List *plist, int data){
    if(plist->lastIdx < 0){
        plist->arr[++plist->lastIdx] = data;
        return;
    }

    if(plist->arr[plist->lastIdx] < data){
        plist->arr[++plist->lastIdx] = data;
        return;
    }

    int pos;
    for(int i=0; i<=plist->lastIdx; i++){
        pos = i;

        if(plist->arr[i] > data){
            break;
        }
    }

    for(int i=plist->lastIdx; i>=pos; i--){
        plist->arr[i+1] = plist->arr[i];
    }

    plist->arr[pos] = data;
    plist->lastIdx++;
}
int binarySearch(List *plist, int p, int r){
    int q;

    while(p<=r){
        int q = (p+r)/2;

        if(plist->arr[q] == k){
            return q;
        } else if(plist->arr[q] < k){
            if(plist->arr[q+1] >= k){
                return q+1;
            }
            p = q+1;
        } else{
            r = q-1;
        }
    }

    return -99;
}