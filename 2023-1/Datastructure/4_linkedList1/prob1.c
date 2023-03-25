#include <stdio.h>
#include <stdlib.h>

typedef struct __node{              // 노드 구조체
    char data;
    struct __node *prev;
    struct __node *next;
}Node;

typedef struct __list{              // 헤더를 구조체로 감싼다. 함수에 리스트를 전달할 것임.
    struct __node *header;
}List;

void add(List *plist, int r, char data);    // add 함수
void delete(List *plist, int r);            // delete 함수
void get(List *plist, int r);               // get 함수
void print(List *plist);                    // print 함수
void freeNode(List *plist);                 // 메모리 해제 함수

int main()
{
    List list;
    Node header, trailer;
    // 이중연결리스트 초기화 O(1)
    header.prev = NULL;
    trailer.data = 0;           // trailer,  prev = header. data = 0. next = NULL
    trailer.next = NULL;
    header.next = &trailer;
    trailer.prev = &header;

    list.header = &header;      // 리스트 구조체의 header는 Node header를 가리킴

    int attempt, i, r;
    char cmd, data;

    scanf("%d", &attempt);      // 연산 개수
    getchar();

    for(i=0; i<attempt; i++){
        scanf("%c", &cmd);      // 연산 명령
        getchar();

        if(cmd == 'A'){         // add 연산
            scanf("%d", &r);    // 연결 순위
            getchar();
            scanf("%c", &data); // 삽입할 문자
            getchar();
            add(&list, r, data);
        }
        else if(cmd == 'D'){    // delete 연산
            scanf("%d", &r);    // 연결 순위
            getchar();
            delete(&list, r);
        }
        else if(cmd == 'G'){    // get 연산
            scanf("%d", &r);    // 연결 순위
            getchar();
            get(&list, r);
        }
        else if(cmd == 'P'){    // print 연산
            print(&list);
        }
    }
    freeNode(&list);            // 메모리 해제

    return 0;
}
void add(List *plist, int r, char data){    // add
    Node *newNode = NULL;                   // 삽입할 노드 생성
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *tmpNode = plist->header;          // 삽입할 newNode의 앞 노드 초기화
    int i, flag = 0;                        // flag 초기화.
    for(i=1; i<r; i++){
        tmpNode = tmpNode->next;            // tmpNode는 next로 계속 이동하면서 r-1번째 연결된 노드를 찾아간다.

        if(tmpNode->data == 0){             // tmpNode의 데이터가 0이다: trailer에 도착했다.
            flag = 1;                       // tmpNode = trailer라면 flag를 1로 바꿔준다.
            break;
        }
    }
    if(flag){                               // flag가 변경되었다면 오류 메세지를 출력하고 함수를 종료
        printf("invalid position\n");
        return;
    }

    // 링크 삽입
    // 1. 기존 링크 건드리지 말고 새노드의 prev, next 지정
    newNode->prev = tmpNode;                // 새노드의 prev은 r-1번째 연결된 'tmpNode'를 가리킴             
    newNode->next = tmpNode->next;          // 새노드의 next는 r번째 연결돼 있던 'tmpNode의 next'를 가리킴
    // 2. 기존 링크 수정
    tmpNode->next->prev = newNode;          // 기존 r번째 연결돼 있던 'tmpNode의 next'의 prev이 newNode를 가리킴 
    tmpNode->next = newNode;                // r-1번째 연결된 'tmpNode'의 next가 newNode를 가리킴
}
void delete(List *plist, int r){            // delete
    Node *delNode = plist->header;          // 삭제할 노드 초기화.
    int i, flag = 0;                        // flag 초기화.
    for(i=0; i<r; i++){
        delNode = delNode->next;            // delNode가 next로 계속 이동하면서 r번째 연결 노드를 찾음

        if(delNode->data == 0){             // 유효성 검사: delNode가 trailer에 도착하면
            flag = 1;
            break;
        }
    }
    if(flag){                               //flag가 변경되었다면 에러 메세지 후 함수 종료
        printf("invalid position\n");
        return;
    }
    delNode->prev->next = delNode->next;    // 'delNode의 앞 노드'의 next를 수정
    delNode->next->prev = delNode->prev;    // 'delNode의 뒷 노드'의 prev을 수정
    free(delNode);                          // 삭제할 노드 메모리 해제
}
void get(List *plist, int r){               // get
    Node *getNode = plist->header;          // 출력할 원소 노드 초기화.
    int i, flag = 0;                        // flag 초기화.
    for(i=0; i<r; i++){                     
        getNode = getNode->next;            // getNode는 next로 계속 이동하면서 r번째 연결 노드를 찾음.

        if(getNode->data == 0){             // 유효성 검사: getNode가 trailer에 도착하면
            flag = 1;
            break;
        }
    }
    if(flag){                               // flag가 변경되었다면 에러 메세지 출력 후 함수 종료
        printf("invalid position\n");
        return;
    }
    printf("%c\n", getNode->data);          // 원소 출력
}
void print(List *plist){                    // print
    Node *node = plist->header->next;       // while문 돌면서 출력할 건데 plist->header를 가리키면 데이터가 아무 것도 없는 header의 데이터를 출력하고 시작함

    while(node->next != NULL){              // node가 trailer가 아닐 때까지
        printf("%c", node->data);           // node의 데이터 출력
        node = node->next;                  // node는 자신의 다음 노드로 이동
    }
    printf("\n");
}
void freeNode(List *plist){                 // 메모리 해제
    Node *freeNode = plist->header->next;   // plist의 header 노드는 동적으로 할당하지 않았기 때문에 'header의 next', 1번째 연결 노드를 가리키고 시작.
    while(1){
        if(freeNode->data == 0)             // trailer인지 아닌지
            break;
        freeNode = freeNode->next;          // freeNode는 다음으로
        free(freeNode->prev);               // freeNode의 prev을 free
        // 이렇게 짠 이유
        // freeNode가 r번째를 가리키고 있는 상황에서 r번째 노드를 free하면 r+1번째로 갈 방법이 없어진다.
    }
}