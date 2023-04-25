#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __stack{
    int top;
    char *stackArr;
}Stack;

void push(Stack *pstack, char operand);
char pop(Stack *pstack);
char top(Stack *pstack);
int isEmpty(Stack *pstack);

void printStack(Stack *pstack);

int main()
{
    Stack stack;
    char str[] = "a - b - c + (d + e * f) / g";
    int i = 0, j = 0;

    char answer[strlen(str)+1];

    stack.top = -1;
    stack.stackArr = (char *)malloc(strlen(str)+1);

    while(str[i]){
        if(str[i] == ' '){
            i++;
            continue;
        }

        if(str[i] == '+' || str[i] == '-'){                 // operator
            if(isEmpty(&stack) || top(&stack) == '(')
                push(&stack, str[i]);
            else{
                while(1){
                    answer[j++] = pop(&stack);
                    if(isEmpty(&stack) || top(&stack) == '(')
                        break;

                }
                push(&stack, str[i]);
            }
        }
        else if(str[i] == '*' || str[i] == '/'){
            if(top(&stack) == '+' || top(&stack) == '-' || top(&stack) == '('){
                push(&stack, str[i]);
            }
            else if(isEmpty(&stack))
                push(&stack, str[i]);
            else{
                answer[j++] = pop(&stack);
                push(&stack, str[i]);
            }
        }
        else{                                       
            if(str[i] == '('){
                push(&stack, str[i]);
            }
            else if(str[i] == ')'){
                while(top(&stack) != '('){
                    answer[j++] = pop(&stack);
                }
                pop(&stack);
            }
            else{                                           // operand
                answer[j++] = str[i];
            }
        }

        //DEBUG
        // printf("=== current ===\n");
        // printf("%s\n", answer);
        // printStack(&stack);
        i++;
    }
    while(!isEmpty(&stack)){
        answer[j++] = pop(&stack);
    }

    answer[j] = 0;
    printf("%s\n", answer);

    free(stack.stackArr);

    return 0;
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