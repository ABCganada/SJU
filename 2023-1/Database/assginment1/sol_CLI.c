#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100    // 파일 이름 길이
#define MAX_CONTENT_LEN 1000    // 파일 내용 길이

int Cmd();      // 프로그램 메뉴
void Load(char *fileName);  // 파일 로드
void Print(char *fileName); // 파일 출력
void Update(char* fileName, char* target, char* replace);   // 파일의 키워드 수정
void Delete(char* fileName, char* keword);  // 파일의 키워드 삭제
void Find(char* fileName, char* keyword);    // 파일의 키워드 찾기
int Save(char *fileName, char *newFileName);    // 파일 새로 저장
int fileIsValid(FILE *fp);  //유효성 검사

int main() 
{
    char fileName[MAX_FILENAME_LEN];
    int cmd;

    while(1){   // 무한 루프
        cmd = Cmd();    // 프로그램 메뉴 호출
        getchar();

        if(cmd == 1){   // 파일 로드 호출
            printf("\n@@@@ File Load @@@@\n");
            printf("--> Load File Name : ");
            scanf("%s", fileName);

            Load(fileName);
        }
        else if(cmd == 2){  // 파일 출력 호출
            printf("\n@@@@ File Print @@@@\n");
            Print(fileName);
        }
        else if(cmd == 3){  // 파일 키워드 수정 호출
            printf("\n@@@@ File Update @@@@\n");
            char before[MAX_CONTENT_LEN], after[MAX_CONTENT_LEN];

            printf("--> Before : ");
            scanf("%s", before);
            printf("--> After : ");
            scanf("%s", after);

            Update(fileName, before, after);
        }
        else if(cmd == 4){  // 파일 키워드 삭제 호출
            printf("\n@@@@ File Delete @@@@\n");
            char delKeyword[MAX_CONTENT_LEN];

            printf("--> Delete Keyword : ");
            scanf("%s", delKeyword);

            Delete(fileName, delKeyword);
        }
        else if(cmd == 5){  // 파일 키워드 찾기 호출
            printf("\n@@@@ File Find @@@@\n");
            char keyword[MAX_CONTENT_LEN];

            printf("--> Find Keyword : ");
            scanf("%s", keyword);

            Find(fileName, keyword);
        }
        else if(cmd == 6){  // 파일 새로 저장 호출
            printf("\n@@@@ File Save @@@@\n");
            char newFileName[MAX_CONTENT_LEN];

            printf("--> New File Name : ");
            scanf("%s", newFileName);
            
            int result;
            result = Save(fileName, newFileName);
            if(result){
                printf("~ Success : Save File \"%s\"\n", newFileName);
            }
        }
        else if(cmd == 7){  // 프로그램 종료
            printf("~ Exit Program\n");
            break;
        }
        else{
            printf("~ COMMAND ERROR\n");
        }
    }

    return 0;
}
int Cmd(){  // 프로그램 메뉴
    int command;

    printf("\n**** Program Menu ****\n");
    printf("1. File Load\n");
    printf("2. File Print\n");
    printf("3. File Update\n");
    printf("4. File Delete\n");
    printf("5. File Find\n");
    printf("6. File Save\n");
    printf("7. Exit Program\n");
    printf("--> PUT COMMAND : ");
    scanf("%d", &command);

    return command;
}
void Load(char* fileName){ //파일 로드
    FILE *fp = NULL;

    fp = fopen(fileName, "r");
    if(!fileIsValid(fp)){
        return;
    }

    printf("~ Success : Load File \"%s\"\n", fileName);
    fclose(fp);
}
void Print(char* fileName){    // 파일 출력
    FILE *fp = NULL;
    char buffer[MAX_CONTENT_LEN];

    fp = fopen(fileName, "r");
    if(!fileIsValid(fp)){
        return;
    }

    while(fgets(buffer, MAX_CONTENT_LEN, fp) != NULL){
        printf("%s", buffer);
    }
    fclose(fp);
}
void Update(char* fileName, char* target, char* replace){   // 파일 키워드 수정
    FILE *fp = NULL;
    char buffer[MAX_CONTENT_LEN];
    char newBuffer[MAX_CONTENT_LEN] = {0};   // strncat으로 붙일 거임.

    fp = fopen(fileName, "r");  // read mode로 먼저 열어봄
    if(!fileIsValid(fp)){
        return;
    }
    
    while (fgets(buffer, MAX_CONTENT_LEN, fp) != NULL) {    // 한 줄씩 읽어가면서
        char *ptr = buffer;
        char *index;
        // strstr : char *strstr(char *str1, const char *str2)
        while((index = strstr(ptr, target)) != NULL){
            // while문에 들어왔다는 의미 : index = strstr(ptr, target) 이 널포인터가 아니다.
            // 일치하는 문자열을 찾았다. 
            strncat(newBuffer, ptr, index - ptr);   // 앞 부분 index-ptr 만큼 붙여줌
            strncat(newBuffer, replace, strlen(replace));   // replace 붙여줌
            ptr = index + strlen(target);   // 같은 라인에 중복을 다시 찾기 위해 index에 target만큼 이동
        }
        // 중복이 없음
        strcat(newBuffer, ptr); // 뒷 부분 붙여줌.
    }
    fclose(fp);

    fp = fopen(fileName, "w");
    if(!fileIsValid(fp)){
        return;
    }

    fprintf(fp, "%s", newBuffer);
    printf("~ Success : File Update \"%s\"\n", fileName);
    fclose(fp);
}
void Delete(char* fileName, char* keyword){ // 파일 키워드 삭제
    FILE *fp = NULL;
    char buffer[MAX_CONTENT_LEN];
    char newBuffer[MAX_CONTENT_LEN] = {0};

    fp = fopen(fileName, "r");
    if(!fileIsValid(fp)){
        return;
    }

    while(fgets(buffer, MAX_CONTENT_LEN, fp) != NULL){
        char *ptr = buffer;
        char *index;
        while ((index = strstr(ptr, keyword)) != NULL) {    // 키워드 찾으면
            strncat(newBuffer, ptr, index - ptr);   // newBuffer에 앞 부분 붙여줌
            ptr = index + strlen(keyword);  // 삭제 키워드 중복 제거 위해 ptr 이동
        }
        strcat(newBuffer, ptr); // 뒷 부분 붙여줌
    }
    fclose(fp);

    fp = fopen(fileName, "w");
    if(!fileIsValid(fp)){
        return;
    }

    fprintf(fp, "%s", newBuffer);
    printf("~ Success : File Delete \"%s\"\n", fileName);
    fclose(fp);
}
void Find(char *fileName, char *keyword){   // 파일 키워드 찾기
    FILE *fp = NULL;
    char buffer[MAX_CONTENT_LEN];

    fp = fopen(fileName, "r");
    if(!fileIsValid(fp)){
        return;
    }

    while(fgets(buffer, MAX_CONTENT_LEN, fp) != NULL){
        if(strstr(buffer, keyword) != NULL){
            printf("~ Find Content : %s", buffer);
        }
    }
    fclose(fp);
}
int Save(char *fileName, char *newFileName){    // 파일 새로 저장
    FILE *fp = NULL, *newFp = NULL;
    char content[MAX_CONTENT_LEN];

    fp = fopen(fileName, "r");
    if(!fileIsValid(fp)){
        return 0;
    }

    newFp = fopen(newFileName, "w");
    if(!fileIsValid(newFp)){
        return 0;
    }

    while(fgets(content, MAX_CONTENT_LEN, fp) != NULL){
        fputs(content, newFp);
    }
    fclose(fp);
    fclose(newFp);
    return 1;
}
int fileIsValid(FILE *fp){  //유효성 검사
    if(fp == NULL){
        printf("~ Fail : Load File\n");
        return 0;
    }
    return 1;
}