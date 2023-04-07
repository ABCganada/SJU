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
void appendTerm(Node *lastNode, int coef, int exp);    // 입력값 단일연결리스트 연결
List addPoly(List *plist1, List *plist2);           // 다항식 덧셈
Node *getNode();        // node 생성
void freeList(List *plist); // List의 메모리 해제

int main()
{
    List list1, list2, result;    // 다항식 두개
    Node *lastNode, *ptrNode = NULL;
    init(&list1);
    init(&list2);

    int i, n1, n2, coef, exp;

    scanf("%d", &n1);                   // 1번째 다항식 항의 개수
    lastNode = list1.header;
    for(i=0; i<n1; i++){
        scanf("%d %d", &coef, &exp);
        appendTerm(lastNode, coef, exp);  // 항 추가 함수 호출
        lastNode = lastNode->next;
    }

    scanf("%d", &n2);                   // 2번째 다항식 항의 개수
    lastNode = list2.header;
    for(i=0; i<n2; i++){     
        scanf("%d %d", &coef, &exp);
        appendTerm(lastNode, coef, exp);  // 항 추가 함수 호출
        lastNode = lastNode->next;
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
void appendTerm(Node *lastNode, int coef, int exp){
    Node *newNode = getNode();
    newNode->coef = coef;
    newNode->exp = exp;

    lastNode->next = newNode;
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
            appendTerm(r, p1->coef, p1->exp);
            p1 = p1->next;
            r = r->next;
        }
        else if(p1->exp < p2->exp){
            appendTerm(r, p2->coef, p2->exp);
            p2 = p2->next;
            r = r->next;
        }
        else{
            int sumCoef = p1->coef + p2->coef;
            if(sumCoef){
                appendTerm(r, sumCoef, p1->exp);
                r = r->next;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    while(p1 != NULL){
        appendTerm(r, p1->coef, p1->exp);
        p1 = p1->next;
        r = r->next;
    }
    while(p2 != NULL){
        appendTerm(r, p2->coef, p2->exp);
        p2 = p2->next;
        r = r->next;
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