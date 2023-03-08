#include "solution.h"

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