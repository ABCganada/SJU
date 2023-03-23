#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    char data;
    struct __node *prev;
    struct __node *next;
}Node;

typedef struct __list{
    struct __node *header;
}List;

void add(List *plist, int r, char data);
void delete(List *plist, int r);
void get(List *plist, int r);
void print(List *plist);
void freeNode(List *plist);

int main()
{
    List list;
    Node header, trailer;   // 이중연결리스트 초기화 O(1)
    header.prev = NULL;
    trailer.data = 0;
    trailer.next = NULL;
    header.next = &trailer;
    trailer.prev = &header;

    list.header = &header;

    int attempt, i, r;
    char cmd, data;

    scanf("%d", &attempt);
    getchar();

    for(i=0; i<attempt; i++){
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
        else if(cmd == 'P'){
            print(&list);
        }
    }
    freeNode(&list);

    return 0;
}
void add(List *plist, int r, char data){
    Node *newNode = NULL;
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    Node *tmpNode = plist->header;
    int i, flag = 0;
    for(i=1; i<r; i++){
        tmpNode = tmpNode->next;

        if(tmpNode->data == 0){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("invalid position\n");
        return;
    }
    newNode->prev = tmpNode;
    newNode->next = tmpNode->next;
    tmpNode->next->prev = newNode;
    tmpNode->next = newNode;
}
void delete(List *plist, int r){
    Node *delNode = plist->header;
    int i, flag = 0;
    for(i=0; i<r; i++){
        delNode = delNode->next;

        if(delNode->data == 0){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("invalid position\n");
        return;
    }
    delNode->prev->next = delNode->next;
    delNode->next->prev = delNode->prev;
    free(delNode);
}
void get(List *plist, int r){
    Node *getNode = plist->header;
    int i, flag = 0;
    for(i=0; i<r; i++){
        getNode = getNode->next;

        if(getNode->data == 0){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("invalid position\n");
        return;
    }
    printf("%c\n", getNode->data);
}
void print(List *plist){
    Node *tmpNode = plist->header->next;
    while(tmpNode->next != NULL){   // 순회 O(N)
        printf("%c", tmpNode->data);
        tmpNode = tmpNode->next;
    }
    printf("\n");
}
void freeNode(List *plist){
    Node *freeNode = plist->header->next;
    while(1){
        if(freeNode->data == 0)
            break;
        freeNode = freeNode->next;
        free(freeNode->prev);
    }
}