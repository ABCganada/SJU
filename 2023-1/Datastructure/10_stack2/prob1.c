#include <stdio.h>
#include <string.h>

typedef struct __stack{
    int top;
    char stackArr[101][3];
}Stack;

void init(Stack *pstack);
void convert(char infix[], char postfix[]);
void push(Stack *pstack, char operand[]);
char *pop(Stack *pstack);
char *top(Stack *pstack);
int isEmpty(Stack *pstack);
int getPriority(char c[]);

int main()
{
    char infix[101];
    char postfix[101];
    int i, calNum;

    scanf("%d", &calNum);
    for(i=0; i<calNum; i++){
        scanf("%s", infix);
        convert(infix, postfix);
        printf("%s\n", postfix);
    }
    return 0;
}
void init(Stack *pstack){
    pstack->top = -1;
}
void convert(char infix[], char postfix[]){
    Stack stack;
    init(&stack);

    char tmp[101][3];
    int i = 0, j = 0;

    while(infix[i]){
        if(infix[i] == '+' || infix[i] == '-'){
            if(i==0)
                infix[i] = (infix[i] == '+') ? 'p' : 'm';
            else if(infix[i-1] != ')' && !(infix[i-1] >= 'A' && infix[i-1] <= 'Z')){
                infix[i] = (infix[i] == '+') ? 'p' : 'm';
            }
        }

        char c[3];
        if(!strncmp(&infix[i], "&&", 2) || !strncmp(&infix[i], "||", 2)){
            c[0] = infix[i++];
            c[1] = infix[i];
            c[2] = '\0';
        }
        else{
            c[0] = infix[i];
            c[1] = '\0';
        }

        if(c[0] >= 'A' && c[0] <= 'Z')      // operand
            strcpy(tmp[j++], c);
        else if(!strcmp(c, "("))            // 괄호 (
            push(&stack, c);
        else if(!strcmp(c, ")")){           // 괄호 )
            while(strcmp(top(&stack), "("))
                strcpy(tmp[j++], pop(&stack));
            pop(&stack);
        }
        else{                               // operator
            while(!isEmpty(&stack) && getPriority(c) <= getPriority(top(&stack))){
                strcpy(tmp[j++], pop(&stack));
            }
            push(&stack, c);
        }
        i++;
    }
    while(!isEmpty(&stack))
        strcpy(tmp[j++], pop(&stack));

    strcpy(postfix, tmp[0]);
    for(i=1; i<j; i++){
        if(!strcmp(tmp[i], "p"))    strcpy(tmp[i], "+");
        else if(!strcmp(tmp[i], "m"))   strcpy(tmp[i], "-");
        strcat(postfix, tmp[i]);
    }
}
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
    if(!strcmp(c, "!") || !strcmp(c, "p") || !strcmp(c, "m"))
        return 6;
    else if(!strcmp(c, "*") || !strcmp(c, "/"))
        return 5;
    else if(!strcmp(c, "+") || !strcmp(c, "-"))
        return 4;
    else if(!strcmp(c, "<") || !strcmp(c, ">"))
        return 3;
    else if(!strcmp(c, "&&"))
        return 2;
    else if(!strcmp(c, "||"))
        return 1;
    else
        return 0;
}