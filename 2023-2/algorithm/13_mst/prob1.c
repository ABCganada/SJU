#include <stdio.h>
// #include <stdlib.h>

/*
* Prim 알고리즘
*/

typedef struct __vnode{
    int vNum, d;
    int *parent;
    struct __vnode *loaction;
}VNode;

typedef struct __graph{
    struct __vnode vList[101];
    int matrix[101][101];
}Graph;

typedef struct __heap{
    struct __vnode *queue[200];
    int head, rear;
}Heap;

int n, m;
Graph g;
Heap h;

void initHeap();
void buildHeap(int i);
void downHeap(int i);
int isEmpty();
int isInQueue(VNode *v);
void swap(VNode **v1, VNode **v2);
VNode *removeMin();
void replaceKey(VNode *v, int w);

void initVertexList();
void initMatrix();

void insertEdge(int vNum1, int vNum2, int w);

int primMST(int start);

int main()
{
    scanf("%d%d", &n, &m);
    initVertexList();
    initMatrix();

    int vNum1, vNum2, w;
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &vNum1, &vNum2, &w);
        insertEdge(vNum1, vNum2, w);
    }

    int sum = primMST(1);

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
            smallChild = h.queue[leftChild]->d < h.queue[rightChild]->d ? leftChild : rightChild;
        } else{
            smallChild = leftChild;
        }

        if(h.queue[i]->d > h.queue[smallChild]->d){
            // printf(">> swap: %d(%d) %d(%d)\n", h.queue[i]->vNum, h.queue[i]->d, h.queue[smallChild]->vNum, h.queue[smallChild]->d);
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
int isInQueue(VNode *v){
    for(int i=h.head; i<h.rear; i++){
        if(v == h.queue[i]){
            return 1;
        }
    }
    return 0;
}
void swap(VNode **v1, VNode **v2){
    VNode *tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}
VNode *removeMin(){
    swap(&h.queue[h.head], &h.queue[h.rear - 1]);
    h.rear--;

    VNode *ret = h.queue[h.rear];
    downHeap(1);

    return ret;
}
void initVertexList(){
    for(int i=0; i<n; i++){
        g.vList[i].vNum = i+1;
        g.vList[i].d = 99999999;
        g.vList[i].parent = NULL;
        g.vList[i].loaction = NULL;
    }
}
void initMatrix(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            g.matrix[i][j] = -1;
        }
    }
}
void insertEdge(int vNum1, int vNum2, int w){
    g.matrix[vNum1-1][vNum2-1] = w;
    g.matrix[vNum2-1][vNum1-1] = w;
}
int primMST(int start){
    int wSum = 0;
    g.vList[start-1].d = 0;

    for(int i=0; i<n; i++){
        if(g.matrix[start-1][i] != -1){
            g.vList[i].d = g.matrix[start-1][i];
        }
    }

    initHeap();
    for(int i=0; i<n; i++){
        h.queue[h.rear++] = &g.vList[i];
    }

    buildHeap(1);   //힙 생성

    while(!isEmpty()){
        VNode *u = removeMin();
        printf(" %d", u->vNum);
        wSum += u->d;

        for(int i=0; i<n; i++){
            if(g.matrix[u->vNum - 1][i] >= 0){
                VNode *z = &g.vList[i];
                if(isInQueue(z) && g.matrix[u->vNum - 1][z->vNum - 1] <= z->d){
                    z->d = g.matrix[u->vNum - 1][z->vNum - 1];
                    z->parent = &g.matrix[u->vNum - 1][z->vNum - 1];
                    buildHeap(1);
                }
            }
        }
    }
    printf("\n");

    return wSum;
}