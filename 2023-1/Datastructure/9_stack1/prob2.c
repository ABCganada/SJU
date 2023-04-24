/*
DS - stack
괄호 검사
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __stack{
    int top, cntParenthesis;
    char stackArr[1001];
}Stack;

void init(Stack *pstack);
int isRight(Stack *pstack, char *str);
void push(Stack *pstack, char parenthesis);
void pop(Stack *pstack, char parenthesis);

int main()
{
    Stack stack;
    char str[1001];
    int i = 0;

    gets(str);
    init(&stack);
    
    if(isRight(&stack, str))
        printf("OK_%d\n", stack.cntParenthesis);
    else
        printf("Wrong_%d\n", stack.cntParenthesis);

    return 0;
}
void init(Stack *pstack){
    pstack->top = -1;
    pstack->cntParenthesis = 0;
}
int isRight(Stack *pstack, char *str){
    int i = 0;

    while(str[i]){
        if(str[i] == '{' || str[i] == '[' || str[i] == '('){
            pstack->cntParenthesis++;
            push(pstack, str[i]);
        }
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')'){
            pstack->cntParenthesis++;
            if(pstack->top < 0)
                return 0;
            pop(pstack, str[i]);
        }
        i++;
    }

    if(pstack->top == -1) 
        return 1;
    else 
        return 0;
}
void push(Stack *pstack, char parenthesis){
    pstack->top++;
    pstack->stackArr[pstack->top] = parenthesis;
}
void pop(Stack *pstack, char parenthesis){
    if(parenthesis == '}'){
        if(pstack->stackArr[pstack->top] == '{')
            pstack->top--;
    }
    else if(parenthesis == ']'){
        if(pstack->stackArr[pstack->top] == '[')
            pstack->top--;
    }
    else{
        if(pstack->stackArr[pstack->top] == '(')
            pstack->top--;
    }
}