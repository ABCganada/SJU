#include <stdio.h>
#include <stdlib.h>

/*
* 1개의 Dijkstra 확장 알고리즘 작성.
* G는 프로그램 수행 초기에 인접리스트 구조로 초기화한다.
*/

#define INIT_D_VALUE 30000  //정점 노드 초기 거리값
#define VERTEX_NUM 6        //정점 노드 수
#define EDGE_NUM 9          //간선 노드 수

typedef struct __priorityQ{ //우선순위큐
    struct __vnode *pq[101];
    int head, rear;
}PriorityQ;

typedef struct __vnode{     //정점 노드
    char v; //정점 알파벳
    int distance;   //거리값
    int equalPathNum;   //최단경로 개수
    struct __inode *iList;  //부착간선리스트
    struct __vnode *locator;    //우선순위 큐 위치자
}VNode;

typedef struct __inode{     //부착간선 노드
    int startIdx, targetIdx, w; 
    struct __inode *next;
}INode;

VNode vList[100];   //정점 개수 변동 고려
PriorityQ h;    //우선순위 큐 전역 변수 선언

//힙 함수
void initHeap();
void enqueue(VNode *v);
void buildHeap(int i);
void downHeap(int i);
void swap(VNode **v1, VNode **v2);
VNode *removeMin();
int isEmpty();
int isInQueue(VNode *v);

void initGraph();   //그래프 생성
INode *getINode(int startIdx, int targetIdx, int w);    //부착간선 노드 생성
void insertIncident(int v1Idx, int v2Idx, int w);   //부착간선 삽입
void DijkstraShortestPath(char start, char target); //다익스트라 알고리즘
void printResult(char start, char target);  //출력 함수

void freeMemory();  //메모리 해제

int main()
{
    DijkstraShortestPath('C', 'A');
    freeMemory();

    DijkstraShortestPath('C', 'F');
    freeMemory();

    DijkstraShortestPath('F', 'C');
    freeMemory();

    DijkstraShortestPath('B', 'D');
    freeMemory();

    return 0;
}
void initHeap(){    //힙 초기화
    h.head = 1;
    h.rear = 1;
}
void enqueue(VNode *v){ //정점 노드 우선순위 큐 삽입 함수
    h.pq[h.rear++] = v;
    v->locator = h.pq[h.rear-1];
}
void buildHeap(int i){  //힙 생성 함수
    if(i > h.rear){
        return;
    }

    buildHeap(2*i);
    buildHeap(2*i + 1);
    downHeap(i);
}
void downHeap(int i){   //down heap 함수
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
void swap(VNode **v1, VNode **v2){  //swap 함수
    VNode *tmp = *v1;
    *v1 = *v2;
    *v2 = tmp;

    (*v1)->locator = *v1;
    (*v2)->locator = *v2;
}
VNode *removeMin(){     //dequeue 함수
    VNode *ret = h.pq[h.head];  //return할 vNode.
    swap(&h.pq[h.head], &h.pq[h.rear-1]);   //맨 처음이랑 맨 뒤 스왑
    h.rear--;   //힙의 rear 하나 줄여줌
    buildHeap(1);

    ret->locator = NULL;    //리턴할 노드 로케이터 NULL. 힙 구조에서 remove 됐으니깐

    return ret;
}
int isEmpty(){  //힙 원소 있는지 없는지 검사
    return h.head == h.rear;
}
int isInQueue(VNode *v){    //정점 노드 힙에 있는지 없는지 검사
    return v->locator != NULL;  //로케이터가 NULL이 아니면 힙에 있다는 것
}
void initGraph(){   //그래프 초기화 함수
    char alp = 'A';
    for(int i=0; i<VERTEX_NUM; i++){    //정점노드 리스트 초기화
        vList[i].v = alp++;
        vList[i].distance = INIT_D_VALUE;
        vList[i].locator = NULL;
        vList[i].equalPathNum = 0;

        vList[i].iList = (INode *)malloc(sizeof(INode));
        vList[i].iList->next = NULL;
    }

    alp = 'A';
    insertIncident('A'-alp, 'B'-alp, 8);    //9개 간선 삽입
    insertIncident('A'-alp, 'C'-alp, 1);
    insertIncident('A'-alp, 'D'-alp, 4);
    insertIncident('B'-alp, 'C'-alp, 7);
    insertIncident('B'-alp, 'E'-alp, 4);
    insertIncident('C'-alp, 'D'-alp, 5);
    insertIncident('C'-alp, 'E'-alp, 3);
    insertIncident('C'-alp, 'F'-alp, 9);
    insertIncident('D'-alp, 'F'-alp, 4);
}
void insertIncident(int v1Idx, int v2Idx, int w){       //부착간선 노드 삽입 함수
    //무방향 간선이기에 v1 -> v2, v2 -> v1
    //2번 삽입 진행
    INode *node1 = getINode(v1Idx, v2Idx, w);   //v1 -> v2 
    INode *node2 = getINode(v2Idx, v1Idx, w);   //v2 -> v1

    INode *i1 = vList[v1Idx].iList;
    while(i1->next){
        i1 = i1->next;
    }
    i1->next = node1;

    INode *i2 = vList[v2Idx].iList;
    while(i2->next){
        i2 = i2->next;
    }
    i2->next = node2;
}
INode *getINode(int startIdx, int targetIdx, int w){    //부착간선 노드 생성
    INode *newNode = (INode *)malloc(sizeof(INode));
    newNode->startIdx = startIdx;
    newNode->targetIdx = targetIdx;
    newNode->w = w;
    newNode->next = NULL;

    return newNode;
}
void DijkstraShortestPath(char start, char target){     //다익스트라 알고리즘
    initGraph();    //그래프 생성
    initHeap();     //힙 초기화

    int startIdx = start - 'A';
    vList[startIdx].distance = 0;  //출발 정점 거리 초기화
    vList[startIdx].equalPathNum = 1;   //출발 정점 최단경로 개수 초기화

    for(int i=0; i<VERTEX_NUM; i++){
        enqueue(&vList[i]);
    }

    while(!isEmpty()){
        
        buildHeap(1);   //힙 생성
        
        VNode *u = removeMin();     //정점 추출
        INode *e = u->iList->next;

        while(e){   //추출한 정점의 부착간선 리스트 순회
            VNode *z = &vList[e->targetIdx];    //부착간선 기준 u의 상대 끝점

            if(isInQueue(z)){
                if(z->distance > u->distance + e->w){       //만약 z의 거리값이 더 크다면
                    z->distance = u->distance + e->w;   //z의 거리값 갱신
                    z->equalPathNum = u->equalPathNum;  //z의 최단경로 개수는 u의 최단경로 개수로 설정
                } else if(z->distance == u->distance + e->w){   //만약 z의 거리값과 같다면
                    z->equalPathNum += u->equalPathNum; //z의 최단경로 개수에 u의 최단경로 개수를 더함
                }
            }
            e = e->next;
        }
    }
    printResult(start, target); //start -> target까지의 최단거리와 최단경로 개수 출력
}
void printResult(char start, char target){  //출력 함수
    int targetIdx = target-'A';
    printf("%c, %c : 최단거리 = %d, 최단경로 수 = %d\n", start, target, vList[targetIdx].distance, vList[targetIdx].equalPathNum);
}
void freeMemory(){  //메모리 해제 함수
    for(int i=0; i<VERTEX_NUM; i++){
        INode *cur = vList[i].iList;
        while(cur){
            INode *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}