#include <stdio.h>
#include <stdlib.h>

#define VERTEX_SIZE 6

typedef struct __vnode{
    int n;
}VNode;

VNode *vList;
int matrix[VERTEX_SIZE][VERTEX_SIZE];

void initVertexList();
void initMatrix();

void printAdjacent(int n);
void modifyEdgeWeight(int n1, int n2, int w);
void insertEdge(int n1, int n2, int w);

int isPresent(int n);

int main()
{
    initVertexList();
    initMatrix();

    char cmd;
    
    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'q'){
            break;
        }

        if(cmd == 'a'){
            int n;
            scanf("%d", &n);
            getchar();

            printAdjacent(n);
        } else if(cmd == 'm'){
            int n1, n2, w;
            scanf("%d %d %d", &n1, &n2, &w);
            getchar();

            modifyEdgeWeight(n1, n2, w);
        }
    }

    free(vList);

    return 0;
}
void initVertexList(){
    vList = (VNode *)malloc(sizeof(VNode) * VERTEX_SIZE);
    for(int i=0; i<VERTEX_SIZE; i++){
        vList[i].n = i+1;
    }
}
void initMatrix(){
    for(int i=0; i<VERTEX_SIZE; i++){     //행렬 초기화
        for(int j=0; j<VERTEX_SIZE; j++){
            matrix[i][j] = 0;
        }
    }
    insertEdge(1, 2, 1);
    insertEdge(1, 3, 1);
    insertEdge(1, 4, 1);
    insertEdge(1, 6, 2);
    insertEdge(2, 3, 1);
    insertEdge(3, 5, 4);
    insertEdge(5, 5, 4);
    insertEdge(5, 6, 3);
}
void printAdjacent(int n){
    if(!isPresent(n)){
        printf("-1\n");
        return;
    }

    for(int i=0; i<VERTEX_SIZE; i++){
        if(matrix[n-1][i] != 0){
            printf(" %d %d", i+1, matrix[n-1][i]);
        }
    }
    printf("\n");
}
void modifyEdgeWeight(int n1, int n2, int w){
    if(!isPresent(n1) || !isPresent(n2)){
        printf("-1\n");
        return;
    }

    if(n1 == n2){
        matrix[n1-1][n1-1] = w;
        return;
    }

    matrix[n1-1][n2-1] = w;
    matrix[n2-1][n1-1] = w;
}
void insertEdge(int n1, int n2, int w){
    if(n1 == n2){
        matrix[n1-1][n2-1] = w;
        return;
    }

    matrix[n1-1][n2-1] = w;
    matrix[n2-1][n1-1] = w;
}
int isPresent(int n){
    for(int i=0; i<VERTEX_SIZE; i++){
        if(vList[i].n == n){
            return 1;
        }
    }
    return 0;
}