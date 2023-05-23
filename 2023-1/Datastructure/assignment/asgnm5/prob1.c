#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    char data;
    struct __node *left, *right;
}Node;
typedef struct __tree{
    struct __node *root;
}Tree;

Node *getNode(char data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
Node *makeExternalNode(){
    char data;
    scanf("%c", &data);
    getchar();
    Node *node = getNode(data);

    return node;
}
Node *makeInternalNode(){
    char data, leftOrRight, inOrEx;

    scanf("%c", &data);
    getchar();
    scanf("%c %c %c", &data, &leftOrRight, &inOrEx);
    getchar();
    Node *node = getNode(data);
    node->data = data;
    
    if(inOrEx == 'i')
        node->left = makeInternalNode();
    else
        node->left = makeExternalNode();
    
    scanf("%c %c %c", &data, &leftOrRight, &inOrEx);
    getchar();
    if(inOrEx == 'i')
        node->right = makeInternalNode();
    else
        node->right = makeExternalNode();

    return node;
}
void preOrder(Node *node){
    if(node){
        printf(" %c", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
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
    
    int N;
    scanf("%d", &N);
    getchar();

    t.root = makeInternalNode();
    // preOrder(t.root);
    // printf("\n****\n");
    char tmp[31];
    int i, M;
    scanf("%d", &M);
    getchar();
    for(i=0; i<M; i++){
        Node *ptr = t.root;
        scanf("%s", tmp);
        int j=0;
        while(tmp[j]){
            if(tmp[j] == 'Y')
                ptr = ptr->left;
            else
                ptr = ptr->right;
            j++;
        }
        printf("%c\n", ptr->data);
    }

    freeNode(t.root);   //메모리 해제


    return 0;
}