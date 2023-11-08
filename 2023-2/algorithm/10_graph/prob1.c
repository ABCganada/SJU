#include <stdio.h>
#include <stdlib.h>

/*
* 가중치의 값은 양수 음수 모두 가능
* 정점 개수 고정
* 간선 개수 변동 가능
* 무방향 가중그래프 + 인접리스트 구현
*
* a + n: n 정점과 인접한 정점과 간선 가중치 모두 인쇄
* 공백만 구분자
* 정점이 존재하지 않으면 -1 인쇄만
* 
* m + a, b, w: (a, b) 간선 가중치를 w로 변경.
* (a, b) 간선이 존재하지 않으면 간선 생성
* w = 0이면, 간선 삭제
* a 정점이나 b 정점 없으면 -1 인쇄만
*/

typedef struct __vnode{     //정점 노드
    int data;   //정점 노드 밸류
    struct __vnode *next;   //정점노드리스트를 위한 next 포인터
    struct __inode *iList;  //각 정점 노드의 부착 간선노드 리스트
}VNode;

typedef struct __inode{     //부착간선 노드
    struct __enode *e;  //간선노드 포인터
    struct __inode *next;   //부착간선리스트를 위한 next 포인터
}INode;

typedef struct __enode{     //간선 노드
    struct __vnode *v1;  //간선에 대한 endpoint 1
    struct __vnode *v2;    //간선에 대한 endpoint 2
    struct __enode *next;   //간선노드리스트를 위한 next 포인터
    int w;  //간선 가중치
}ENode;

VNode *vList;   //전역 변수, 정점 리스트
ENode *eList;   //전역 변수, 간선 리스트

VNode *getVNode(int data);  //정점 노드 생성 함수
ENode *getENode(VNode *v1, VNode *v2, int w);   //간선 노드 생성 함수
INode *getINode(ENode *e);  //부착간선 노드 생성 함수
VNode *findVNode(int data); //정점 노드 탐색 함수
ENode *findENode(VNode *v1, VNode *v2); //간선 노드 탐색 함수
VNode *findAdjacentVNode(ENode *e, VNode *v);   //간선 e에서 정점 v에 대한 끝점 리턴 함수
void insertINode(VNode *v, ENode *e);   //v에 대해 부착간선 노드 삽입 함수
void insertENode(ENode *e); //간선 노드 삽입 함수

VNode *createVertexList();  //초기 그래프 구현을 위한 정점노드리스트 생성 함수
ENode *createEdgeList();    //초기 그래프 구현을 위한 간선노드리스트 생성 함수

void printAdjacent(int n);  //n값의 정점에 대한 인접 정점과 가중치 출력 함수
void modifyEdgeWeight(int n1, int n2, int w);   //간선 가중치 수정 함수

void freeGraph();   //graph 내 노드 메모리 해제 함수
void freeEdgeList();    //간선노드리스트 메모리 해제 함수
void freeVertexList();  //정점노드리스트 메모리 해제 함수

int main()
{
    vList = createVertexList(); //초기 그래프를 위한 정점리스트 생성
    eList = createEdgeList();   //초기 그래프를 위한 간선리스트 생성

    char cmd;   //명령어
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'q'){ //명령이 q라면, 프로그램 종료
            break;
        }

        if(cmd == 'a'){ //인접노드 + 간선 가중치 출력 함수 호출
            scanf("%d", &data);
            getchar();

            printAdjacent(data);
        } else if(cmd == 'm'){  //간선 가중치 수정 함수 호출
            int n1, n2;
            scanf("%d %d %d", &n1, &n2, &data);
            getchar();

            modifyEdgeWeight(n1, n2, data);
        }
    }

    freeGraph();    //메모리 해제

    return 0;
}
VNode *getVNode(int data){  //정점 노드 생성 함수
    VNode *newNode = (VNode *)malloc(sizeof(VNode));
    newNode->data = data;
    newNode->next = NULL;

    INode *iList = (INode *)malloc(sizeof(INode)); //정점 생성과 동시에 부착간선리스트의 header를 생성
    iList->e = NULL;
    iList->next = NULL;
    newNode->iList = iList;

    return newNode;
}
ENode *getENode(VNode *v1, VNode *v2, int w){   //간선 노드 생성 함수
    ENode *newNode = (ENode *)malloc(sizeof(ENode));
    newNode->v1 = v1;
    newNode->v2 = v2;
    newNode->w = w;
    newNode->next = NULL;

    return newNode;
}
INode *getINode(ENode *e){  //부착간선 노드 생성 함수
    INode *newNode = (INode *)malloc(sizeof(INode));
    newNode->e = e;
    newNode->next = NULL;

    return newNode;
}
VNode *findVNode(int data){ //정점 노드 탐색 함수
    VNode *ptr = vList;
    while(ptr){
        if(ptr->data == data){  //data와 같은 값의 정점 찾으면 리턴
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;    //못 찾으면 널값 리턴
}
ENode *findENode(VNode *v1, VNode *v2){ //간선 노드 탐색 함수
    ENode *ptr = eList;

    while(ptr){ //v1, v2를 끝점으로 가지는 간선 찾으면 반복문 탈출
        if((ptr->v1 == v1 && ptr->v2 == v2) || (ptr->v1 == v2 && ptr->v2 == v1)){
            break;
        }
        ptr = ptr->next;
    }

    return ptr; //찾으면 해당 간선 리턴, 못 찾으면 NULL 리턴
}
VNode *findAdjacentVNode(ENode *e, VNode *v){   //간선 e에서 정점 v에 대한 끝점 리턴 함수
    VNode *tmp = e->v1;
    if(tmp == v){
        tmp = e->v2;
    }
    return tmp;
}
void insertINode(VNode *v, ENode *e){   //v에 대해 부착간선 노드 삽입 함수
    INode *i = getINode(e);

    INode *ptr = v->iList;
    while(ptr->next){   //부착간선의 인접 정점에 대한 data 값 오름차순으로 삽입함
        if(findAdjacentVNode(ptr->next->e, v)->data > findAdjacentVNode(i->e, v)->data){
            i->next = ptr->next;
            ptr->next = i;
            return;
        }
        ptr = ptr->next;
    }

    ptr->next = i;
}
void insertENode(ENode *e){ //간선 노드 삽입 함수
    //간선은 오름차순 상관없이 맨 뒤에 삽입한다.
    ENode *ptr = eList;
    while(ptr->next){
        ptr = ptr->next;
    }

    ptr->next = e;
}
VNode *createVertexList(){  //초기 그래프 구현을 위한 정점노드리스트 생성 함수
    VNode *node = getVNode(1);
    VNode *ptr = node;

    for(int i=2; i<=6; i++){
        VNode *tmp = getVNode(i);
        ptr->next = tmp;
        ptr = ptr->next;
    }

    return node;
}
ENode *createEdgeList(){    //초기 그래프 구현을 위한 간선노드리스트 생성 함수
    ENode *node1 = getENode(findVNode(1), findVNode(2), 1); //(1, 2)에 대한 가중치 1 간선
    insertINode(findVNode(1), node1);
    insertINode(findVNode(2), node1);

    ENode *node2 = getENode(findVNode(1), findVNode(3), 1); //(1, 3)에 대한 가중치 1 간선
    node1->next = node2;
    insertINode(findVNode(1), node2);
    insertINode(findVNode(3), node2);

    ENode *node3 = getENode(findVNode(1), findVNode(4), 1); //(1, 4)에 대한 가중치 1 간선
    node2->next = node3;
    insertINode(findVNode(1), node3);
    insertINode(findVNode(4), node3);

    ENode *node4 = getENode(findVNode(1), findVNode(6), 2); //(1, 6)에 대한 가중치 2 간선
    node3->next = node4;
    insertINode(findVNode(1), node4);
    insertINode(findVNode(6), node4);

    ENode *node5 = getENode(findVNode(2), findVNode(3), 1); //(2, 3)에 대한 가중치 1 간선
    node4->next = node5;
    insertINode(findVNode(2), node5);
    insertINode(findVNode(3), node5);
    
    ENode *node6 = getENode(findVNode(3), findVNode(5), 4); //(3, 5)에 대한 가중치 4 간선
    node5->next = node6;
    insertINode(findVNode(3), node6);
    insertINode(findVNode(5), node6);

    ENode *node7 = getENode(findVNode(5), findVNode(5), 4); //(5, 5)에 대한 가중치 4 간선
    node6->next = node7;
    insertINode(findVNode(5), node7);

    ENode *node8 = getENode(findVNode(5), findVNode(6), 3); //(5, 6)에 대한 가중치 3 간선
    node7->next = node8;
    insertINode(findVNode(5), node8);
    insertINode(findVNode(6), node8);

    return node1;
}
void printAdjacent(int n){  //n값의 정점에 대한 인접 정점과 가중치 출력 함수
    VNode *v = findVNode(n);    //n에 대한 정점 탐색

    if(!v){ //탐색 실패의 경우, -1 출력 후 함수 종료
        printf("-1\n");
        return;
    }

    INode *ptr = v->iList->next;    //헤더의 next부터 ptr가 시작됨
    while(ptr){
        VNode *tmp = findAdjacentVNode(ptr->e, v);
        if(ptr->e->w != 0){
            printf(" %d %d", tmp->data, ptr->e->w);
        }
        ptr = ptr->next;
    }
        printf("\n");
}
void modifyEdgeWeight(int n1, int n2, int w){   //간선 가중치 수정 함수
    VNode *v1 = findVNode(n1);  //n1 정점 탐색
    VNode *v2 = findVNode(n2);  //n2 정점 탐색

    if(!v1 || !v2){     //정점 탐색 실패
        printf("-1\n");
        return;
    }

    ENode *e = findENode(v1, v2);   //v1, v2에 대한 간선이 있는지 탐색
    
    if(e != NULL){  //v1, v2에 대한 간선이 있다면 가중치만 변경
        e->w = w;
    } else{         //v1, v2에 대한 간선이 없다면 간선 새로 생성
        ENode *newENode = getENode(v1, v2, w);  //(v1, v2)의 가중치 w 간선 생성
        insertENode(newENode);  //간선리스트에 삽입
        if(v1 == v2){   //loop 간선이라면, 부착간선리스트에는 1번만 삽입
            insertINode(v1, newENode);
        } else{     //loop 간선이 아니라면, v1과 v2 각각의 부착간선리스트에 삽입해줘야 함
            insertINode(v1, newENode);
            insertINode(v2, newENode);
        }
    }
}
void freeGraph(){   //graph 내 노드 메모리 해제 함수
    freeEdgeList(); //간선리스트 메모리 해제 호출
    freeVertexList();   //정점리스트 메모리 해제 호출
}
void freeEdgeList(){    //간선노드리스트 메모리 해제 함수
    ENode *cur = eList;

    while(cur){
        ENode *next = cur->next;
        free(cur);
        cur = next;
    }
}
void freeVertexList(){  //정점노드리스트 메모리 해제 함수
    VNode *curV = vList;

    /*
    * 외부 반복문: 정점 노드 메모리 해제
    * 내부 반복문: 부착간선 노드 메모리 해제
    * */

    while(curV){
        VNode *nextV = curV->next;

        INode *cur = curV->iList;
        while(cur){
            INode *next = cur->next;
            free(cur);
            cur = next;
        }

        free(curV);
        curV = nextV;
    }
}