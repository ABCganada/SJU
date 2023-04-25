#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __stack{
    int top;
    char *stackArr;
}Stack;

void init(Stack *pstack, char str[]);
void convert(Stack *pstack, char str[], char answer[]);
void push(Stack *pstack, char operand);
char pop(Stack *pstack);
char top(Stack *pstack);
int isEmpty(Stack *pstack);
void printStack(Stack *pstack);

int main()
{
    Stack stack;
    char str[] = "a - b - c + (d + e * f) / g";
    char answer[strlen(str) + 1];
    int i = 0, j = 0;

    init(&stack, str);                      // stack 구조체 초기화
    convert(&stack, str, answer);           // 후위수식 변환
    printf("%s\n", answer);                 // output
    free(stack.stackArr);                   // 메모리 해제

    return 0;
}
void init(Stack *pstack, char str[]){
    pstack->top = -1;
    pstack->stackArr = (char *)malloc(strlen(str)+1);
}
void convert(Stack *pstack, char str[], char answer[]){
    int i = 0, j = 0;

    while(str[i]){
        if(str[i] == ' '){
            i++;
            continue;
        }

        if(str[i] == '+' || str[i] == '-'){                 // operator
            if(isEmpty(pstack) || top(pstack) == '(')
                push(pstack, str[i]);
            else{
                while(1){
                    answer[j++] = pop(pstack);
                    if(isEmpty(pstack) || top(pstack) == '(')
                        break;

                }
                push(pstack, str[i]);
            }
        }
        else if(str[i] == '*' || str[i] == '/'){
            if(top(pstack) == '+' || top(pstack) == '-' || top(pstack) == '('){
                push(pstack, str[i]);
            }
            else if(isEmpty(pstack))
                push(pstack, str[i]);
            else{
                answer[j++] = pop(pstack);
                push(pstack, str[i]);
            }
        }
        else{                                       
            if(str[i] == '('){
                push(pstack, str[i]);
            }
            else if(str[i] == ')'){
                while(top(pstack) != '('){
                    answer[j++] = pop(pstack);
                }
                pop(pstack);
            }
            else{                                           // operand
                answer[j++] = str[i];
            }
        }

        // DEBUG
        // printf("=== current ===\n");
        // printf("%s\n", answer);
        // printStack(pstack);
        i++;
    }
    while(!isEmpty(pstack)){
        answer[j++] = pop(pstack);
    }

    answer[j] = '\0';;

    //DEBUG
    // printf("=== complete ===\n");
    // printf("%s\n\n\n",answer);
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