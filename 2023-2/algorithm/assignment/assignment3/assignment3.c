#include <stdio.h>

#define MAX 23  //해시테이블 사이즈
#define PRIME_NUM 19    //해시테이블 사이즈보다 조금 작은 소수

typedef struct __bucket{
    int key, elem;
    int flag;       //flag -1: 쓰인 적이 없음. 0: 쓰였지만 삭제됐음. 1: 쓰이고 있음
}Bucket;

Bucket hashTable[MAX];

void initHashTable();               //해시테이블 초기화 함수

int hash1(int n);                   //해시코드맵
int hash2(int n);                   //압축맵

int findElem(int key);              //키값 통해 원소 찾는 함수
void insertData(int key, int elem); //키값, 원소 쌍 삽입 함수
int removeElem(int key);            //키값 통해 버킷 비활성화 삭제하는 함수
void printHashTable();              //해시테이블 출력 함수

void FullOfIndexException();        //인덱스 만원 예외
void DuplicateKeyException();       //중복 키 예외
void NoSuchKey();                   //탐색 실패 예외

int main()
{
    initHashTable();    //해시테이블 초기화

    char cmd;
    int key, elem;
    while(1){
        scanf("%c", &cmd);  //명령 입력
        getchar();

        if(cmd == 'q'){         //프로그램 종료
            break;
        }

        if(cmd == 'f'){         //탐색
            scanf("%d", &key);
            getchar();

            int e = findElem(key);  //리턴값이 0보다 크면 
            if(e >= 0){
                printf("find element: %d\n", e);
            } else{ //e가 -1이라면, 탐색 실패 오류
                NoSuchKey();
            }
        } else if(cmd == 'i'){  //삽입
            scanf("%d %d", &key, &elem);
            getchar();

            insertData(key, elem);
        } else if(cmd == 'r'){  //삭제
            scanf("%d", &key);
            getchar();

            int e = removeElem(key);
            if(e >= 0){
                printf("removed element: %d\n", e);
            } else{ //e가 -1라면, 탐색 실패 오류
                NoSuchKey();
            }
        } else if(cmd == 'p'){  //출력
            printHashTable();
        }
    }



    return 0;
}
void initHashTable(){
    for(int i=0; i<MAX; i++){
        hashTable[i].key = -1;  //버킷 키값 음수로 초기화
        hashTable[i].elem = -1; //버킷 원소 음수로 초기화
        hashTable[i].flag = -1; //버킷 비활성화로 초기화
    }
}
int hash1(int n){   //해시코드맵
    return n % MAX;
}
int hash2(int n){   //압축맵
    return PRIME_NUM - (n % PRIME_NUM);
}
int findElem(int key){  //키값 통해 원소찾는 함수
    int h = hash1(key); //해시코드맵 해싱
    int gap = hash2(key);   //압축맵 해싱
    int searchCnt = 0;  //탐색 횟수

    while(hashTable[h].flag != -1 && searchCnt < MAX){
        if(hashTable[h].key == key){
            return hashTable[h].elem;
        }

        h = (h + gap) % MAX;    //원형으로 돌아야 하기 때문에 h2를 더해주되 배열 사이즈의 나머지값을 취함
        searchCnt++;
    }

    if(searchCnt == MAX){   //while을 MAX만큼 돌았다는 것은 인덱스가 포화상태라는 것
        return -2;
    }

    return -1;          //while에서 리턴을 받지 못하고 비활성화 버킷을 만나 while을 탈출했다면 탐색 실패라는 것
}
void insertData(int key, int elem){ //키, 원소 쌍 삽입 함수
    int res = findElem(key);    //key값에 대한 탐색 진행
    if(res >= 0){   //key에 대한 탐색 결과가 0보다 크다면, key가 해시테이블에 존재함
        DuplicateKeyException();    //중복키 예외처리
        return;
    } else if(res == -2){   //key에 대한 탐색 결과가 -2라면, 인덱스가 포화상태라는 것
        FullOfIndexException(); //인덱스 만원 예외처리
        return;
    }

    int h = hash1(key);     //해시코드맵 해싱
    int gap = hash2(key);   //압축맵 해싱

    while(hashTable[h].flag != -1 && hashTable[h].flag != 0){   //초기화 상태 버킷이나 비활성화된 버킷을 만날 때까지 반복문 진행
        h = (h + gap) % MAX;
    }
    
    hashTable[h].key = key;     //반복문이 빠져나온 시점의 인덱스 h 버킷은 초기화 상태나 비활성화 상태임. 삽입 가능
    hashTable[h].elem = elem;
    hashTable[h].flag = 1;
}
int removeElem(int key){    //key값 통해 버킷 비활성화 삭제하는 함수
    int res = findElem(key);    //key값 통해 탐색 진행
    if(res == -1){  //탐색 결과가 -1이라면, key에 대한 버킷이 없다는 것
        return res;
    }

    int h = hash1(key);     //해시코드맵 해싱
    int gap = hash2(key);   //압축맵 해싱

    while(hashTable[h].flag != 1){  //활성화 버킷 만날 때까지 반복문 진행
        h = (h + gap) % MAX;
    }

    res = hashTable[h].elem;    //반복문 빠져나온 시점의 인덱스 h는 활성화 버킷. 
    hashTable[h].key = -1;
    hashTable[h].elem = -1;
    hashTable[h].flag = 0;  //flag는 1에서 0으로 표기. 비활성화

    return res;
}
void printHashTable(){  //해시테이블 출력 함수
    for(int i=0; i<MAX; i++){   //해시테이블 배열첨자 출력
        printf("%3d", i);
    }
    printf("\n");

    for(int i=0; i<MAX; i++){   //저장된 원소 출력
        if(hashTable[i].flag != 1){
            printf("  .");
        } else{
            printf("%3d", hashTable[i].elem);
        }
    }
    printf("\n");
}
void FullOfIndexException(){    //인덱스 만원 예외
    printf("삽입 실패: 인덱스 만원 예외\n");
}
void DuplicateKeyException(){   //중복키 예외
    printf("삽입 실패: 중복키 예외\n");
}
void NoSuchKey(){               //탐색 실패 예외
    printf("탐색 실패: 키가 존재하지 않음\n");
}