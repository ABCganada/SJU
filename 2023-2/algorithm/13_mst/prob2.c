#include <stdio.h>

/*
* Kruskal 알고리즘
* 정정 노드가 아닌 간선 무게 출력
*/

typedef struct __sack{
    int sNum, size;
    struct __vnode *arr[100];
}Sack;

typedef struct __vnode{
    int vNum, d, sackIdx;
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
Sack sack[100];

void initHeap();            //힙 우선순위 큐 함수
void buildHeap(int i);
void downHeap(int i);
int isEmpty();
void swap(ENode **v1, ENode **v2);
ENode *removeMin();
void heapSort();

void initVertexList();      //그래프 데이터 구조 초기화 함수
void initEdgeList();
void initSack();

void insertEdge(int vNum1, int vNum2, int w);   //간선 삽입 함수

int kruskalMST();   //Kruskal MST 알고리즘

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
    int bigChild;

    while(2*i < h.rear){
        leftChild = 2*i;
        rightChild = 2*i + 1;

        if(rightChild < h.rear){
            bigChild = h.queue[leftChild]->w > h.queue[rightChild]->w ? leftChild : rightChild;
        } else{
            bigChild = leftChild;
        }

        if(h.queue[i]->w < h.queue[bigChild]->w){
            swap(&h.queue[i], &h.queue[bigChild]);
            i = bigChild;
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
void swap(ENode **v1, ENode **v2){
    ENode *tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;
}
ENode *removeMin(){
    ENode *ret = h.queue[h.head++];
    return ret;
}
void heapSort(){
    buildHeap(1);

    int lastIdx = h.rear-1;
    for(int i=lastIdx; i>=2; i--){
        swap(&h.queue[1], &h.queue[i]);
        h.rear--;
        downHeap(1);
    }
    h.rear = lastIdx + 1;
}
void initVertexList(){
    for(int i=0; i<n; i++){
        g.vList[i].vNum = i+1;
        g.vList[i].d = 99999999;
        g.vList[i].sackIdx = i;
    }
}
void initEdgeList(){
    g.eListRear = 0;
}
void initSack(){
    for(int i=0; i<n; i++){
        sack[i].size = 0;
        sack[i].sNum = g.vList[i].vNum;
        sack[i].arr[sack[i].size++] = &g.vList[i];
    }
}
void insertEdge(int vNum1, int vNum2, int w){
    g.eList[g.eListRear].vIdx1 = vNum1-1;
    g.eList[g.eListRear].vIdx2 = vNum2-1;
    g.eList[g.eListRear++].w = w;
}
int kruskalMST(){
    int wSum = 0;

    initSack();
    initHeap();

    for(int i=0; i<g.eListRear; i++){
        h.queue[h.rear++] = &g.eList[i];
    }

    heapSort();

    while(!isEmpty()){
        ENode *e = removeMin();
        int v1 = e->vIdx1;
        int v2 = e->vIdx2;

        int sackIdx1 = g.vList[v1].sackIdx;
        int sackIdx2 = g.vList[v2].sackIdx;
        if(sack[sackIdx1].sNum != sack[sackIdx2].sNum){
            printf(" %d", e->w);
            wSum += e->w;

            Sack *targetSack = sack[sackIdx1].size > sack[sackIdx2].size ? &sack[sackIdx1] : &sack[sackIdx2];
            Sack *modifySack = &sack[sackIdx1];
            if(modifySack->sNum == targetSack->sNum){
                modifySack = &sack[sackIdx2];
            }

            modifySack->sNum = targetSack->sNum;
            for(int i=0; i<modifySack->size; i++){
                targetSack->arr[targetSack->size++] = modifySack->arr[i];
                modifySack->arr[i]->sackIdx = targetSack->arr[0]->sackIdx;
            }
            modifySack->size = 0;
        }
    }
    printf("\n");

    return wSum;
}