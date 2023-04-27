#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __stack{
    int top;
    char *stackArr;
}Stack;

void init(Stack *pstack);
void convert(Stack *pstack, char str[], char answer[]);
void push(Stack *pstack, char operand);
char pop(Stack *pstack);
char top(Stack *pstack);
int isEmpty(Stack *pstack);
void printStack(Stack *pstack);
int isOperator(char c);
int priorityOperator(char a, char b);
int getPriority(char c);

int main()
{
    Stack stack;
    char str[101];
    char answer[101];

    scanf("%s", str);

    init(&stack);                           // stack 구조체 초기화
    convert(&stack, str, answer);           // 후위수식 변환
    printf("%s\n", answer);                 // output
    free(stack.stackArr);                   // 메모리 해제

    return 0;
}
void init(Stack *pstack){
    pstack->top = -1;
    pstack->stackArr = (char *)malloc(101);
}
void convert(Stack *pstack, char str[], char answer[]){
    int i = 0, j = 0;

    while(str[i]){
        if(str[i] == '(')
            push(pstack, str[i]);
        else if(str[i] == ')'){
            while(top(pstack) != '(')
                answer[j++] = pop(pstack);
            pop(pstack);
        }
        else if(isOperator(str[i])){
            while(!isEmpty(pstack) && priorityOperator(str[i], top(pstack))){
                answer[j++] = pop(pstack);
            }
            push(pstack, str[i]);
        }
        else
            answer[j++] = str[i];
        
        i++;
    }

    while(!isEmpty(pstack))
        answer[j++] = pop(pstack);
    answer[j] = '\0';
}
void push(Stack *pstack, char operand){
    pstack->stackArr[++pstack->top] = operand;
}
char pop(Stack *pstack){
    return pstack->stackArr[pstack->top--];
}
char top(Stack *pstack){
    return pstack->stackArr[pstack->top];
}
int isEmpty(Stack *pstack){
    if(pstack->top < 0)
        return 1;
    else    
        return 0;
}
void printStack(Stack *pstack){
    int tmp = pstack->top;

    // printf("*** current STACK ***\n");
    while(tmp > -1){
        printf("%c", pstack->stackArr[tmp--]);
    }
    printf("\n\n");
}
int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    else
        return 0;
}
int priorityOperator(char a, char b){
    int aP = getPriority(a);
    int bP = getPriority(b);

    if(aP <= bP)
        return 1;
    else
        return 0;
}
int getPriority(char c){
    if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return 0;
}