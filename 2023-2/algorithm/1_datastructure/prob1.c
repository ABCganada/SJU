#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    char data;
    struct __node *prev, *next;
}Node;

typedef struct __list{
    struct __node *header, *trailer;
}List;

void init(List *plist);
Node *getNode(char data);
void add(List *plist, int r, char data);
void delete(List *plist, int r);
void get(List *plist, int r);
void print(List *plist);
void freeList(List *plist);

int main()
{
    List list;
    int n, r;
    char cmd, data;

    init(&list);

    scanf("%d", &n);
    getchar();
    
    for(int i=0; i<n; i++){
        scanf("%c", &cmd);
        getchar();

        if(cmd == 'A'){
            scanf("%d", &r);
            getchar();
            scanf("%c", &data);
            getchar();

            add(&list, r, data);
        } 
        else if(cmd == 'D'){
            scanf("%d", &r);
            getchar();

            delete(&list, r);
        } 
        else if(cmd == 'G'){
            scanf("%d", &r);
            getchar();

            get(&list, r);
        } 
        else{
            print(&list);
        }
    }

    freeList(&list);

    return 0;
}
void init(List *plist){
    plist->header = (Node *)malloc(sizeof(Node));
    plist->trailer = (Node *)malloc(sizeof(Node));

    plist->header->prev = NULL;
    plist->trailer->next = NULL;

    plist->header->next = plist->trailer;
    plist->trailer->prev = plist->header;
}
Node *getNode(char data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}
void print(List *plist){
    Node *ptrNode = plist->header->next;

    while(ptrNode->next){
        printf("%c", ptrNode->data);
        ptrNode = ptrNode->next;
    }

}
void add(List *plist, int r, char data){
    Node *ptrNode = plist->header;

    for(int i=0; i<r; i++){
        ptrNode = ptrNode->next;

        if(!ptrNode)
            break;
    }
    
    if(!ptrNode){
        printf("invalid position\n");
        return;
    }

    Node *newNode = getNode(data);
    newNode->prev = ptrNode->prev;
    newNode->next = ptrNode;
    ptrNode->prev->next = newNode;
    ptrNode->prev = newNode;
}
void delete(List *plist, int r){
    Node *ptrNode = plist->header;

    for(int i=0; i<r; i++){
        ptrNode = ptrNode->next;

        if(!ptrNode){
            break;
        }
    }
    
    if(!ptrNode || !ptrNode->next){
        printf("invalid position\n");
        return;
    }

    ptrNode->prev->next = ptrNode->next;
    ptrNode->next->prev = ptrNode->prev;

    free(ptrNode);
}
void get(List *plist, int r){
    Node *ptrNode = plist->header;

    for(int i=0; i<r; i++){
        ptrNode = ptrNode->next;

        if(!ptrNode)
            break;
    }

    if(!ptrNode || !ptrNode->next){
        printf("invalid position\n");
        return;
    }

    printf("%c\n", ptrNode->data);
}
void freeList(List *plist){
    Node *cur = plist->header->next;

    while(cur != NULL){
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}