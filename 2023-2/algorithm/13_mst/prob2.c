#include <stdio.h>
// #include <stdlib.h>

/*
* Kruskal 알고리즘
* 정정 노드가 아닌 간선 무게 출력
*/

typedef struct __sack{
    int sNum;
}Sack;
typedef struct __vnode{
    int vNum, d;
    int *parent;
    struct __vnode *loaction;
    struct __sack sack;
}VNode;

typedef struct __enode{
    int vIdx1, vIdx2, w;
}ENode;

typedef struct __graph{
    struct __vnode vList[100];
    struct __enode eList[1000];
    int eListRear;
}Graph;

typedef struct __heap{
    struct __enode *queue[1000];
    int head, rear;
}Heap;

int n, m;
Graph g;
Heap h;

void initHeap();
void buildHeap(int i);
void downHeap(int i);
int isEmpty();
int isInQueue(ENode *v);
void swap(ENode **v1, ENode **v2);
ENode *removeMin();

void initVertexList();
void initEdgeList();

void insertEdge(int vNum1, int vNum2, int w);

int kruskalMST();

int main()
{
    scanf("%d%d", &n, &m);
    initVertexList();
    initEdgeList();

    int vNum1, vNum2, w;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &vNum1, &vNum2, &w);
        insertEdge(vNum1, vNum2, w);
    }

    int sum = kruskalMST();

    printf("%d\n", sum);

    return 0;
}
void initHeap(){
    h.head = h.rear = 1;
}
void buildHeap(int i){
    if(i > h.rear){
        return;
    }

    buildHeap(2*i);
    buildHeap(2*i + 1);
    downHeap(i);
}
void downHeap(int i){
    int leftChild;
    int rightChild;
    int smallChild;

    while(2*i < h.rear){
        leftChild = 2*i;
        rightChild = 2*i + 1;

        if(rightChild < h.rear){
            smallChild = h.queue[leftChild]->w < h.queue[rightChild]->w ? leftChild : rightChild;
        } else{
            smallChild = leftChild;
        }

        if(h.queue[i]->w > h.queue[smallChild]->w){
            swap(&h.queue[i], &h.queue[smallChild]);
            i = smallChild;
        } else{
            break;
        }
    }
}
int isEmpty(){
    if(h.head == h.rear){
        return 1;
    }

    return 0;
}
int isInQueue(ENode *e){
    for(int i=h.head; i<h.rear; i++){
        if(e == h.queue[i]){
            return 1;
        }
    }
    return 0;
}
void swap(ENode **v1, ENode **v2){
    ENode *tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}
ENode *removeMin(){
    swap(&h.queue[h.head], &h.queue[h.rear - 1]);
    h.rear--;

    ENode *ret = h.queue[h.rear];
    downHeap(1);

    return ret;
}
void initVertexList(){
    for(int i=0; i<n; i++){
        g.vList[i].vNum = i+1;
        g.vList[i].d = 99999999;
        g.vList[i].parent = NULL;
        g.vList[i].loaction = NULL;
        g.vList[i].sack.sNum = i+1;
    }
}
void initEdgeList(){
    g.eListRear = 0;
}
void insertEdge(int vNum1, int vNum2, int w){
    g.eList[g.eListRear].vIdx1 = vNum1-1;
    g.eList[g.eListRear].vIdx2 = vNum2-1;
    g.eList[g.eListRear++].w = w;
}
int kruskalMST(){
    int wSum = 0;

    initHeap();
    for(int i=0; i<g.eListRear; i++){
        h.queue[h.rear++] = &g.eList[i];
    }

    buildHeap(1);

    

    return wSum;
}