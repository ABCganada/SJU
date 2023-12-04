#include <stdio.h>
#include <stdlib.h>

/*
* 무방향 양의 가중 그래프.
*/

#define INIT_D_VALUE 30000

typedef struct __priorityQ{
    struct __vnode *pq[101];
    int head, rear;
}PriorityQ;

typedef struct __inode{
    int vIdx1, vIdx2, w;
    struct __inode *next;
}INode;

typedef struct __vnode{
    int vNum, distance;
    struct __vnode *locator;
    struct __inode *iList;
}VNode;

VNode vList[100];
PriorityQ h;
int n, m;

void initHeap();
void enqueue(VNode *v);
void buildHeap(int i);
void downHeap(int i);
void swap(VNode **v1, VNode **v2);
VNode *removeMin();
int isEmpty();
int isInQueue(VNode *v);

void initVertexList();

INode *getINode(int vNum1, int vNum2, int w);
void insertEdge(int vNum1, int vNum2, int w);

void DijkstraShortestPath(int s);

void freeMemory();

int main()
{
    int s, vNum1, vNum2, w;
    scanf("%d %d %d", &n, &m, &s);

    initVertexList();

    for(int i=0; i<m; i++){
        scanf("%d%d%d", &vNum1, &vNum2, &w);

        insertEdge(vNum1, vNum2, w);
        insertEdge(vNum2, vNum1, w);
    }

    DijkstraShortestPath(s);

    for(int i=0; i<n; i++){
        if(i != s-1 && vList[i].distance != INIT_D_VALUE){
            printf("%d %d\n", vList[i].vNum, vList[i].distance);
        }
    }

    freeMemory();

    return 0;
}
void initHeap(){
    h.head = 1;
    h.rear = 1;
}
void enqueue(VNode *v){
    h.pq[h.rear++] = v;
    v->locator = h.pq[h.rear-1];
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
    int leftChild, rightChild, smallChild;

    while(2*i < h.rear){
        leftChild = 2*i;
        rightChild = 2*i + 1;

        if(rightChild < h.rear){
            smallChild = h.pq[leftChild]->distance < h.pq[rightChild]->distance ? leftChild : rightChild;
        } else{
            smallChild = leftChild;
        }

        if(h.pq[i]->distance > h.pq[smallChild]->distance){
            swap(&h.pq[i], &h.pq[smallChild]);
            i = smallChild;
        } else{
            break;
        }
    }
}
void swap(VNode **v1, VNode **v2){
    VNode *tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;

    (*v1)->locator = *v1;
    (*v2)->locator = *v2;
}
VNode *removeMin(){
    VNode *ret = h.pq[h.head];
    swap(&h.pq[h.head], &h.pq[h.rear-1]);
    h.rear--;
    buildHeap(1);

    ret->locator = NULL;

    return ret;
}
int isEmpty(){
    if(h.head == h.rear){
        return 1;
    }
    return 0;
}
int isInQueue(VNode *v){
    return v->locator != NULL;
}
void initVertexList(){
    for(int i=0; i<n; i++){
        vList[i].vNum = i+1;
        vList[i].distance = INIT_D_VALUE;
        vList[i].locator = NULL;

        vList[i].iList = (INode *)malloc(sizeof(INode));
        vList[i].iList->next = NULL;
    }
}
INode *getINode(int vNum1, int vNum2, int w){
    INode *newNode = (INode *)malloc(sizeof(INode));
    newNode->vIdx1 = vNum1-1;
    newNode->vIdx2 = vNum2-1;
    newNode->w = w;
    newNode->next = NULL;

    return newNode;
}
void insertEdge(int vNum1, int vNum2, int w){
    INode *newNode = getINode(vNum1, vNum2, w);

    INode *ptr = vList[vNum1-1].iList;

    while(ptr->next){
        ptr = ptr->next;
    }

    ptr->next = newNode;
}
void DijkstraShortestPath(int s){
    initHeap();

    vList[s-1].distance = 0;

    for(int i=0; i<n; i++){     //enqueue
        enqueue(&vList[i]);
    }

    buildHeap(1);   //힙 생성

    while(!isEmpty()){
        VNode *u = removeMin();

        INode *e = u->iList->next;
        while(e){
            VNode *z = &vList[e->vIdx2];
            
            if(isInQueue(z)){
                if(z->distance > u->distance + e->w){
                    z->distance = u->distance + e->w;
                    buildHeap(1);
                }
            }
            e = e->next;
        }
    }
}
void freeMemory(){
    for(int i=0; i<n; i++){
        INode *cur = vList[i].iList;
        while(cur){
            INode *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}