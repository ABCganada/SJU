#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_FILENAME_LEN 100
#define MAX_CONTENT_LEN 1000

int Cmd(); // 프로그램 메뉴
void Load(char* fileName); // 파일 로드
void Print(char* fileName); // 파일 출력
void Update(char* fileName, char* target, char* replace); // 파일의 키워드 수정
void Delete(char* fileName, char* target); // 파일의 키워드 삭제
void Find(const string& fileName, const string& keyword);
int Save(const string& fileName, const string& newFileName); // 파일 새로 저장

int main()
{
    char fileName[MAX_FILENAME_LEN];
    int cmd;

    while (1)
    { // 무한 루프
        cmd = Cmd(); // 프로그램 메뉴 호출
        cin.ignore();

        if (cmd == 1)
        { // 파일 로드 호출
            cout << "\n@@@@ File Load @@@@\n";
            cout << "--> Load File Name : ";
            cin >> fileName;

            Load(fileName);
        }
        else if (cmd == 2)
        { // 파일 출력 호출
            cout << "\n@@@@ File Print @@@@\n";
            Print(fileName);
        }
        else if (cmd == 3)
        { // 파일 키워드 수정 호출
            cout << "\n@@@@ File Update @@@@\n";
            char before[MAX_CONTENT_LEN], after[MAX_CONTENT_LEN];

            cout << "--> Before : ";
            cin >> before;
            cout << "--> After : ";
            cin >> after;

            Update(fileName, before, after);
        }
        else if (cmd == 4)
        { // 파일 키워드 삭제 호출
            cout << "\n@@@@ File Delete @@@@\n";
            char delKeyword[MAX_CONTENT_LEN];

            cout << "--> Delete Keyword : ";
            cin >> delKeyword;

            Delete(fileName, delKeyword);
        }
        else if (cmd == 5)
        { // 파일 키워드 찾기 호출
            cout << "\n@@@@ File Find @@@@\n";
            char keyword[MAX_CONTENT_LEN];

            cout << "--> Find Keyword : ";
            cin >> keyword;

            Find(fileName, keyword);
        }
        else if (cmd == 6)
        { // 파일 새로 저장 호출
            cout << "\n@@@@ File Save @@@@\n";
            char newFileName[MAX_CONTENT_LEN];

            cout << "--> New File Name : ";
            cin >> newFileName;

            Save(fileName, newFileName);
        }
        else if (cmd == 7)
        { // 프로그램 종료
            cout << "~ Exit Program\n";
            break;
        }
        else
        {
            cout << "~ COMMAND ERROR\n";
        }
    }

    return 0;
}
int Cmd() { // 프로그램 메뉴
    int command;

    cout << "\n**** Program Menu ****\n";
    cout << "1. File Load\n";
    cout << "2. File Print\n";
    cout << "3. File Update\n";
    cout << "4. File Delete\n";
    cout << "5. File Find\n";
    cout << "6. File Save\n";
    cout << "7. Exit Program\n";
    cout << "--> PUT COMMAND : ";
    cin >> command;

    return command;
}

void Load(char* fileName) { //파일 로드
    ifstream inFile(fileName);
    if (!inFile) { // 유효성 검사
        cout << "~ Fail : Load File \"" << fileName << "\"" << endl;
        return;
    }
    cout << "~ Success : Load File: \"" << fileName << "\"" << endl;
    inFile.close();
}

void Print(char* fileName) { // 파일 출력
    ifstream inFile(fileName);
    if (!inFile) { // 유효성 검사
        cout << "~ Fail : Load File \"" << fileName << "\"" << endl;
        return;
    }
    string content;
    while (getline(inFile, content)) {
        cout << content << endl;
    }
    inFile.close();
}

void Update(char* fileName, char* target, char* replace) {
    ifstream inFile(fileName);
    if (!inFile) { // 유효성 검사
        cout << "~ Fail : Load File \"" << fileName << "\"" << endl;
        return;
    }
    ofstream outFile(fileName);
    if (!outFile) { // 유효성 검사
        cout << "~ Fail : Load File \"" << fileName << "\"" << endl;
        inFile.close();
        return;
    }
    string content;
    while (getline(inFile, content)) {
        size_t pos = 0;
        while ((pos = content.find(target, pos)) != string::npos) {
            content.replace(pos, strlen(target), replace);
            pos += strlen(replace);
        }
        outFile << content << endl;
    }
    cout << "~ Success : File Update \"" << fileName << "\"" << endl;
    inFile.close();
    outFile.close();
}

void Delete(char* fileName, char* target) {
    ifstream inFile(fileName);
    if (!inFile) { // 유효성 검사
        cout << "~ Fail : Load File \"" << fileName << "\"" << endl;
        return;
    }
    ofstream outFile(fileName);
    if (!outFile) { // 유효성 검사
        cout << "~ Fail : Load File \"" << fileName << "\"" << endl;
        inFile.close();
        return;
    }
    string content;
    while (getline(inFile, content)) {
        size_t pos = 0;
        while ((pos = content.find(target, pos)) != string::npos) {
            content.erase(pos, strlen(target));
        }
        outFile << content << endl;
    }
    cout << "~ Success : File Delete \"" << fileName << "\"" << endl;
    inFile.close();
    outFile.close();
}

void Find(const string& fileName, const string& keyword) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "~ Fail : Load File \"" << fileName << "\"\n";
        return;
    }
    string line;
    int line_num = 1;
    while (getline(file, line)) {
        if (line.find(keyword) != string::npos) {
            cout << "Line " << line_num << ": " << line << "\n";
        }
        line_num++;
    }
}

int Save(const string& fileName, const string& newFileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "~ Fail : Load Existing File \"" << fileName << "\"\n";
        return 0;
    }
    ofstream newFile(newFileName);
    if (!newFile.is_open()) {
        cout << "~ Fail : Load New File \"" << newFileName << "\"\n";
        return 0;
    }
    string content;
    while (getline(file, content)) {
        newFile << content << "\n";
    }
    return 1;
}