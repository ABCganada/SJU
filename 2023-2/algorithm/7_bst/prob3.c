#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data, h;
    struct __node *parent, *left, *right;
}Node;

typedef struct __tree{
    struct __node *root;
}Tree;

Tree tree;

void init();
void printAVLTree(Node *node);
int isExternal(Node *node);

Node *searchTree(int data);
void insert(int data);
void expandExternal(Node *node);
void searchAndFixAfterInsert(Node *node);
Node *restruct(Node *x, Node *y, Node *z);

int removeNode(int data);
Node *reduceExternal(Node *exNode);
void searchAndFixAfterRemove(Node *node);

Node *inOrderSucc(Node *node);
Node *getSibling(Node *node);
int updateHeight(Node *node);
int isBalanced(Node *node);
void freeTree(Node *node);

int main()
{
    init();
    
    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'q'){
            break;
        } else if(cmd == 'i'){
            scanf("%d", &data);
            getchar();

            insert(data);
        } else if(cmd == 's'){
            scanf("%d", &data);
            getchar();

            // Node *searchNode = searchTree(data);
            // if(searchNode->h > 0){
            //     printf("%d\n", searchNode->data);
            // } else{
            //     printf("X\n");
            // }
            if(isExternal(searchTree(data))){
                printf("X\n");
            } else{
                printf("%d\n", data);
            }
        } else if(cmd == 'd'){
            scanf("%d", &data);
            getchar();

            int flag = removeNode(data);
            if(flag){
                printf("%d\n", data);
            } else{
                printf("X\n");
            }

        } else{
            printAVLTree(tree.root);
            printf("\n");
        }
    }

    freeTree(tree.root);

    return 0;
}
void init(){
    Node *node = (Node *)malloc(sizeof(Node));
    node->h = 0;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    tree.root = node;
}
void printAVLTree(Node *node){
    if(!isExternal(node)){
        printf(" %d", node->data);
        printAVLTree(node->left);
        printAVLTree(node->right);
    }
}
int isExternal(Node *node){
    if(!node->left && !node->right){
        return 1;
    }
    return 0;
}
Node *searchTree(int data){
    Node *node = tree.root;

    while(!isExternal(node)){
        if(node->data == data){
            return node;
        } else if(node->data > data){
            node = node->left;
        } else{
            node = node->right;
        }
    }
    return node;
}
void insert(int data){
    Node *node = searchTree(data);

    if(!isExternal(node)){
        return;
    }

    node->data = data;
    expandExternal(node);
    searchAndFixAfterInsert(node);
}
void expandExternal(Node *node){
    node->h = 1;

    node->left = (Node *)malloc(sizeof(Node));
    node->left->h = 0;
    node->left->parent = node;
    node->left->left = NULL;
    node->left->right = NULL;

    node->right = (Node *)malloc(sizeof(Node));
    node->right->h = 0;
    node->right->parent = node;
    node->right->left = NULL;
    node->right->right = NULL;
}
void searchAndFixAfterInsert(Node *node){
    if(node->parent == NULL){
        return;
    }

    Node *x, *y;
    Node *z = node->parent;

    while(updateHeight(z) && isBalanced(z)){
        if(z->parent == NULL){
            return;
        }
        z = z->parent;
    }

    if(isBalanced(z)){
        return;
    }

    //불균형 발견
    if(z->left->h > z->right->h){
        y = z->left;    
    } else{
        y = z->right;
    }

    if(y->left->h > y->right->h){
        x = y->left;
    } else{
        x = y->right;
    }

    restruct(x, y, z);
}
Node *restruct(Node *x, Node *y, Node *z){
    Node *a, *b, *c;
    Node *t0, *t1, *t2, *t3;

    if(z->data < y->data && y->data < x->data){             //z < y < x
        a = z, b = y, c = x;
        t0 = a->left, t1 = b->left, t2 = c->left, t3 = c->right;
    } else if(x->data < y->data && y->data < z->data){      //x < y < z
        a = x, b = y, c = z;
        t0 = a->left, t1 = a->right, t2 = b->right, t3 = c->right;
    } else if(y->data < x->data && x->data < z->data){      //y < x < z
        a = y, b = x, c = z;
        t0 = a->left, t1 = b->left, t2 = b->right, t3 = c->right;
    } else{                                                 //z < x < y
        a = z, b = x, c = y;
        t0 = a->left, t1 = b->left, t2 = b->right, t3 = c->right;
    }

    if(z->parent == NULL){
        tree.root = b;
        b->parent = NULL;
    } else if(z->parent->left == z){
        z->parent->left = b;
        b->parent = z->parent;
    } else{
        z->parent->right = b;
        b->parent = z->parent;
    }

    a->left = t0, t0->parent = a;
    a->right = t1, t1->parent = a;
    updateHeight(a);

    c->left = t2, t2->parent = c;
    c->right = t3, t3->parent = c;
    updateHeight(c);

    b->left = a, a->parent = b;
    b->right = c, c->parent = b;
    updateHeight(b);

    return b;
}
int removeNode(int data){
    Node *rmNode = searchTree(data);

    if(isExternal(rmNode)){
        return 0;
    }

    Node *zs;
    Node *z = rmNode->left;
    if(!isExternal(z)){
        z = rmNode->right;
    }

    if(isExternal(z)){
        zs = reduceExternal(z);
    } else{
        Node *succ = inOrderSucc(rmNode);
        z = succ->left;
        rmNode->data = succ->data;
        zs = reduceExternal(z);
    }
    searchAndFixAfterRemove(zs->parent);
    return 1;
}
Node *reduceExternal(Node *node){
    Node *parent = node->parent;
    Node *sibling = getSibling(node);

    if(!parent->parent){
        tree.root = sibling;
        sibling->parent = NULL;
    } else{
        Node *grandParent = parent->parent;
        if(grandParent->left == parent){
            grandParent->left = sibling;
            sibling->parent = grandParent;
        } else{
            grandParent->right = sibling;
            sibling->parent = grandParent;
        }
    }

    free(parent);
    free(node);
    return sibling;
}
void searchAndFixAfterRemove(Node *node){
    while(updateHeight(node) && isBalanced(node)){
        if(!node->parent){
            return;
        }
        node = node->parent;
    }
    if(isBalanced(node)){
        return;
    }

    Node *x, *y;
    Node *z = node;
    if(z->left->h > z->right->h){
        y = z->left;
    } else{
        y = z->right;
    }
    if(y->left->h > y->right->h){
        x = y->left;
    } else if(y->left->h < y->right->h){
        x = y->right;
    } else{
        if(z->left == y){
            x = y->left;
        } else{
            x = y->right;
        }
    }

    Node *b = restruct(x, y, z);
    if(!b->parent){
        return;
    }
    searchAndFixAfterRemove(b->parent);
}
Node *inOrderSucc(Node *node){
    node = node->right;

    if(isExternal(node)){
        return NULL;
    }

    while(!isExternal(node)){
        node = node->left;
    }
    return node->parent;
}
Node *getSibling(Node *node){
    if(node == node->parent->left){
        return node->parent->right;
    }
    return node->parent->left;
}
int updateHeight(Node *node){
    int h = node->left->h;
    if(h < node->right->h){
        h = node->right->h;
    }
    h++;

    if(node->h != h){
        node->h = h;
        return 1;
    }
    return 0;

}
int isBalanced(Node *node){
    if(node->left->h - node->right->h < -1 || node->left->h - node->right->h > 1){
        return 0;
    }
    return 1;
}
void freeTree(Node *node){
    if(node){
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}