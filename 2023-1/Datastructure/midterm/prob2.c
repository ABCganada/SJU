#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct __node {
	int data;
	struct __node *next;
}Node;

typedef struct __list {
	struct __node *header;
}List;

void append(Node *ptrNode, int data);
void moveFirst(List *plist, int pos);

int main() 
{
	List list;
	list.header = (Node *)malloc(sizeof(Node));
	list.header->next = NULL;

	int i, N, data;
	Node *ptrNode = list.header;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {			// 연결리스트. 초기 리스트 생성
		scanf("%d", &data);
		append(ptrNode, data);
		ptrNode = ptrNode->next;
	}

	int M, pos;							// 이동 연산
	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &pos);
		if(pos <= N)
			moveFirst(&list, pos);
	}

	ptrNode = list.header->next;		// 최종 출력
	while (ptrNode) {
		printf(" %d", ptrNode->data);
		ptrNode = ptrNode->next;
	}
	printf("\n");
	
	Node *current, *next;				// 메모리 해제
	current = list.header;
	next = current->next;
	while (1) {
		free(current);

		current = next;
		if (current == NULL)
			break;
		next = current->next;
		
	}



	return 0;
}
void append(Node *ptrNode, int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	ptrNode->next = newNode;
}
void moveFirst(List *plist, int pos) {
	Node *moveNode;
	Node *prevMoveNode = plist->header;
	int i;
	for (i = 0; i < pos-1; i++) {
		prevMoveNode = prevMoveNode->next;
	}
	moveNode = prevMoveNode->next;
	// printf("*** %d ***\n", moveNode->data);
	prevMoveNode->next = moveNode->next;
	moveNode->next = plist->header->next;
	plist->header->next = moveNode;

}

