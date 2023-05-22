#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *left, *right;
}Node;

typedef struct __tree{
    struct __node *root;
}Tree;

Node *getNode(int data){
    if(data == 0)
        return NULL;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
Node *findNode(Node *node, int data){
    if(node == NULL)
        return NULL;
    if(node->data == data)
        return node;
    Node *ptr = findNode(node->left, data);
    if(ptr)
        return ptr;
    return findNode(node->right, data);
}
void setNode(Node *node, int data2, int data3){
    node->left = getNode(data2);
    node->right = getNode(data3);
}
void freeNode(Node *node){
    if(node){
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int main()
{
    Tree t;
    int i, N, data1, data2, data3;
    scanf("%d", &N);
    scanf("%d %d %d", &data1, &data2, &data3);
    t.root = getNode(data1);
    setNode(findNode(t.root, data1), data2, data3);

    for(i=1; i<N; i++){
        scanf("%d %d %d", &data1, &data2, &data3);
        setNode(findNode(t.root, data1), data2, data3);
    }

    char search[101];
    int M;
    scanf("%d", &M);
    getchar();
    for(i=0; i<M; i++){
        scanf("%s", search);
        int j=0;
        Node *ptr = t.root;

        while(search[j]){
            printf(" %d", ptr->data);
            if(search[j] == 'L')
                ptr = ptr->left;
            else
                ptr = ptr->right;
            
            j++;
        }
        printf(" %d\n", ptr->data);
    }

    freeNode(t.root);



    return 0;
}
