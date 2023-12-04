#include <stdio.h>
#include <stdio.h>

/*
* 방향 가중 그래프
* 음의 가중치 허용, 싸이클 없음
* Bellman-Ford algorithm
*/

#define INIT_D_VALUE 30000

typedef struct __vnode{
    int vNum, distance;
}VNode;

typedef struct __enode{
    int startIdx, destIdx, w;
}ENode;

int n, m;
VNode vList[100];
ENode eList[1000];
int eListLastIdx = 0;


void initVertexList();
void insertEdge(int start, int dest, int w);
void BellmanFordShortestPath(int s);

int main()
{
    int s, start, dest, w;
    scanf("%d%d%d", &n, &m, &s);

    initVertexList();

    for(int i=0; i<m; i++){
        scanf("%d%d%d", &start, &dest, &w);
        insertEdge(start, dest, w);
    }

    BellmanFordShortestPath(s);

    for(int i=0; i<n; i++){
        if(i != s-1 && vList[i].distance != INIT_D_VALUE){
            printf("%d %d\n", vList[i].vNum, vList[i].distance);
        }
    }

    return 0;
}
void initVertexList(){
    for(int i=0; i<n; i++){
        vList[i].vNum = i+1;
        vList[i].distance = INIT_D_VALUE;
    }
}
void insertEdge(int start, int dest, int w){
    eList[eListLastIdx].startIdx = start-1;
    eList[eListLastIdx].destIdx = dest-1;
    eList[eListLastIdx++].w = w;
}
void BellmanFordShortestPath(int s){
    vList[s-1].distance = 0;

    for(int i=1; i<=n-1; i++){
        for(int j=0; j<eListLastIdx; j++){
            VNode *u = &vList[eList[j].startIdx];
            VNode *z = &vList[eList[j].destIdx];

            if(u->distance == INIT_D_VALUE && z->distance == INIT_D_VALUE){
                continue;
            }
            z->distance = u->distance + eList[j].w < z->distance ? u->distance + eList[j].w : z->distance;
        }
    }
}