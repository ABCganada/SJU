#include <stdio.h>
#include <stdlib.h>

typedef struct __vnode{
    int data;
}VNode;

typedef struct __inode{

}INode;

typedef struct __enode{
    struct __vnode *start;
    struct __vnode *end;
    int data;
}ENode;

VNode *getVNode(int data);
void getENode();

void createVertexList();
void createEdgeList();

int main()
{
    VNode vList;
    ENode eList;

    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'q'){
            break;
        }

        if(cmd == 'a'){
            scanf("%d", &data);
            getchar();
        } else if(cmd == 'm'){

        }
    }

    return 0;
}
VNode *getVNode(int data){
    VNode *newNode = (VNode *)malloc(sizeof(VNode));
    newNode->data = data;
}