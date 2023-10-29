#include <stdio.h>
#include <stdlib.h>

/*
* 크기 M인 배열 동적 할당
* n은 M보다 작은 자연수, 최대 삽입 개수
* 입력 키는 중복 없는 6~8자리
* 해시 함수는 x%M
* 키값 없는 버킷은 0
* 
* 입력
* i or s or e
* 삽입 : 저장된 배열 인덱스 출력
* 삽입할 때, 충돌 일어나면 다음 셀로 가는데 충돌 횟수만큼 C를 출력함.
* 그런 다음에 삽입 성공한 주소 인쇄함
* 
*/

int M, n;

void init(int bucket[]);
int hash(int data);

int insertBucket(int bucket[], int data, int i);
void searchBucket(int bucket[], int data, int i);

int main()
{
    scanf("%d %d", &M, &n);
    getchar();

    int *bucket = (int *)malloc(sizeof(int) * M);
    init(bucket);

    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'e'){
            break;
        } else if(cmd == 'i'){
            scanf("%d", &data);
            getchar();

            printf("%d\n",insertBucket(bucket, data, hash(data)));
        } else if(cmd == 's'){
            scanf("%d", &data);
            getchar();

            searchBucket(bucket, data, hash(data));
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
int hash(int data){
    return data % M;
}
int insertBucket(int bucket[], int data, int i){
    if(!bucket[i]){     //충돌 없음
        bucket[i] = data;
        return i;
    }

    printf("C");
    return insertBucket(bucket, data, (i+1)%M);
}
void searchBucket(int bucket[], int data, int i){
    if(!bucket[i]){
        printf("-1\n");
        return;
    }

    if(bucket[i] == data){
        printf("%d %d\n", i, bucket[i]);
        return;
    }

    searchBucket(bucket, data, (i+1)%M);
}