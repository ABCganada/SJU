#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *next;
}Node;

typedef struct __list{
    struct __node *head, *tail;
}List;

int N;

void init(List *plist);
Node *getNode(int data);
void insertNode(List *plist, Node *node);
Node *deleteNode(List *plist);
void mergeSort(List *plist, int n);
void merge(List *plist1, List *plist2);
List partition(List *plist, int n);
void printList(List *plist);
void freeList(List *plist);

int main()
{
    List list;
    int data;

    init(&list);

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        scanf("%d", &data);
        insertNode(&list, getNode(data));
    }

    mergeSort(&list, N);
    printList(&list);
    
    freeList(&list);

    return 0;
}
void init(List *plist){
    plist->head = NULL;
    plist->tail = plist->head; 
}
Node *getNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
void insertNode(List *plist, Node *node){

    if(plist->head == NULL){
        plist->head = node;
        plist->tail = node;
        return;
    }

    plist->tail->next = node;
    plist->tail = node;
}

void mergeSort(List *plist, int n){

    if(n > 1){
        List leftList = partition(plist, n/2);
        mergeSort(&leftList, n/2);
        mergeSort(plist, n - n/2);
        merge(&leftList, plist);
    }
}
void merge(List *plist1, List *plist2){
    List retList;
    init(&retList);

    Node *node1 = plist1->head;
    Node *node2 = plist2->head;

    while(node1 && node2){
        if(node1->data < node2->data){
            Node *newNode = deleteNode(plist1);
            insertNode(&retList, newNode);
            node1 = plist1->head;
        } else{
            Node *newNode = deleteNode(plist2);
            insertNode(&retList, newNode);
            node2 = plist2->head;
        }
    }

    while(node1){
        Node *newNode = deleteNode(plist1);
        insertNode(&retList, newNode);
        node1 = plist1->head;
    }

    while(node2){
        Node *newNode = deleteNode(plist2);
        insertNode(&retList, newNode);
        node2 = plist2->head;
    }

    Node *ptrNode = retList.head;
    while(ptrNode){
        Node *newNode = deleteNode(&retList);
        insertNode(plist2, newNode);
        ptrNode = retList.head;
    }
}
Node *deleteNode(List *plist){
    Node *delNode = plist->head;
    plist->head = delNode->next;
    if(plist->head == NULL){
        init(plist);
    }
    delNode->next = NULL;

    return delNode;
}
List partition(List *plist, int n){
    List retList;
    init(&retList);

    Node *ptrNode = plist->head;
    int i=0;

    while(i++ < n){
        Node *newNode = deleteNode(plist);
        insertNode(&retList, newNode);
    }

    return retList;
}
void printList(List *plist){
    Node *node = plist->head;

    while(node){
        printf(" %d", node->data);
        node = node->next;
    }
    printf("\n");
}
void freeList(List *plist){
    Node *cur = plist->head;

    while(cur){
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}