#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data, id;
    struct __node *left, *right;
}Node;
typedef struct __tree{
    struct __node *root;
}Tree;

Node *getNode(int data, int id){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
void setNode(Node *parent, Node *leftChild, Node *rightChild){
    parent->left = leftChild;
    parent->right = rightChild;
}
Node *search(Node *node, int id){
    if(node == NULL)
        return NULL;
    if(node->id == id)
        return node;
    
    Node *ret = search(node->left, id);
    if(ret != NULL)
        return ret;
    
    return search(node->right, id);
}
int sumNode(Node *node){
    if(node == NULL)
        return 0;
    
    int tmp = node->data;
    tmp += sumNode(node->left);
    tmp += sumNode(node->right);

    return tmp;
}
void preOrder(Node *node){
    if(node){
        printf(" %d", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}
void inOrder(Node *node){
    if(node){
        inOrder(node->left);
        printf(" %d", node->data);
        inOrder(node->right);
    }

}
void postOrder(Node *node){
    if(node){
        postOrder(node->left);
        postOrder(node->right);
        printf(" %d", node->data);
    }
}
void freeNode(Node *node){
    if(node == NULL)
        return;
    
    freeNode(node->left);
    freeNode(node->right);
    free(node);
}

int main()
{
    Tree t;
    t.root = getNode(20,1);
    setNode(t.root, getNode(30, 2), getNode(50, 3));
    setNode(t.root->left, getNode(70, 4), getNode(90, 5));
    setNode(t.root->right, NULL, getNode(120, 6));
    setNode(t.root->right->right, getNode(130, 7), getNode(80, 8));

    int searchId;
    scanf("%d", &searchId);
    Node *ptr = search(t.root, searchId);
    if(ptr == NULL){
        printf("-1\n");
    }
    else{
        printf("%d\n", sumNode(ptr));
    }

    freeNode(t.root);

    return 0;
}