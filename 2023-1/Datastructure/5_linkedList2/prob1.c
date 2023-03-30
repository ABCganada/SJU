#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int coef, exp;
    struct __node *next;
}Node;

typedef struct __list{
    struct __node *header;
}List;

void init(List *plist);
void appendTerm(List *plist, int coef, int exp);
List addPoly(List *plist1, List *plist2);
Node *getNode();
void freeList(List *plist);

int main()
{
    List list1, list2, result;    // 다항식 두개
    Node *ptrNode = NULL;
    init(&list1);
    init(&list2);

    int i, n1, n2, coef, exp;

    scanf("%d", &n1);
    for(i=0; i<n1; i++){
        scanf("%d %d", &coef, &exp);
        appendTerm(&list1, coef, exp);
    }
    // ptrNode = list1.header->next;
    // while(1){
    //     printf(" %d %d", ptrNode->coef, ptrNode->exp);
    //     if(!ptrNode->next)
    //         break;
    //     ptrNode = ptrNode->next;
    // }
    // printf("\n");

    scanf("%d", &n2);
    for(i=0; i<n2; i++){
        scanf("%d %d", &coef, &exp);
        appendTerm(&list2, coef, exp);
    }
    // ptrNode = list2.header->next;
    // while(1){
    //     printf(" %d %d", ptrNode->coef, ptrNode->exp);
    //     if(!ptrNode->next)
    //         break;
    //     ptrNode = ptrNode->next;
    // }
    // printf("\n");
    result = addPoly(&list1, &list2);

    ptrNode = result.header->next;
    while(1){
        if(ptrNode->coef != 0)
            printf(" %d %d", ptrNode->coef, ptrNode->exp);
        if(!ptrNode->next)
            break;
        ptrNode = ptrNode->next;
    }
    printf("\n");
    
    free(ptrNode);
    // freeList(&list1);
    // freeList(&list2);
    // freeList(&result);

    return 0;
}
void init(List *plist){
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;

    plist->header = header;
}
void appendTerm(List *plist, int coef, int exp){
    Node *newNode = getNode();
    newNode->coef = coef;
    newNode->exp = exp;

    Node *ptrNode = plist->header;
    while(ptrNode->next != NULL){
        ptrNode = ptrNode->next;
    }
    ptrNode->next = newNode;
}
List addPoly(List *plist1, List *plist2){
    List result;
    init(&result);

    Node *p1, *p2, *r;
    p1 = plist1->header->next;
    p2 = plist2->header->next;
    r = result.header;

    while(p1 != NULL && p2 != NULL){
        if(p1->exp > p2->exp){
            appendTerm(&result, p1->coef, p1->exp);
            p1 = p1->next;
        }
        else if(p1->exp < p2->exp){
            appendTerm(&result, p2->coef, p2->exp);
            p2 = p2->next;
        }
        else{
            int sumCoef = p1->coef + p2->coef;
            appendTerm(&result, sumCoef, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        appendTerm(&result, p1->coef, p1->exp);
        p1 = p1->next;
    }
    while(p2 != NULL){
        appendTerm(&result, p2->coef, p2->exp);
        p2 = p2->next;
    }

    return result;
}
Node *getNode(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;

    return newNode;
}
void freeList(List *plist){
    Node *current, *next;
    current = plist->header;
    next = current->next;

    while(1){
        current = next;
        next = current->next;
        if(current == NULL)
            break;
        free(current);

    }
}