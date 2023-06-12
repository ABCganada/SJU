#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __deque {
	int size;
	int front, rear;
	int *arr;
}Deque;

int addFront(Deque *dq, int data);
int addRear(Deque *dq, int data);
int delFront(Deque *dq);
int delRear(Deque *dq);
void printDq(Deque *dq);


int main() {
	Deque dq;
	int m, flag;
	scanf("%d %d", &dq.size, &m);
	getchar();

	dq.arr = (int *)malloc(sizeof(int) * dq.size);
	dq.front = dq.rear = 0;

	for (int i = 0; i < m; i++) {
		char cmd[3];
		scanf("%s", cmd);

		if (!strcmp(cmd, "AF")) {
			int data;
			scanf("%d", &data);
			getchar();

			addFront(&dq, data);
		}
		else if (!strcmp(cmd, "AR")) {
			int data;
			scanf("%d", &data);
			getchar();

			addRear(&dq, data);
		}
		else if (!strcmp(cmd, "DF")) {
			delFront(&dq);
		}
		else if (!strcmp(cmd, "DR")) {
			delRear(&dq);
		}
		else if (!strcmp(cmd, "P")) {
			printDq(&dq);
		}
	}

	free(dq.arr);	//메모리 해제 



	return 0;
}
int addFront(Deque *dq, int data) {
	if ((dq->rear + 1) % dq->size == dq->front)	//overflow
		return 0;

	dq->front--;
	if (dq->front == -1) {
		dq->front = dq->size - 1;
	}
	dq->arr[dq->front] = data;
}
int addRear(Deque *dq, int data) {
	if ((dq->rear + 1) % dq->size == dq->front)	//overflow
		return 0;

	dq->arr[dq->rear++] = data;
	if (dq->rear == dq->size) {
		dq->rear = 0;
	}
}
int delFront(Deque *dq) {
	if (dq->front == dq->rear)	//underflow
		return 0;

	dq->front++;
	if (dq->front == dq->size)
		dq->front = 0;
}
int delRear(Deque *dq) {
	if (dq->front == dq->rear)	//underflow
		return 0;

	dq->rear--;
	if (dq->rear == -1)
		dq->rear = dq->size - 1;
}
void printDq(Deque *dq) {
	int i = dq->front;
	while (1) {
		if (i == dq->rear)
			break;

		printf(" %d", dq->arr[i]);
		i++;

		if (i == dq->size) {
			i = 0;
		}
	}
	printf("\n");
}