#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data, h;
    struct __node *left, *right, *parent;
}Node;

typedef struct __tree{
    struct __node *root;
}Tree;

Tree tree;

void init();
Node *searchTree(int data);
void expandExternal(Node *node);
void insert(int data);
void searchAndFixAfterInsert(Node *w);

int updateHeight(Node *w);
int isBalanced(Node *w);
Node *restruct(Node *x, Node *y, Node *z);

void printPreOrder(Node *node);
int isExternal(Node *node);
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

            Node *node = searchTree(data);
            if(node){
                printf("%d\n", node->data);
            } else{
                printf("X\n");
            }
        } else if(cmd == 'p'){
            printPreOrder(tree.root);
            printf("\n");
        }
    }

    freeTree(tree.root);

    return 0;
}
void init(){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->h = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    tree.root = newNode;
}
Node *searchTree(int data){
    Node *node = tree.root;

    while(!isExternal(node) && node->data != data){
        if(node->data > data){
            node = node->left;
        } else{
            node = node->right;
        }
    }

    return node;
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
void insert(int data){
    Node *node = searchTree(data);

    if(!isExternal(node)){
        return;
    }

    node->data = data;
    expandExternal(node);
    searchAndFixAfterInsert(node);
}
void searchAndFixAfterInsert(Node *w){
    w->left->h = 0, w->right->h = 0, w->h = 1;

    if(w->parent == NULL){
        return;
    }

    Node *x, *y;
    Node *z = w->parent;

    while(updateHeight(z) && isBalanced(z)){
        if(z->parent == NULL){
            return;
        }
        z = z->parent;
    }

    if(isBalanced(z)){
        return;
    }

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
    if(z->data < y->data && y->data < x->data){
        a = z, b = y, c = x;
        t0 = a->left, t1 = b->left, t2 = c->left, t3 = c->right;
    } else if(x->data < y->data && y->data < z->data){
        a = x, b = y, c = z;
        t0 = a->left, t1 = a->right, t2 = b->right, t3 = c->right;
    } else if(z->data < x->data && x->data < y->data){
        a = z, b = x, c = y;
        t0 = a->left, t1 = b->left, t2 = b->right, t3 = c->right;
    } else{
        a = y, b = x, c = z;
        t0 = a->left, t1 = b->left, t2 = b->right, t3 = c->right;
    }
    if(!z->parent){
        tree.root = b;
        b->parent = NULL;
    } else if(z->parent->left == z){
        z->parent->left = b;
        b->parent = z->parent;
    } else{
        z->parent->right = b;
        b->parent = z->parent;
    }

    a->left = t0, a->right = t1;
    t0->parent = a, t1->parent = a;
    updateHeight(a);

    c->left = t2, c->right = t3;
    t2->parent = c, t3->parent = c;
    updateHeight(c);

    b->left = a, b->right = c;
    a->parent = b, c->parent = b;
    updateHeight(b);

    return b;
}
int updateHeight(Node *w){
    int h = w->left->h;
    if(h < w->right->h){
        h = w->right->h;
    }
    h++;

    if(h != w->h){
        w->h = h;
        return 1;
    }

    return 0;
}
int isBalanced(Node *w){
    Node *left = w->left;
    Node *right = w->right;

    if(left->h - right->h < -1 || left->h - right->h > 1){
        return 0;
    }

    return 1;
}
void printPreOrder(Node *node){
    if(!isExternal(node)){
        printf(" %d", node->data);
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
}
int isExternal(Node *node){
    if(!node->left && !node->right){
        return 1;
    }
    return 0;
}
void freeTree(Node *node){
    if(node){
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}