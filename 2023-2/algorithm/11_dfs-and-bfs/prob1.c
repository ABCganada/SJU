#include <stdio.h>
#include <stdlib.h>

typedef struct __vnode{
    int n, visit;   //0: init, 1: visited
    struct __inode *iList;
}VNode;

typedef struct __enode{
    int v1;
    int v2;
    int visit;  //0: init, 1: tree, -1: back
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
int getOppositeVertexIndex(int eIdx, int vIdx);

void insertEdge(int n1, int n2, int i);
void insertIncident(int v, int i);

void dfs(int n);

void freeGraph();
void freeIncident(int i);

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

    dfs(s-1);
    
    freeGraph();

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
int getOppositeVertexIndex(int eIdx, int vIdx){
    int ret = eList[eIdx].v1;
    if(ret == vIdx){
        ret = eList[eIdx].v2;
    }

    return ret;
}
void insertEdge(int n1, int n2, int i){
    eList[i].v1 = n1-1;
    eList[i].v2 = n2-1;
    eList[i].visit = 0;
    insertIncident(n1-1, i);
    insertIncident(n2-1, i);
}
void insertIncident(int v, int i){
    INode *newNode = getINode(i);
    int oppositeIdx = getOppositeVertexIndex(i, v);

    INode *ptr = vList[v].iList;

    while(ptr->next){
        if(getOppositeVertexIndex(ptr->next->eIdx, v) > oppositeIdx){
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }
        ptr = ptr->next;
    }

    ptr->next = newNode;
}
void dfs(int k){
    vList[k].visit = 1;
    printf("%d\n", k+1);

    INode *ptr = vList[k].iList->next;
    while(ptr){
        if(eList[ptr->eIdx].visit == 0){
            int oppositeV = getOppositeVertexIndex(ptr->eIdx, k);
            if(vList[oppositeV].visit == 0){
                eList[ptr->eIdx].visit = 1;
                dfs(oppositeV);
            } else{
                eList[ptr->eIdx].visit = -1;
            }
        }
        ptr = ptr->next;
    }
}
void freeGraph(){
    for(int i=0; i<n; i++){
        freeIncident(i);
    }

    free(vList);
    free(eList);
}
void freeIncident(int i){
    INode *cur = vList[i].iList;

    while(cur){
        INode *next = cur->next;
        free(cur);
        cur = next;
    }
}