#include <stdio.h>
#include <stdlib.h>

typedef struct __vnode{
    int n, visit;
}VNode;

typedef struct __enode{
    int v1, v2, visit;
}ENode;

typedef struct __queue{
    int arr[100];
    int head, rear;
}Q;

VNode vList[100];
ENode eList[1000];
int matrix[100][100];
Q q;
int n, m, s;

void initVertexList();
void initMatrix();

void initQueue();
void enqueue(int vIdx);
int dequeue();
int isEmpty();

int getOppositeVertexIdx(int eIdx, int vIdx);

void insertEdge(int n1, int n2, int i);
void bfs(int k);

int main()
{
    scanf("%d%d%d", &n, &m, &s);

    initVertexList();
    initMatrix();
    initQueue();

    int n1, n2;
    for(int i=0; i<m; i++){
        scanf("%d%d", &n1, &n2);
        insertEdge(n1, n2, i);
    }

    bfs(s);

    return 0;
}
void initVertexList(){
    for(int i=0; i<n; i++){
        vList[i].n = i+1;
        vList[i].visit = 0;
    }
}
void initMatrix(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = -1;
        }
    }
}
void initQueue(){
    q.head = 0;
    q.rear = 0;
}
void enqueue(int vIdx){
    q.arr[q.rear] = vIdx;
    q.rear = (q.rear+1)%100;
}
int dequeue(){
    int ret = q.arr[q.head];
    q.head = (q.head+1)%100;
    return ret;
}
int isEmpty(){
    if(q.head == q.rear){
        return 1;
    }
    return 0;
}
void insertEdge(int n1, int n2, int i){
    eList[i].v1 = n1-1;
    eList[i].v2 = n2-1;
    eList[i].visit = 0;

    matrix[n1-1][n2-1] = i;
    matrix[n2-1][n1-1] = i;
}
void bfs(int k){
    enqueue(k-1);
    vList[k-1].visit = 1;
    printf("%d\n", k);

    while(!isEmpty()){
        int vIdx = dequeue();
        for(int i=0; i<n; i++){
            if(matrix[vIdx][i] != -1){
                int oVIdx = getOppositeVertexIdx(matrix[vIdx][i], vIdx);
                if(vList[oVIdx].visit == 0){
                    eList[matrix[vIdx][i]].visit = 1;   //Tree
                    vList[oVIdx].visit = 1;
                    printf("%d\n", oVIdx+1);
                    enqueue(oVIdx);
                } else{
                    eList[matrix[vIdx][i]].visit = -1;  //Cross
                }
            }
        }
    }
}
int getOppositeVertexIdx(int eIdx, int vIdx){
    int ret = eList[eIdx].v1;
    if(ret == vIdx){
        ret = eList[eIdx].v2;
    }
    return ret;
}