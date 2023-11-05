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

typedef struct __vnode{
    int data;
    struct __vnode *next;
    struct __inode *iList;
}VNode;

typedef struct __inode{
    struct __enode *e;
    struct __inode *next;
}INode;

typedef struct __enode{
    struct __vnode *start;
    struct __vnode *end;
    struct __enode *next;
    int w;
}ENode;

VNode *vList;
ENode *eList;

VNode *getVNode(int data);
ENode *getENode(VNode *v1, VNode *v2, int w);
INode *getINode(ENode *e);
VNode *findVNode(int data);
ENode *findENode(VNode *v1, VNode *v2);
VNode *findAdjacentVNode(ENode *e, VNode *v);
void insertINode(VNode *v, ENode *e);
void insertENode(ENode *e);

VNode *createVertexList();
ENode *createEdgeList();

void printAdjacent(int n);
void modifyEdgeWeight(int n1, int n2, int w);

void freeGraph();
void freeEdgeList();
void freeVertexList();

int main()
{
    vList = createVertexList();
    eList = createEdgeList();

    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'q'){
            break;
        }

        if(cmd == 'a'){
            scanf("%d", &data);
            getchar();

            printAdjacent(data);
        } else if(cmd == 'm'){
            int n1, n2;
            scanf("%d %d %d", &n1, &n2, &data);
            getchar();

            modifyEdgeWeight(n1, n2, data);
        }
    }

    freeGraph();    //메모리 해제

    return 0;
}
VNode *getVNode(int data){
    VNode *newNode = (VNode *)malloc(sizeof(VNode));
    newNode->data = data;
    newNode->next = NULL;

    INode *iList = (INode *)malloc(sizeof(INode));
    iList->e = NULL;
    iList->next = NULL;
    newNode->iList = iList;

    return newNode;
}
ENode *getENode(VNode *v1, VNode *v2, int w){
    ENode *newNode = (ENode *)malloc(sizeof(ENode));
    newNode->start = v1;
    newNode->end = v2;
    newNode->w = w;
    newNode->next = NULL;

    return newNode;
}
INode *getINode(ENode *e){
    INode *newNode = (INode *)malloc(sizeof(INode));
    newNode->e = e;
    newNode->next = NULL;

    return newNode;
}
VNode *findVNode(int data){
    VNode *ptr = vList;
    while(ptr){
        if(ptr->data == data){
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}
ENode *findENode(VNode *v1, VNode *v2){
    ENode *ptr = eList;

    while(ptr){
        if((ptr->start == v1 && ptr->end == v2) || (ptr->start == v2 && ptr->end == v1)){
            break;
        }
        ptr = ptr->next;
    }

    return ptr;
}
VNode *findAdjacentVNode(ENode *e, VNode *v){
    VNode *tmp = e->start;
    if(tmp == v){
        tmp = e->end;
    }
    return tmp;
}
void insertINode(VNode *v, ENode *e){
    INode *i = getINode(e);

    INode *ptr = v->iList;
    while(ptr->next){
        if(findAdjacentVNode(ptr->next->e, v)->data > findAdjacentVNode(i->e, v)->data){
            i->next = ptr->next;
            ptr->next = i;
            return;
        }
        ptr = ptr->next;
    }

    ptr->next = i;
}
void insertENode(ENode *e){
    ENode *ptr = eList;
    while(ptr->next){
        ptr = ptr->next;
    }

    ptr->next = e;
}
VNode *createVertexList(){
    VNode *node = getVNode(1);
    VNode *ptr = node;

    for(int i=2; i<=6; i++){
        VNode *tmp = getVNode(i);
        ptr->next = tmp;
        ptr = ptr->next;
    }

    return node;
}
ENode *createEdgeList(){
    ENode *node1 = getENode(findVNode(1), findVNode(2), 1);
    insertINode(findVNode(1), node1);
    insertINode(findVNode(2), node1);

    ENode *node2 = getENode(findVNode(1), findVNode(3), 1);
    node1->next = node2;
    insertINode(findVNode(1), node2);
    insertINode(findVNode(3), node2);

    ENode *node3 = getENode(findVNode(1), findVNode(4), 1);
    node2->next = node3;
    insertINode(findVNode(1), node3);
    insertINode(findVNode(4), node3);

    ENode *node4 = getENode(findVNode(1), findVNode(6), 2);
    node3->next = node4;
    insertINode(findVNode(1), node4);
    insertINode(findVNode(6), node4);

    ENode *node5 = getENode(findVNode(2), findVNode(3), 1);
    node4->next = node5;
    insertINode(findVNode(2), node5);
    insertINode(findVNode(3), node5);
    
    ENode *node6 = getENode(findVNode(3), findVNode(5), 4);
    node5->next = node6;
    insertINode(findVNode(3), node6);
    insertINode(findVNode(5), node6);

    ENode *node7 = getENode(findVNode(5), findVNode(5), 4);
    node6->next = node7;
    insertINode(findVNode(5), node7);

    ENode *node8 = getENode(findVNode(5), findVNode(6), 3);
    node7->next = node8;
    insertINode(findVNode(5), node8);
    insertINode(findVNode(6), node8);

    node8->next = NULL;

    return node1;
}
void printAdjacent(int n){
    VNode *v = findVNode(n);

    if(!v){
        printf("-1\n");
        return;
    }

    INode *ptr = v->iList->next;
    while(ptr){
        VNode *tmp = ptr->e->start;
        if(tmp == v){
            tmp = ptr->e->end;
        }

        if(ptr->e->w != 0){
            printf(" %d %d", tmp->data, ptr->e->w);
        }
        ptr = ptr->next;
    }
        printf("\n");
}
void modifyEdgeWeight(int n1, int n2, int w){
    VNode *v1 = findVNode(n1);
    VNode *v2 = findVNode(n2);

    if(!v1 || !v2){     //정점 못 찾음
        printf("-1\n");
        return;
    }

    ENode *e = findENode(v1, v2);
    
    if(e != NULL){
        e->w = w;
    } else{
        ENode *newENode = getENode(v1, v2, w);
        insertENode(newENode);
        if(v1 == v2){
            insertINode(v1, newENode);
        } else{
            insertINode(v1, newENode);
            insertINode(v2, newENode);
        }
    }
}
void freeGraph(){
    freeEdgeList();
    freeVertexList();
}
void freeEdgeList(){
    ENode *cur = eList;

    while(cur){
        ENode *next = cur->next;
        free(cur);
        cur = next;
    }
}
void freeVertexList(){
    VNode *curV = vList;

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