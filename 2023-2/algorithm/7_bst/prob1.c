#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    int data;
    struct __node *left, *right, *parent;
}Node;

typedef struct __tree{
    struct __node *root;
}Tree;

Tree tree;

void init(Tree *ptree);                 //트리 초기화 함수
void insert(Tree *ptree, int k);        //k원소 노드 트리 삽입 함수
Node *searchTree(Tree *ptree, int k);   //k원소 노드 탐색 함수
int removeNode(Tree *ptree, int k);     //k원소 노드 삭제 함수
void expandExternal(Node *node);        //삽입 후 노드 확장 함수
Node *reduceExternal(Node *z);          //삭제 후 노드 축소 함수
int isExternal(Node *node);             //외부노드 확인 함수
Node *inOrderSucc(Node *node);          //중위순회후계자 찾는 함수
void printTree(Node *node);             //트리 전위순회 출력 함수
void freeTree(Node *node);              //트리 후위순회 메모리 해제 함수
Node *sibling(Node *node);              //node의 형제 찾는 함수

int main()
{
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

            if(!isExternal(searchTree(&tree, data))){
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
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    ptree->root = newNode;
}
void insert(Tree *ptree, int k){    //k원소 노드 트리 삽입 함수
    if(isExternal(ptree->root)){
        ptree->root->data = k;
        expandExternal(ptree->root);
        return;
    }

    Node *insertNode = searchTree(ptree, k);
    // Node *parentNode = getParent(ptree->root, k);
    if(isExternal(insertNode)){
        insertNode->data = k;
        expandExternal(insertNode);
    }
}
Node *searchTree(Tree *ptree, int k){   //k원소의 노드를 얻는 함수
    Node *ptrNode = ptree->root;

    while(!isExternal(ptrNode)){
        if(ptrNode->data == k){
            break;
        }

        if(ptrNode->data > k){
            ptrNode = ptrNode->left;
        } else{
            ptrNode = ptrNode->right;
        }
    }
    return ptrNode;
}
int removeNode(Tree *ptree, int k){
    Node *rmNode = searchTree(ptree, k);

    if(isExternal(rmNode)){
        printf("X\n");
        return -999;
    }

    int ret = rmNode->data;

    if(isExternal(rmNode->left) && isExternal(rmNode->right)){  //rmNode의 자식 모두 외부노드일 경우
        Node *rmChild = rmNode->left;
        reduceExternal(rmChild);
        return ret;
    }

    Node *child = rmNode->left;
    if(!isExternal(child)){
        child = rmNode->right;
    }

    if(isExternal(child)){      //rmNode의 child가 하나라도 외부노드일 경우
        reduceExternal(child);
    } else{
        Node *succ = inOrderSucc(rmNode);
        Node *succLeftChild = succ->left;
        rmNode->data = succ->data;
        reduceExternal(succLeftChild);
    }
    return ret;
}
void expandExternal(Node *node){
    node->left = (Node *)malloc(sizeof(Node));
    node->left->parent = node;
    node->left->left = NULL;
    node->left->right = NULL;

    node->right = (Node *)malloc(sizeof(Node));
    node->right->parent = node;
    node->right->left = NULL;
    node->right->right = NULL;
}
Node *reduceExternal(Node *exNode){
    Node *exParent = exNode->parent;
    Node *exSibliing = sibling(exNode);

    if(exParent->parent == NULL){   //exParent가 root인 경우
        exSibliing->parent = NULL;
        tree.root = exSibliing;
    } else{
        Node *exGrandParent = exParent->parent;
        exSibliing->parent = exGrandParent;
        if(exParent == exGrandParent->left){
            exGrandParent->left = exSibliing;
        } else{
            exGrandParent->right = exSibliing;
        }
    }

    free(exNode);
    free(exParent);
    return exSibliing;
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
    if(!isExternal(node)){
        printf(" %d", node->data);
        printTree(node->left);
        printTree(node->right);
    }
}
int isExternal(Node *node){ //외부노드 확인 함수
    if(!node->left && !node->right){
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