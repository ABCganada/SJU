#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __stack{
    int top;
    int stack[101];
}Stack;

int evaluate(char postfix[]);
void init(Stack *pstack);
void push(Stack *pstack, char operand);
int pop(Stack *pstack);
int operate(int a, int b, char c);

int main()
{
    char postfix[101];
    int i, calNum;

    scanf("%d", &calNum);
    getchar();

    for(i=0; i<calNum; i++){
        scanf("%s", postfix);
        printf("%d\n", evaluate(postfix));
    }

    return 0;
}
int evaluate(char postfix[]){
    Stack stack;
    init(&stack);

    char c;
    int i = 0;

    while(postfix[i]){
        c = postfix[i];

        if(c=='+' || c=='-' || c=='*' || c=='/'){
            int a = pop(&stack);
            int b = pop(&stack);
            push(&stack, operate(b, a, c));
        }
        else{
            push(&stack, atoi(&c));
        }
        i++;
    }
    return pop(&stack);
}
void init(Stack *pstack){
    pstack->top = -1;
}
void push(Stack *pstack, char operand){
    pstack->stack[++pstack->top] = operand;
}
int pop(Stack *pstack){
    return pstack->stack[pstack->top--];
}
int operate(int a, int b, char c){
    switch(c){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
    return 0;
}