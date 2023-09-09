#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node{
    int data;
    struct __node *left, *right;
}Node;

typedef struct __tree{
    struct __node *root;
}Tree;

void init(Tree *ptree);
Node *getNode();
Node *makeInternalNode();
void searchTree(Tree *tree, char *str);

void preOrder(Node *node){

    if(node){
        printf(" %d", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}
void freeNode(Node *node);

int main()
{
    Tree tree;
    int n;

    init(&tree);
    scanf("%d", &n);

    tree.root = makeInternalNode();

    // preOrder(tree.root);

    char str[101];
    int m;
    scanf("%d", &m);
    getchar();

    for(int i=0; i<m; i++){
        scanf("%s", str);
        searchTree(&tree, str);
    }







    return 0;
}
void init(Tree *ptree){
    ptree->root = getNode();
}
Node *getNode(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
Node *makeInternalNode(){

    int data, left, right;
    scanf("%d %d %d", &data, &left, &right);

    Node *newNode = getNode();
    newNode->data = data;

    if(left){
        newNode->left = makeInternalNode();
    }

    if(right){
        newNode->right = makeInternalNode();
    }

    return newNode;
}
void searchTree(Tree *tree, char *str){
    Node *ptrNode = tree->root;
    int i = 0;

    while(str[i]){
        printf(" %d", ptrNode->data);
        
        if(str[i] == 'L'){
            ptrNode = ptrNode->left;
        } else{
            ptrNode = ptrNode->right;
        }
        i++;
    }
    printf(" %d\n", ptrNode->data);
}
void freeNode(Node *node){
    if(node){
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}