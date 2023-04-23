#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __stack{
    int size;
    int top;
    char *stackArr;
}Stack;

void push(Stack *pstack, char data);
char pop(Stack *pstack);
void peek(Stack *pstack);
void duplicate(Stack *pstack);
void upRotate(Stack *pstack, int n);
void downRotate(Stack *pstack, int n);
void print(Stack *pstack);

int main()
{
    Stack stack;
    char cmd[10];
    int i, N, calNum;
    scanf("%d", &N);

    stack.stackArr = (char *)malloc(sizeof(char) * N);  // 스택 초기화
    stack.top = -1;
    stack.size = N;

    scanf("%d", &calNum);
    getchar();

    for(i=0; i<calNum; i++){
        scanf("%s", cmd);
        getchar();
        if(!strcmp(cmd, "POP")){            // pop
            char ret = pop(&stack);
        }
        else if(!strcmp(cmd, "PUSH")){      // push
            char data;
            scanf("%c", &data);
            getchar();

            push(&stack, data);
        }
        else if(!strcmp(cmd, "PEEK")){      // peek
            peek(&stack);
        }
        else if(!strcmp(cmd, "DUP")){       // duplicate
            duplicate(&stack);
        }
        else if(!strcmp(cmd, "UpR")){       // upRotate
            int data;
            scanf("%d", &data);
            getchar();

            upRotate(&stack, data);
        }
        else if(!strcmp(cmd, "DownR")){     // downRotate
            int data;
            scanf("%d", &data);
            getchar();

            downRotate(&stack, data);
        }
        else if(!strcmp(cmd, "PRINT")){     // print
            print(&stack);
        }
    }

    free(stack.stackArr);



    return 0;
}
void push(Stack *pstack, char data){
    if(pstack->top == pstack->size -1){
        printf("Stack FULL\n");
        return;
    }
    
    pstack->top++;
    pstack->stackArr[pstack->top] = data;
}
char pop(Stack *pstack){
    if(pstack->top < 0){
        printf("Stack Empty\n");
        return 0;
    }

    pstack->top--;
    return pstack->stackArr[pstack->top+1];
}
void peek(Stack *pstack){
    if(pstack->top < 0){
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", pstack->stackArr[pstack->top]);
}
void duplicate(Stack *pstack){
    char dup = pop(pstack);
    if(!dup) return;

    for(int i=0; i<2; i++)
        push(pstack, dup);
}
void upRotate(Stack *pstack, int n){
    if(pstack->top+1 < n)
        return;
    
    char tmp = pop(pstack);
    pstack->top++;
    int i;

    for(i=pstack->top; i>=pstack->top-n+1; i--){
        pstack->stackArr[i] = pstack->stackArr[i-1];
    }
    pstack->stackArr[pstack->top-n+1] = tmp;
}
void downRotate(Stack *pstack, int n){
    if(pstack->top+1 < n)
        return;
    
    char tmp = pstack->stackArr[pstack->top-n+1];
    int i;

    for(i=pstack->top-n+1; i<= pstack->top-1; i++){
        pstack->stackArr[i] = pstack->stackArr[i+1];
    }

    pstack->top--;
    push(pstack, tmp);
}
void print(Stack *pstack){
    int n = pstack->top;
    if(n < 0)
        return;
    
    while(n >= 0){
        printf("%c", pstack->stackArr[n]);
        n--;
    }
    printf("\n");
}