#include <stdio.h>
#include <stdlib.h>

typedef struct __node{  //노드 구조체
    char data;
    struct __node *left, *right;
}Node;
typedef struct __tree{  //트리의 루트 노드 저장 구조체
    struct __node *root;
}Tree;

Node *getNode(char data){       //노드 생성 함수
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
Node *makeInternalNode(){       //내부 노드 생성 함수
    char data, leftOrRight, inOrEx; //트리 정보 변수들
    scanf("%c", &data); //출력 프레임을 위한 data 입력
    getchar();
    scanf("%c %c %c", &data, &leftOrRight, &inOrEx);    //left 노드 정보 입력
    getchar();
    Node *node = getNode(data); //노드 생성
    
    //left 노드
    if(inOrEx == 'i')   //내부 노드라면
        node->left = makeInternalNode();    //재귀 호출
    else{    //외부 노드라면
        scanf("%c", &data);
        getchar();
        node->left = getNode(data);
    }
    
    scanf("%c %c %c", &data, &leftOrRight, &inOrEx);    //right 노드 정보 입력
    getchar();

    //right 노드 
    if(inOrEx == 'i')   //내부 노드라면
        node->right = makeInternalNode();   //재귀 호출
    else{    //외부 노드라면
        scanf("%c", &data);
        getchar();
        node->right = getNode(data);
    }

    return node;
}
char yesOrNo(Node *node){       //트리 탐색
    char str[31];
    scanf("%s", str);   //문자열 입력

    int i=0;
    while(str[i]){
        if(str[i] == 'Y')   //Yes면 left
            node = node->left;
        else                //No면 right
            node = node->right;
        i++;
    }
    return node->data;  //노드의 data값 반환
}
void freeNode(Node *node){      //트리 메모리 해제
    if(node){   //후위 순회로 메모리 해제
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int main()
{
    Tree t;
    int N, M;
    scanf("%d", &N);    //노드의 개수
    getchar();

    t.root = makeInternalNode();    //트리 만들기

    scanf("%d", &M);    //결정 횟수
    getchar();
    for(int i=0; i<M; i++){
        printf("%c\n", yesOrNo(t.root));
    }
    freeNode(t.root);   //메모리 해제

    return 0;
}