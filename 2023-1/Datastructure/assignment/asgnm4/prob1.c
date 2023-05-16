#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct __stack{         //stack 구조체
    int top;
    char stackArr[201][3];      //stack을 문자열 형태로. 두 자릿수 피연산자를 위해.
    int stackForOp[200];
}Stack;

void init(Stack *pstack);
void convert(char infix[], char postfix[]);
int operate(char postfix[]);
void push(Stack *pstack, char operand[]);
char *pop(Stack *pstack);
char *top(Stack *pstack);
int isEmpty(Stack *pstack);
int getPriority(char c[]);

void push2(Stack *pstack, int num);
int pop2(Stack *pstack);
int doOp(int secondPop, int firstPop, char operate);

int main()
{
    char infix[201], *postfix = NULL;   //중위 표기식, 후위 표기식
    int i, N;

    scanf("%d", &N);
    getchar();
    for(i=0; i<N; i++){
        scanf("%s", infix);                                 //중위표기식 입력
        postfix = (char *)malloc(strlen(infix)*2 +1);       //후위표기식 메모리 할당
        convert(infix, postfix);    //변환

        int ret = operate(postfix); //연산
        printf("%d\n", ret);        //연산 결과 출력

        free(postfix);              //메모리 해제
    }
    return 0;
}
void init(Stack *pstack){   //스택 초기화 함수
    pstack->top = -1;
}
void convert(char infix[], char postfix[]){     // 후위표기식 변환 함수
    Stack stack;
    init(&stack);

    char tmp[201][3];   //후위표기식 변환하기 전 저장할 임시 버퍼
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
        else{                                               //연산자. +, -, *, /, ^
            while(!isEmpty(&stack) && getPriority(c) <= getPriority(top(&stack))){
                if(getPriority(c) == 3){   //stack의 top이 ^라면 ^가 들어오더라도 stack에 넣어야함
                    break;
                }
                else
                    strcpy(tmp[j++], pop(&stack));
            }
            push(&stack, c);
        }
        i++;
    }
    while(!isEmpty(&stack))
        strcpy(tmp[j++], pop(&stack));

    strcpy(postfix, tmp[0]);        //첫 문자열 strcpy
    for(i=1; i<j; i++){
        strcat(postfix, " ");       //두 자릿수 피연산자 구분 위해 공백 삽입
        strcat(postfix, tmp[i]);    //두 번째부터 strcat
    }
}
int operate(char postfix[]){            //후위표기식 계산 함수
    Stack stack;
    init(&stack);

    char c[3];
    int i;
    for(i=0; i<strlen(postfix); i += 2){    // 연산자, 피연산자 사이 공백으로 인해 인덱스 2칸씩 점프
        if(postfix[i] >= '0' && postfix[i] <= '9'){             //피연산자일 경우 c정의
            if(postfix[i+1] >= '0' && postfix[i+1] <= '9'){
                c[0] = postfix[i++];
                c[1] = postfix[i];
                c[2] = '\0';
            }
            else{                                      
                c[0] = postfix[i];
                c[1] = '\0';
            }

            int tmp = atoi(c);
            push2(&stack, tmp);
        }
        else{                               //연산자일 경우
            int firstPop = pop2(&stack);
            int secondPop = pop2(&stack);
            push2(&stack, doOp(secondPop, firstPop, postfix[i]));   //연산 결과를 푸시
        }
    }

    return pop2(&stack);    //while문 다 돌고 나서 스택에 남아 있는 마지막 값 리턴
}
void push(Stack *pstack, char operand[]){   //변환 스택 푸시 함수
    strcpy(pstack->stackArr[++pstack->top], operand);
}
char *pop(Stack *pstack){                   //변환 스택 팝 함수
    return pstack->stackArr[pstack->top--];
}
char *top(Stack *pstack){                   //변환 스택 top 확인 함수
    return pstack->stackArr[pstack->top];
}
int isEmpty(Stack *pstack){                 //스택 empty 확인 함수
    if(pstack->top < 0)
        return 1;
    else    
        return 0;
}
int getPriority(char c[]){                  //연산자 우선순위 함수
    if(!strcmp(c, "^"))
        return 3;
    else if(!strcmp(c, "*") || !strcmp(c, "/"))
        return 2;
    else if(!strcmp(c, "+") || !strcmp(c, "-"))
        return 1;
    
    return 0;
}
void push2(Stack *pstack, int num){         //연산 스택 푸시 함수
    pstack->stackForOp[++pstack->top] = num;
}
int pop2(Stack *pstack){                    //연산 스택 팝 함수
    return pstack->stackForOp[pstack->top--];
}
int doOp(int secondPop, int firstPop, char operate){    //연산 함수
    if(operate == '^')
        return (int)pow(secondPop, firstPop);
    else if(operate == '*')
        return secondPop*firstPop;
    else if(operate == '/')
        return secondPop/firstPop;
    else if(operate == '+')
        return secondPop+firstPop;
    else if(operate == '-')
        return secondPop-firstPop;

    return 0;
}