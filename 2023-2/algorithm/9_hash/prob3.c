#include <stdio.h>
#include <stdlib.h>

int M, n, prime;

void init(int bucket[]);
int hash1(int data);
int hash2(int data);

int insertBucket(int bucket[], int data, int i);
void searchBucket(int bucket[], int data, int i);
void printBucket(int bucket[]);

int main()
{
    scanf("%d %d %d", &M, &n, &prime);
    getchar();

    int *bucket = (int *)malloc(sizeof(int) * M);
    init(bucket);

    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'e'){
            printBucket(bucket);
            break;
        } else if(cmd == 'i'){
            scanf("%d", &data);
            getchar();

            printf("%d\n",insertBucket(bucket, data, hash1(data)));
        } else if(cmd == 's'){
            scanf("%d", &data);
            getchar();

            searchBucket(bucket, data, hash1(data));
        } else if(cmd == 'p'){
            printBucket(bucket);
        }
    }

    free(bucket);

    return 0;
}
void init(int bucket[]){
    for(int i=0; i<M; i++){
        bucket[i] = 0;
    }
}
int hash1(int data){
    return data%M;
}
int hash2(int data){
    return prime - (data%prime);
}
int insertBucket(int bucket[], int data, int i){
    if(bucket[i] == 0){
        bucket[i] = data;
        return i;
    }

    printf("C");
    return insertBucket(bucket, data, (i+hash2(data))%M);
}
void searchBucket(int bucket[], int data, int i){
    if(bucket[i] == 0){
        printf("-1\n");
        return;
    }

    if(bucket[i] == data){
        printf("%d %d\n", i, bucket[i]);
        return;
    }

    searchBucket(bucket, data, (i+hash2(data))%M);
}
void printBucket(int bucket[]){
    for(int i=0; i<M; i++){
        printf(" %d", bucket[i]);
    }
    printf("\n");
}