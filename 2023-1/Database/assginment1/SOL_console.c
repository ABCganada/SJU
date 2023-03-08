#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100
#define MAX_CONTENT_LEN 1000

int Cmd();      // 프로그램 메뉴
void Load(char *fileName);  // 파일 로드
void Print(char *fileName); // 파일 출력
void Update(char* fileName, char* target, char* replace);   // 파일의 키워드 수정
void Delete(char* fileName, char* target);  // 파일의 키워드 삭제
void Find(char* fileName, char* target);    // 파일의 키워드 찾기
int Save(char *fileName, char *newFileName);    // 파일 새로 저장

int main() {
    FILE *fp=NULL;
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

            Save(fileName, newFileName);
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
void Load(char* fileName) { //파일 로드
    FILE *fp;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }
    printf("~ Success : Load File: \"%s\"\n", fileName);
    fclose(fp);
}
void Print(char* fileName) {    // 파일 출력
    FILE *fp;
    char content[MAX_CONTENT_LEN];

    fp = fopen(fileName, "r");
    if (fp == NULL) {   // 유효성 검사
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }

    while(fgets(content, MAX_CONTENT_LEN, fp) != NULL){
        printf("%s", content);
    }
    fclose(fp);
}
void Update(char* fileName, char* target, char* replace) {
    FILE *fp;
    char content[MAX_CONTENT_LEN];
    char newContent[MAX_CONTENT_LEN] = {'\0'};

    fp = fopen(fileName, "r");
    if (fp == NULL) {   // 유효성 검사
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }
    
    while (fgets(content, MAX_CONTENT_LEN, fp) != NULL) {
        char *ptr = content;
        char *index;
        int targetLen = strlen(target);
        int replaceLen = strlen(replace);
        while ((index = strstr(ptr, target)) != NULL) {
            strncat(newContent, ptr, index - ptr);
            strncat(newContent, replace, replaceLen);
            ptr = index + targetLen;
        }
        strcat(newContent, ptr);
    }

    fclose(fp);
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }
    fprintf(fp, "%s", newContent);
    printf("~ Success : File Update \"%s\"\n", fileName);
    fclose(fp);
}

void Delete(char* fileName, char* target) {
    FILE *fp;
    char content[MAX_CONTENT_LEN];
    char newContent[MAX_CONTENT_LEN] = {0};
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }
    while (fgets(content, MAX_CONTENT_LEN, fp) != NULL) {
        char *ptr = content;
        char *index;
        int targetLen = strlen(target);
        while ((index = strstr(ptr, target)) != NULL) {
            strncat(newContent, ptr, index - ptr);
            ptr = index + targetLen;
        }
        strcat(newContent, ptr);
    }
    fclose(fp);
    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }
    fprintf(fp, "%s", newContent);
    printf("~ Success : File Delete \"%s\"\n", fileName);
    fclose(fp);
}

void Find(char *fileName, char *keyword) {
    FILE *fp;
    char line[256];
    int line_num = 1;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("~ Fail : Load File \"%s\"\n", fileName);
        return;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, keyword) != NULL) {
            printf("Line %d: %s", line_num, line);
        }
        line_num++;
    }

    fclose(fp);
}
int Save(char *fileName, char *newFileName) {
    FILE *fp, *newFp;
    char content[MAX_CONTENT_LEN];
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("~ Fail : Load Existing File \"%s\"\n", fileName);
        return 0;
    }
    newFp = fopen(newFileName, "w");
    if (newFp == NULL) {
        printf("~ Fail : Load New File \"%s\"\n", newFileName);
        fclose(fp);
        return 0;
    }
    while (fgets(content, MAX_CONTENT_LEN, fp) != NULL) {
        fputs(content, newFp);
    }
    fclose(fp);
    fclose(newFp);
    return 1;
}