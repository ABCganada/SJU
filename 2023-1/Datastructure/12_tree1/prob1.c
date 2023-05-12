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
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
Node *linkNode(Node *left, Node *right, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}
int isInternal(Node *node){
    if(node->left != NULL || node->right != NULL)
        return 1;
    else
        return 0;
}
void freeNode(Node *node){
    if(isInternal(node)){
        if(node->left)
            freeNode(node->left);
        if(node->right)
            freeNode(node->right);
    }
    free(node);
}

int main()
{
    Node *f7 = getNode(130);
    Node *f8 = getNode(80);
    Node *f6 = linkNode(f7, f8, 120);
    Node *f3 = linkNode(NULL, f6, 50);

    Node *f4 = getNode(70);
    Node *f5 = getNode(90);
    Node *f2 = linkNode(f4, f5, 30);

    Node *f1 = linkNode(f2, f3, 20);
    
    Tree tree;
    tree.root = f1;

    int N;
    scanf("%d", &N);

    if(N > 8)
        printf("-1\n");
    else{
        Node *ptr[8] = {f1,f2,f3,f4,f5,f6,f7,f8};
        Node *res = ptr[N-1];

        printf("%d", res->data);
        if(res->left)
            printf(" %d", res->left->data);
        if(res->right)
            printf(" %d", res->right->data);
        printf("\n");
    }

    freeNode(f1);

    return 0;
}