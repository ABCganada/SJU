#include <stdio.h>
#include <stdlib.h>

int M;

typedef struct __node{
    int data;
    struct __node *next;
}Node;

void init(Node *bucket);
Node *getNode(int data);
int hash(int data);

void insertBucket(Node *bucket, int data);
int searchBucket(Node *bucket, int data);
int deleteBucket(Node *bucket, int data);
void printBucket(Node *bucket);
void freeBucket(Node *bucket, int i);

int main()
{
    scanf("%d", &M);
    getchar();

    Node *bucket = (Node *)malloc(sizeof(Node) * M);
    init(bucket);

    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'e'){
            break;
        }

        if(cmd == 'i'){
            scanf("%d", &data);
            getchar();

            insertBucket(bucket, data);
        } else if(cmd == 's'){
            scanf("%d", &data);
            getchar();

            printf("%d\n", searchBucket(bucket, data));
        } else if(cmd == 'd'){
            scanf("%d", &data);
            getchar();

            printf("%d\n", deleteBucket(bucket, data));
        } else if(cmd == 'p'){
            printBucket(bucket);
        }
    }

    for(int i=0; i<M; i++){
        freeBucket(bucket, i);
    }
    free(bucket);

    return 0;
}
void init(Node *bucket){
    for(int i=0; i<M; i++){
        bucket[i].next = NULL;
    }
}
Node *getNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int hash(int data){
    return data%M;
}
void insertBucket(Node *bucket, int data){
    int i = hash(data);
    Node *newNode = getNode(data);

    if(bucket[i].next == NULL){
        bucket[i].next = newNode;
    } else{
        newNode->next = bucket[i].next;
        bucket[i].next = newNode;
    }
}
int searchBucket(Node *bucket, int data){
    int i = hash(data);
    Node *node = bucket[i].next;

    int ret = 1;

    while(node){
        if(node->data == data){
            return ret;
        }
        node = node->next;
        ret++;
    }
    return 0;
}
int deleteBucket(Node *bucket, int data){
    int i = hash(data);
    Node *delNode = bucket[i].next;
    Node *preDelNode = &bucket[i];

    int ret = 1;

    while(delNode){
        if(delNode->data == data){
            preDelNode->next = delNode->next;
            free(delNode);
            return ret;
        }
        preDelNode = delNode;
        delNode = delNode->next;
        ret++;
    }

    return 0;
}
void printBucket(Node *bucket){
    for(int i=0; i<M; i++){
        Node *node = bucket[i].next;

        while(node){
            printf(" %d", node->data);
            node = node->next;
        }
    }
    printf("\n");
}
void freeBucket(Node *bucket, int i){
    Node *node = bucket[i].next;

    while(node){
        bucket[i].next = node->next;
        free(node);
        node = bucket[i].next;
    }
}