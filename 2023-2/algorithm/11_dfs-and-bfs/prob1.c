#include <stdio.h>
#include <stdlib.h>

typedef struct __vnode{
    int n, visit;
    struct __inode *iList;
}VNode;

typedef struct __enode{
    int v1;
    int v2;
    int visit;
}ENode;

typedef struct __inode{
    int eIdx;
    struct __inode *next;
}INode;

VNode *vList;
ENode *eList;

int n, m, s;

void initVertexList();
void initEdgeList();

INode *getINode(int i);

void insertEdge(int n1, int n2, int i);
void insertIncident(VNode *v, int i);

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    
    initVertexList();
    initEdgeList();

    int n1, n2;
    
    for(int i=0; i<m; i++){
        scanf("%d%d", &n1, &n2);
        insertEdge(n1, n2, i);
    }

    return 0;
}
void initVertexList(){
    vList = (VNode *)malloc(sizeof(VNode) * n);
    for(int i=0; i<n; i++){
        vList[i].n = i+1;
        vList[i].visit = 0;

        vList[i].iList = (INode *)malloc(sizeof(INode));
        vList[i].iList->next = NULL;
    }
}
void initEdgeList(){
    eList = (ENode *)malloc(sizeof(ENode) * m);
}
INode *getINode(int i){
    INode *newNode = (INode *)malloc(sizeof(INode));
    newNode->eIdx = i;
    newNode->next = NULL;

    return newNode;
}
void insertEdge(int n1, int n2, int i){
    VNode *v1 = &vList[n1-1];
    VNode *v2 = &vList[n2-1];

    eList[i].v1 = n1-1;
    eList[i].v2 = n2-1;
    eList[i].visit = 0;
    insertIncident(v1, i);
    insertIncident(v2, i);
}
void insertIncident(VNode *v, int i){
    INode *ptr = v->iList;
    while(ptr->next){
        ptr = ptr->next;
    }

    INode *newNode = getINode(i);
    ptr->next = newNode;
}