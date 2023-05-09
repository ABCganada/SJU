#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct __stack{
    int top;
    char stackArr[101][3];
}Stack;

void init(Stack *pstack);
void convert(char infix[], char postfix[]);
// int operate(char postfix[]);
void push(Stack *pstack, char operand[]);
char *pop(Stack *pstack);
char *top(Stack *pstack);
int isEmpty(Stack *pstack);
int getPriority(char c[]);

int main()
{
    char infix[201];
    char postfix[401];
    int i, calNum;

    scanf("%d", &calNum);
    getchar();
    for(i=0; i<calNum; i++){
        scanf("%s", infix);
        convert(infix, postfix);
        printf("%s\n", postfix);
        // printf("%d\n", operate(postfix));
    }
    return 0;
}
void init(Stack *pstack){
    pstack->top = -1;
}
void convert(char infix[], char postfix[]){
    Stack stack;
    init(&stack);

    char tmp[201][3];
    int i = 0, j = 0;

    while(infix[i]){
        char c[3];
        if(infix[i] >= '0' && infix[i] <='9'){              //피연산자일 경우
            c[0] = infix[i];
            if(infix[i+1] >= '0' && infix[i+1] <= '9'){ //피연산자가 두 자리일 경우
                c[1] = infix[++i];
                c[2] = '\0';
            }
            else{                                       //피연산자가 한 자리일 경우
                c[1] = '\0';
            }
        }
        else{                                               //연산자일 경우
            c[0] = infix[i];
            c[1] = '\0';
        }

        if(c[0] >= '0' && c[0] <= '9')                      //피연산자
            strcpy(tmp[j++], c);
        else if(!strcmp(c, "("))                            //괄호 (
            push(&stack, c);
        else if(!strcmp(c, ")")){                           //괄호 )
            while(strcmp(top(&stack), "("))
                strcpy(tmp[j++], pop(&stack));
            pop(&stack);
        }
        else{                               // operator
            while(!isEmpty(&stack) && getPriority(c) <= getPriority(top(&stack))){
                if(getPriority(top(&stack)) == 3)
                    break;
                else
                    strcpy(tmp[j++], pop(&stack));
            }
            push(&stack, c);
        }
        i++;
        for(int k=0; k<j; k++)
            printf(" %s",tmp[k]);
        printf("\n");
    }
    while(!isEmpty(&stack))
        strcpy(tmp[j++], pop(&stack));

    strcpy(postfix, tmp[0]);
    for(i=1; i<j; i++){
        strcat(postfix, " ");
        strcat(postfix, tmp[i]);
    }
}
// int operate(char postfix[]){
//     return 0;
// }
void push(Stack *pstack, char operand[]){
    strcpy(pstack->stackArr[++pstack->top], operand);
}
char *pop(Stack *pstack){
    return pstack->stackArr[pstack->top--];
}
char *top(Stack *pstack){
    return pstack->stackArr[pstack->top];
}
int isEmpty(Stack *pstack){
    if(pstack->top < 0)
        return 1;
    else    
        return 0;
}
int getPriority(char c[]){
    if(!strcmp(c, "^"))
        return 3;
    else if(!strcmp(c, "*") || !strcmp(c, "/"))
        return 2;
    else if(!strcmp(c, "+") || !strcmp(c, "-"))
        return 1;
    
    return 0;
}