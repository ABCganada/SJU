/*
DS - assignment3
- 전역 변수 X
- 메모리 해제 확인
- **header, trailer가 없는 단일 연결리스트
- **파괴적 다항식 덧셈(원본 영향)
- 생성: O(N)
- 덧셈: O(N1 + N2)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct __node{                                  // 항에 대한 노드
    int coef, exp;
    struct __node *next;
}Node;

Node *appendFirst(Node *headNode, int coef, int exp);   // append (if head == NULL)
void appendTerm(Node *ptrNode, int coef, int exp);      // append (if head != NULL)
Node *addPoly(Node *poly1, Node *poly2);                // poly1 + poly2 다항식 리턴 함수

int main()
{
    Node *headA = NULL, *headB = NULL, *headC = NULL;   // 각 다항식 head
    Node *ptr;                                          // pointer node
    int i, numA, numB, coef, exp;

    scanf("%d", &numA);                                 // 다항식A의 항의 개수
    if(numA){                                           // 항의 개수가 양의 정수일 때
        for(i=0; i<numA; i++){
            scanf("%d%d", &coef, &exp);                 // coef, exp 입력

            if(!headA){                                 // head가 초기화 상태일 때
                headA = appendFirst(headA, coef, exp);  // appendFirst 리턴값을 head에 전달
                ptr = headA;                            // ptr를 head에 연결
                continue;
            }
            appendTerm(ptr, coef, exp);                 // appendTerm
            ptr = ptr->next;                            // ptr, 다음 노드로 이동
        }
    }

    scanf("%d", &numB);                                 // 다항식B의 항의 개수
    if(numB){                                           // 항의 개수가 양의 정수일 때
        for(i=0; i<numB; i++){
            scanf("%d%d", &coef, &exp);                 // coef, exp 입력

            if(!headB){                                 // head가 초기화 상태일 때
                headB = appendFirst(headB, coef, exp);  // appendFirst 리턴값을 head에 전달
                ptr = headB;                            // ptr를 head에 연결
                continue;
            }
            appendTerm(ptr, coef, exp);                 // appendTerm
            ptr = ptr->next;                            // ptr, 다음 노드로 이동
        }
    }

    headC = addPoly(headA, headB);                      // 다항식C = 다항식A + 다항식B

    ptr = headC;                                        // 다항식C 출력
    while(ptr){                                         
        printf(" %d %d", ptr->coef, ptr->exp);
        ptr = ptr->next;
    }
    printf("\n");

    Node *current = headC;                              // 메모리 해제
    Node *next = current->next;
    while(1){
        free(current);
        current = next;
        if(current == NULL)
            break;
        next = current->next;
    }



    return 0;
}
Node *appendFirst(Node *headNode, int coef, int exp){   // append (if head == NULL)
    Node *newNode = (Node*)malloc(sizeof(Node));        // 새로운 노드 할당
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    headNode = newNode;         // head, 새로운 노드를 가리킴

    return headNode;            // head를 리턴
}
void appendTerm(Node *ptrNode, int coef, int exp){      // append (if head != NULL)
    Node *newNode = (Node*)malloc(sizeof(Node));        // 새로운 노드 할당
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    ptrNode->next = newNode;        // ptr의 다음 노드를 새로운 노드에 연결
}
Node *addPoly(Node *polyHead1, Node *polyHead2){        // 다항식 덧셈 함수
    Node *resultHead = NULL;        // 리턴할 다항식헤드
    Node *ptrNode1, *ptrNode2;      // 다항식1, 다항식2 포인터
    Node *ptrRes;                   // 리턴할 다항식의 포인터

    while(polyHead1 != NULL && polyHead2 != NULL){
        if(polyHead1->exp > polyHead2->exp){        // 1다항식계수 > 2다항식계수
            ptrNode1 = polyHead1->next;              // ptr노드, 1다항식헤드의 다음을 미리 가리킴
            polyHead1->next = NULL;                 // 1다항식헤드 연결 끊음

            if(!resultHead){                // result 다항식이 NULL이면
                resultHead = polyHead1;     // result헤드, 1다항식헤드를 가리킴
                ptrRes = resultHead;        // result에 대한 포인터 연결
            }
            else{                           // result 다항식이 NULL이 아니면
                ptrRes->next = polyHead1;   // result포인터, 다음 노드에 1다항식헤드 연결
                ptrRes = ptrRes->next;      // result포인터, 다음 노드로 이동
            }
            polyHead1 = ptrNode1;                    // 1다항식헤드를 ptr노드 지점에 다시 연결

        }
        else if(polyHead1->exp < polyHead2->exp){   // 1다항식계수 < 2디힝식계수
            ptrNode2 = polyHead2->next;              // ptr노드, 1다항식헤드의 다음을 미리 가리킴
            polyHead2->next = NULL;                 // 1다항식헤드 연결 끊음

            if(!resultHead){                // result 다항식이 NULL이면
                resultHead = polyHead2;     // result헤드, 1다항식헤드를 가리킴
                ptrRes = resultHead;        // result에 대한 포인터 연결
            }
            else{                           // result 다항식이 NULL이 아니면
                ptrRes->next = polyHead2;   // result포인터, 다음 노드에 1다항식헤드 연결
                ptrRes = ptrRes->next;      // result포인터, 다음 노드로 이동
            }
            polyHead2 = ptrNode2;                    // 1다항식헤드를 ptr노드 지점에 다시 연결

        }
        else{                                   // 1다항식계수 == 2다항식계수
            ptrNode1 = polyHead1->next;
            polyHead1->next = NULL;         // 다항식1 제일 앞부분 연결 해제

            ptrNode2 = polyHead2->next;
            polyHead2->next = NULL;         // 다항식2 제일 앞부분 연결 해제

            polyHead1->coef += polyHead2->coef; //

            if(polyHead1->coef != 0){           // 계수가 0이 아니면
                if(!resultHead){                // result 다항식이 NULL이면
                    resultHead = polyHead1;     // result헤드, 1다항식헤드를 가리킴
                    ptrRes = resultHead;        // result에 대한 포인터 연결
                }
                else{                           // result 다항식이 NULL이 아니면
                    ptrRes->next = polyHead1;   // result포인터, 다음 노드에 1다항식헤드 연결
                    ptrRes = ptrRes->next;      // result포인터, 다음 노드로 이동
                }
            }
            else{                               // 계수가 0이면
                free(polyHead1);                // 1다항식헤드도 메모리 해제 시켜버림
            }
            polyHead1 = ptrNode1;                   // 1다항식헤드를 ptr노드 지점에 다시 연결
            free(polyHead2);                        // 2다항식헤드 메모리 해제
            polyHead2 = ptrNode2;                   // 2다항식헤드를 ptr노드 지점에 다시 연결
        }
    }

    while(polyHead1){
        ptrNode1 = polyHead1->next;
        polyHead1->next = NULL;
        
        if(!resultHead){                    // result 다항식이 NULL이면
                resultHead = polyHead1;     // result헤드, 1다항식헤드를 가리킴
                ptrRes = resultHead;        // result에 대한 포인터 연결
            }
        else{                           // result 다항식이 NULL이 아니면
            ptrRes->next = polyHead1;   // result포인터, 다음 노드에 1다항식헤드 연결
            ptrRes = ptrRes->next;      // result포인터, 다음 노드로 이동
        }
        polyHead1 = ptrNode1;           // 포인터지점에 1다항식헤드 연결
    }

    while(polyHead2){
        ptrNode2 = polyHead2->next;
        polyHead2->next = NULL;
        
        if(!resultHead){                    // result 다항식이 NULL이면
                resultHead = polyHead2;     // result헤드, 1다항식헤드를 가리킴
                ptrRes = resultHead;        // result에 대한 포인터 연결
            }
        else{                           // result 다항식이 NULL이 아니면
            ptrRes->next = polyHead2;   // result포인터, 다음 노드에 1다항식헤드 연결
            ptrRes = ptrRes->next;      // result포인터, 다음 노드로 이동
        }
        polyHead2 = ptrNode2;           // 포인터지점에 2다항식헤드 연결
    }

    return resultHead;                  // 합한 다항식헤드 리턴
}

