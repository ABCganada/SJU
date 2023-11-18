#include <stdio.h>
#include <stdlib.h>

/*
* DAG, 위상 순서 인쇄
* not DAG, 0 인쇄
* 
* 인접리스트 구조
* 배열 구현
* 정점의 진입차수 이용한 위상 정렬 알고리즘
* 
* 간선노드 삽입시, 리스트 맨 앞에 삽입
* 최초로 진입간선 개수 0인 정점을 찾을 때, 정점번호 순서대로 조사
*/

typedef struct __vnode{
    char name;
    int visit;
    int degree;
    struct __inode *inList;
    struct __inode *outList;
}VNode;

typedef struct __enode{
    int vIdx1, vIdx2;
    int visit;
}ENode;

typedef struct __inode{
    int eIdx;
    struct __inode *next;
}INode;

typedef struct __graph{
    struct __vnode vList[100];
    struct __enode eList[1000];
}Graph;

typedef struct __queue{
    int arr[100];
    int head, rear;
}Queue;

int n, m, degree[100], topOrder[101];
Graph g;
Queue q;

void buildGraph();
void insertVertex(char vName, int i);
void insertDirectedEdge(char uName, char wName, int i);
void addFirst(INode *header, int i);
void topologicalSort();

void initQueue();
void enqueue(int vIdx);
int dequeue();
int isEmpty();

INode *getINode(int eIdx);
int findVIdx(char vName);
void freeMemory();

int main()
{
    buildGraph();

    topologicalSort();

    if(topOrder[0] == 0){
        printf("0\n");
    } else{
        for(int i=1; i<=n; i++){
            printf("%c ", g.vList[topOrder[i]].name);
        }
        printf("\n");
    }

    freeMemory();

    return 0;
}
void buildGraph(){
    char data1, data2;
    scanf("%d", &n);
    getchar();

    for(int i=0; i<n; i++){
        scanf("%c", &data1);
        getchar();

        g.vList[i].name = data1;
        insertVertex(data1, i);
    }

    scanf("%d", &m);
    getchar();

    for(int i=0; i<m; i++){
        scanf("%c %c", &data1, &data2);
        getchar();

        insertDirectedEdge(data1, data2, i);
    }
}
void insertVertex(char vName, int i){
    g.vList[i].name = vName;
    g.vList[i].degree = 0;
    g.vList[i].visit = 0;
    
    g.vList[i].inList = (INode *)malloc(sizeof(INode));
    g.vList[i].inList->next = NULL;

    g.vList[i].outList = (INode *)malloc(sizeof(INode));
    g.vList[i].outList->next = NULL;
}
void insertDirectedEdge(char uName, char wName, int i){
    int u = findVIdx(uName);
    int w = findVIdx(wName);

    g.eList[u].vIdx1 = u;
    g.eList[i].vIdx2 = w;
    g.eList[i].visit = 0;
    g.vList[findVIdx(wName)].degree++;

    addFirst(g.vList[u].outList, i);
    addFirst(g.vList[w].inList, i);
}
void addFirst(INode *header, int i){
    INode *newNode = getINode(i);

    if(header->next){
        newNode->next = header->next;
    }
    header->next = newNode;
}
void topologicalSort(){
    initQueue();

    for(int i=0; i<n; i++){
        degree[i] = g.vList[i].degree;
        if(degree[i] == 0){
            enqueue(i);
        }
    }

    int t = 1;

    while(!isEmpty()){
        int u = dequeue();
        topOrder[t++] = u;

        INode *ptr = g.vList[u].outList->next;
        while(ptr){
            int w = g.eList[ptr->eIdx].vIdx2;
            degree[w]--;
            if(degree[w] == 0){
                enqueue(w);
            }
            ptr = ptr->next;
        }
    }

    if(t <= n){
        topOrder[0] = 0;
    } else{
        topOrder[0] = 1;
    }
}
void initQueue(){
    q.head = 0;
    q.rear = 0;
}
void enqueue(int vIdx){
    q.arr[q.rear] = vIdx;
    q.rear = (q.rear + 1) % 100;
}
int dequeue(){
    int delIdx = q.arr[q.head];
    q.head = (q.head + 1) % 100;

    return delIdx;
}
int isEmpty(){
    if(q.head == q.rear){
        return 1;
    }

    return 0;
}
INode *getINode(int eIdx){
    INode *newNode = (INode *)malloc(sizeof(INode));
    newNode->eIdx = eIdx;
    newNode->next = NULL;

    return newNode;
}
int findVIdx(char vName){
    int i;
    for(i=0; i<n; i++){
        if(g.vList[i].name == vName){
            break;
        }
    }

    return i;
}
void freeMemory(){
    for(int i=0; i<n; i++){
        INode *cur = g.vList[i].inList;
        while(cur){
            INode *next = cur->next;
            free(cur);
            cur = next;
        }

        cur = g.vList[i].outList;
        while(cur){
            INode *next = cur->next;
            free(cur);
            cur = next;
        }
    }
}