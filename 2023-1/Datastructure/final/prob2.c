#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
9 5 3 9 3 8 15 8 0 2 2 0 0 15 0 0 9 7 10 7 12 0 12 0 0 10 0 0
*/

typedef struct __tree {
	struct __node *root;
}Tree;

typedef struct __node {
	int data;
	struct __node *left, *right;
}Node;

Node *getNode(int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}
Node *setNode() {
	Node *node;
	int data1, data2, data3;
	scanf("%d %d %d", &data1, &data2, &data3);
	node = getNode(data1);
	if (data2) {
		node->left = setNode();
	}
	if (data3) {
		node->right = setNode();
	}
	return node;
}
void postOrder(Node *node) {
	if (node) {
		postOrder(node->left);
		postOrder(node->right);
		printf(" %d", node->data);
	}
}
void printM2(Node *node, int cnt) {
	if (node) {

		if (node->right) {	//오른쪽 노드 있다면
			cnt++;	//들어가기 전
			printM2(node->right, cnt);
			cnt--;	//들어온 후
		}

		for (int i = 0; i < cnt; i++)
			printf("*");
		printf("%d\n", node->data);

		if (node->left) {	//왼쪽 노드 있다면
			cnt++;	//들어가기 전
			printM2(node->left, cnt);
			cnt--;	//들어온 후
		}
	}
}

void freeNode(Node *node) {
	if (node) {
		freeNode(node->left);
		freeNode(node->right);
		free(node);
	}
}


int main()
{
	Tree t;
	int data1, data2, data3;
	int N;
	scanf("%d", &N);
	t.root = setNode();	//트리 구축 

	int M;
	scanf("%d", &M);

	postOrder(t.root);
	printf("\n");

	if (M == 2) {
		// 반시계 회전 트리 
		printM2(t.root, 0);
	}

	freeNode(t.root);	//메모리 해제


	return 0;
}
/*
9
5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
*/