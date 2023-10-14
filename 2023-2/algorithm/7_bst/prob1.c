#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *left, *right, *parent;
}Node;

typedef struct __tree{
    struct __node *root;
}Tree;

void init(Tree *ptree);                 //트리 초기화 함수
Node *createNode(int k);                //k원소 노드 생성 함수
void insert(Tree *ptree, int k);        //k원소 노드 트리 삽입 함수
Node *searchTree(Tree *ptree, int k);      //k원소 노드를 얻는 함수
Node *getParent(Node *node, int k);     //k원소 혹은 k원소가 들어갈 자리에 대한 부모 노드를 얻는 함수
int removeNode(Tree *ptree, int k);
void expandExternal(Node *node);
Node *reduceExternal(Node *z);
int isExternal(Node *node);             //외부노드 확인 함수
Node *inOrderSucc(Node *node);
void printTree(Node *node);             //트리 전위순회 출력 함수
void freeTree(Node *node);
Node *sibling(Node *node);

int main()
{
    Tree tree;
    init(&tree);
    char cmd;
    int data;

    while(1){
        scanf("%c", &cmd);

        if(cmd == 'q'){
            break;
        } else if(cmd == 'i'){
            scanf("%d", &data);
            getchar();

            insert(&tree, data);
        } else if(cmd == 'p'){
            printTree(tree.root);
            printf("\n");
        } else if(cmd == 's'){
            scanf("%d", &data);
            getchar();

            if(searchTree(&tree, data)){
                printf("%d\n", data);
            } else{
                printf("X\n");
            }
        } else if(cmd == 'd'){
            scanf("%d", &data);
            getchar();

            int tmp = removeNode(&tree, data);
            if(tmp != -999){
                printf("%d\n", data);
            }
        }
    }

    freeTree(tree.root);

    return 0;
}
void init(Tree *ptree){ //트리 초기화 함수
    ptree->root = NULL;
}
Node *createNode(int k){    //k원소 노드 생성 함수
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = k;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    return newNode;
}
void insert(Tree *ptree, int k){    //k원소 노드 트리 삽입 함수
    if(isExternal(ptree->root)){
        ptree->root = createNode(k);
        expandExternal(ptree->root);
        return;
    }

    Node *newNode = searchTree(ptree, k);
    Node *parentNode = getParent(ptree->root, k);
    if(!newNode->left && !newNode->right){
        newNode = createNode(k);
        newNode->parent = parentNode;
        if(parentNode->data > newNode->data){
            parentNode->left = newNode;
        } else{
            parentNode->right = newNode;
        }
    }
}
Node *searchTree(Tree *ptree, int k){   //k원소의 노드를 얻는 함수
    Node *ptrNode = ptree->root;

    while(ptrNode && ptrNode->data != k){
        if(ptrNode->data > k){
            ptrNode = ptrNode->left;
        } else{
            ptrNode = ptrNode->right;
        }
    }
    return ptrNode;
}
Node *getParent(Node *node, int k){ //k원소 혹은 k원소가 들어갈 자리의 부모 노드를 얻는 함수
    Node *cur = node;
    Node *before = node;

    while(cur && cur->data != k){
        before = cur;
        if(cur->data > k){
            cur = cur->left;
        } else{
            cur = cur->right;
        }
    }
    return before;
}
int removeNode(Tree *ptree, int k){
    Node *rmNode = searchTree(ptree, k);

    if(isExternal(rmNode)){
        printf("X\n");
        return -999;
    }

    int ret = rmNode->data;

    Node *child = rmNode->left;
    if(!isExternal(child)){
        child = rmNode->right;
    }

    if(isExternal(child)){      //rmNode의 child가 하나라도 외부노드일 경우
        printf("**\n");
        reduceExternal(child);
        printf("* *\n");
    } else{
        Node *succ = inOrderSucc(rmNode);
        Node *succChild = succ->left;
        rmNode->data = succ->data;
        printf("***\n");
        reduceExternal(succChild);
        printf("* * *\n");
    }
    return ret;
}
void expandExternal(Node *node){
    node->left = (Node *)malloc(sizeof(Node));
    node->right = (Node *)malloc(sizeof(Node));
}
Node *reduceExternal(Node *z){
    Node *w = z->parent;
    Node *zs = sibling(z);

    if(w->parent == NULL){
        w = zs;
        zs->parent = NULL;
    } else{
        printf("^^\n");
        Node *g = w->parent;
        zs->parent = g;
        if(w == g->left){
            g->left = zs;
        } else{
            g->right = zs;
        }
    }

    free(z);
    free(w);
    return zs;
}
Node *inOrderSucc(Node *node){
    node = node->right;
    if(isExternal(node)){
        return NULL;
    }
    while(!isExternal(node->left)){
        node = node->left;
    }
    return node;
}
void printTree(Node *node){ //트리 전위순회 출력함수
    if(node){
        printf(" %d", node->data);
        printTree(node->left);
        printTree(node->right);
    }
}
int isExternal(Node *node){ //외부노드 확인 함수
    if(!node){
        return 1;
    }

    return 0;
}
Node *sibling(Node *node){
    if(node->parent->left == node){
        return node->parent->right;
    }

    return node->parent->left;
}
void freeTree(Node *node){
    if(node){
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}