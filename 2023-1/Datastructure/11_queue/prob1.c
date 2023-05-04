#include <stdio.h>
#include <stdlib.h>

typedef struct __q{
    int size;
    int *qArr;
    int front, rear;
}Q;

void init(Q *pq);
int enqueue(Q *pq, int data);
int dequeue(Q *pq);
void printQ(Q *pq);

int isEmpty(Q *pq);
int isFull(Q *pq);

int main()
{
    Q q;
    char cmd;
    int i, calNum, data;
    scanf("%d", &q.size);
    scanf("%d", &calNum);
    getchar();

    init(&q);

    for(i=0; i<calNum; i++){
        scanf("%c", &cmd);
        if(cmd == 'I'){
            scanf("%d",&data);
            int flag = enqueue(&q, data);
            if(!flag)
                break;
        }
        else if(cmd == 'D'){
            int flag = dequeue(&q);
            if(!flag)
                break;
        }
        else if(cmd == 'P'){
            printQ(&q);
        }
        getchar();
    }

    free(q.qArr);


    return 0;
}
void init(Q *pq){
    pq->qArr = (int *)malloc(sizeof(int) * pq->size);
    pq->front = 0;
    pq->rear = 0;
}
int enqueue(Q *pq, int data){
    if(isFull(pq)){
        printf("overflow");
        printQ(pq);
        return 0;
    }

    pq->rear = (pq->rear+1) % pq->size;
    pq->qArr[pq->rear] = data;

    return 1;
}
int dequeue(Q *pq){
    if(isEmpty(pq)){
        printf("underflow");
        return 0;
    }

    pq->front = (pq->front+1) % pq->size;
    pq->qArr[pq->front] = 0;
    return 1;
}
void printQ(Q *pq){
    int i;
    for(i=0; i<pq->size; i++)
        printf(" %d", pq->qArr[i]);
    printf("\n");
}
int isEmpty(Q *pq){
    if(pq->rear % pq->size == pq->front)
        return 1;
    else
        return 0;

}
int isFull(Q *pq){
    if((pq->rear+1) % pq->size == pq->front)
        return 1;
    else
        return 0;
}