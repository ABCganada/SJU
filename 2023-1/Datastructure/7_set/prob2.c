#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *next;
}Node;

typedef struct __list{
    struct __node *header;
}List;

void init(List *set);   // 집합 초기화
void addSet(Node *lastNode, int data);  // 집합 원소 추가
Node *unionSet(List *set1, List *set2); // 유니온
Node *intersectionSet(List *set1, List *set2);  // 인터섹션
void freeSet(List *set);    // 메모리 해제

int main()
{
    List setA, setB;    // 집합 A, B
    Node *ptrNode; 
    int i, sizeA, sizeB, data;

    init(&setA);        // 초기화
    init(&setB);

    scanf("%d", &sizeA);            // set A 입력
    if(sizeA){
        ptrNode = setA.header;
        for(i=0; i<sizeA; i++){
            scanf("%d", &data);
            addSet(ptrNode, data);
            ptrNode = ptrNode->next;
        }   
    }

    scanf("%d", &sizeB);            // set B 입력
    if(sizeB){
        ptrNode = setB.header;
        for(i=0; i<sizeB; i++){
            scanf("%d", &data);
            addSet(ptrNode, data);
            ptrNode = ptrNode->next;
        }   
    }

    Node *uNode = unionSet(&setA, &setB);           // union output
    ptrNode = uNode->next;
    if(!ptrNode)
        printf(" 0");
    else{
        while(ptrNode){
            printf(" %d", ptrNode->data);
            ptrNode = ptrNode->next;
        }
    }
    printf("\n");

    Node *iNode = intersectionSet(&setA, &setB);    // intersection output
    ptrNode = iNode->next;
    if(!ptrNode)
        printf(" 0");
    else{
        while(ptrNode){
            printf(" %d", ptrNode->data);
            ptrNode = ptrNode->next;
        }
    }
    printf("\n");

    if(sizeA)                           // 메모리 해제
        freeSet(&setA);
    if(sizeB)
        freeSet(&setB);
    
    List setU, setI;
    setU.header = uNode;
    setI.header = iNode;

    if(setU.header->next != NULL)
        freeSet(&setU);
    if(setI.header->next != NULL)
        freeSet(&setI);


    return 0;
}
void init(List *set){
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;

    set->header = header;
}
void addSet(Node *lastNode, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    lastNode->next = newNode;
}
Node *unionSet(List *set1, List *set2){
    List result;
    Node *ptr1, *ptr2, *ptrRes;
    init(&result);

    ptr1 = set1->header->next;
    ptr2 = set2->header->next;
    ptrRes = result.header;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            addSet(ptrRes, ptr1->data);
            ptr1 = ptr1->next;
            ptrRes = ptrRes->next;
        }
        else if(ptr1->data > ptr2->data){
            addSet(ptrRes, ptr2->data);
            ptr2 = ptr2->next;
            ptrRes = ptrRes->next;
        }
        else{
            addSet(ptrRes, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptrRes = ptrRes->next;
        }
    }

    while(ptr1 != NULL){
        addSet(ptrRes, ptr1->data);
        ptr1 = ptr1->next;
        ptrRes = ptrRes->next;
    }

    while(ptr2 != NULL){
        addSet(ptrRes, ptr2->data);
        ptr2 = ptr2->next;
        ptrRes = ptrRes->next;
    }

    return result.header;
}
Node *intersectionSet(List *set1, List *set2){
    List result;
    Node *ptr1, *ptr2, *ptrRes;
    init(&result);

    ptr1 = set1->header->next;
    ptr2 = set2->header->next;
    ptrRes = result.header;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data == ptr2->data){
            addSet(ptrRes, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptrRes = ptrRes->next;
        }
        else{
            if(ptr1->data < ptr2->data){
                ptr1 = ptr1->next;
            }
            else{
                ptr2 = ptr2->next;
            }
        }
    }

    return result.header;
}
void freeSet(List *set){
    Node *current, *next;
    current = set->header;
    if(current->next == NULL){  // Set 원소가 1개일 때
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