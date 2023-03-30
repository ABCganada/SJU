#include <stdio.h>
#include <stdlib.h>

// 수정할 포인트: 노드 append시 마지막 노드를 기억해 시간복잡도 O(1)로 만들어보자.

typedef struct __node{      // 단일 연결 리스트
    int coef, exp;
    struct __node *next;
}Node;

typedef struct __list{      // header 가지고 있는 리스트
    struct __node *header;
}List;

void init(List *plist);     // List 초기화
void appendTerm(List *plist, int coef, int exp);    // 입력값 단일연결리스트 연결
List addPoly(List *plist1, List *plist2);           // 다항식 덧셈
Node *getNode();        // node 생성
void freeList(List *plist); // List의 메모리 해제

int main()
{
    List list1, list2, result;    // 다항식 두개
    Node *ptrNode = NULL;
    init(&list1);
    init(&list2);

    int i, n1, n2, coef, exp;

    scanf("%d", &n1);                   // 1번째 다항식 항의 개수
    for(i=0; i<n1; i++){
        scanf("%d %d", &coef, &exp);
        appendTerm(&list1, coef, exp);  // 항 추가 함수 호출
    }

    scanf("%d", &n2);                   // 2번째 다항식 항의 개수
    for(i=0; i<n2; i++){     
        scanf("%d %d", &coef, &exp);
        appendTerm(&list2, coef, exp);  // 항 추가 함수 호출
    }

    result = addPoly(&list1, &list2);   // result List에 다항식 덧셈 리턴값 저장
    ptrNode = result.header->next;
    while(ptrNode != NULL){
        printf(" %d %d", ptrNode->coef, ptrNode->exp);
        ptrNode = ptrNode->next;
    }
    printf("\n");
    
    free(ptrNode);      // 노드 포인터 메모리 해제
    freeList(&list1);   // 1번째 다항식 메모리 해제
    freeList(&list2);   // 2번째 다항식 메모리 해제
    freeList(&result);  // 합한 다항식 메모리 해제

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
            if(sumCoef != 0)
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
        free(current);
        if(current->next == NULL)
            break;
    }
}