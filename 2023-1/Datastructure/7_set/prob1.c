#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *next;
}Node;

void addFirst(Node *head, int data);
void addData(Node *lastNode, int data);
int isSubset(Node *setA, Node *setB);
void freeSet(Node *pset);

int main()
{
    Node *headSetA = NULL, *headSetB = NULL;
    Node *ptrNode;
    int i, sizeA, sizeB, data;

    scanf("%d", &sizeA);            // set A 입력
    if(sizeA){
        headSetA = (Node *)malloc(sizeof(Node));
        ptrNode = headSetA;
        for(i=0; i<sizeA; i++){
            scanf("%d", &data);
            if(i==0){
                addFirst(headSetA, data);
                continue;
            }
            addData(ptrNode, data);
            ptrNode = ptrNode->next;
        }   
    }

    scanf("%d", &sizeB);            // set B 입력
    if(sizeB){
        headSetB = (Node *)malloc(sizeof(Node));
        ptrNode = headSetB;
        for(i=0; i<sizeB; i++){
            scanf("%d", &data);
            if(i == 0){
                addFirst(headSetB, data);
                continue;
            }
            addData(ptrNode, data);
            ptrNode = ptrNode->next;
        }   
    }

    if(headSetA == NULL)
        printf("0\n");
    else
        printf("%d\n", isSubset(headSetA, headSetB));


    if(headSetA)
        freeSet(headSetA);
    if(headSetB)
        freeSet(headSetB);

    


    return 0;
}
void addFirst(Node *head, int data){
    head->data = data;
    head->next = NULL;
}
void addData(Node *lastNode, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    lastNode->next = newNode;
}
int isSubset(Node *setA, Node *setB){
    Node *ptrA, *ptrB;
    ptrA = setA;
    ptrB = setB;
    while(ptrA != NULL && ptrB != NULL){
        if(ptrA->data == ptrB->data){
            ptrA = ptrA->next;
            if(ptrA == NULL)
                return 0;
            ptrB = ptrB->next;
        }
        else if(ptrA->data != ptrB->data){
            ptrB = ptrB->next;
        }

        if(ptrB == NULL){
            return ptrA->data;
        }
    }
    return ptrA->data;
}
void freeSet(Node *head){
    Node *current, *next;
    current = head;
    if(current->next == NULL){
        free(current);
        return;
    }
    next = current->next;

    while(1){
        free(current);
        current = next;
        next = current->next;
        if(current->next == NULL)
            break;
    }
}