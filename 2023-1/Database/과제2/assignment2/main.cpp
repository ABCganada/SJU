#include "header.h"
#include "function.cpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);   // app 생성

    // 기본 틀 구성
    QWidget *window = new QWidget();    // window 생성
    QTextEdit *textEdit = new QTextEdit();  // Text 편집기 생성, 일반 텍스트와 리치 텍스트를 편집하고 표시하는 데 사용되는 위젯.
    QVBoxLayout *layout = new QVBoxLayout();    // 위젯을 세로로 정렬함. 텍스트편집기와 함수 버튼을 세로로 정렬할 것.
    layout->addWidget(textEdit);    // 텍스트 편집기 레이아웃에 추가

    QPushButton *loadButton = new QPushButton("File Load"); // file Load 기능 버튼
    QAbstractButton::connect(loadButton, &QPushButton::clicked, [textEdit]() { fileLoad(textEdit); });  // 버튼 클릭시 fileLoad 실행
    layout->addWidget(loadButton);  // fileLoad 레이아웃에 추가

    QPushButton *printButton = new QPushButton("File Print");   // file Print 기능 버튼
    QAbstractButton::connect(printButton, &QPushButton::clicked, [textEdit]() { filePrint(textEdit); });
    layout->addWidget(printButton);

    QPushButton *updateButton = new QPushButton("File Update"); // file Update 기능 버튼
    QAbstractButton::connect(updateButton, &QPushButton::clicked, [textEdit]() { fileUpdate(textEdit); });
    layout->addWidget(updateButton);

    QPushButton *deleteButton = new QPushButton("File Delete"); // file Delete 기능 버튼
    QAbstractButton::connect(deleteButton, &QPushButton::clicked, [textEdit]() {fileDelete(textEdit); });
    layout->addWidget(deleteButton);

    QPushButton *findButton = new QPushButton("File Find"); // file Find 기능 버튼
    QAbstractButton::connect(findButton, &QPushButton::clicked, [textEdit]() {fileFind(textEdit); });
    layout->addWidget(findButton);

    QPushButton *saveButton = new QPushButton("File Save"); // file Save 기능 버튼
    QAbstractButton::connect(saveButton, &QPushButton::clicked, [textEdit]() {fileSave(textEdit); });
    layout->addWidget(saveButton);

    QPushButton *insertButton = new QPushButton("File Insert"); // file Insert 기능 버튼
    QAbstractButton::connect(insertButton, &QPushButton::clicked, [textEdit]() {fileInsert(textEdit); });
    layout->addWidget(insertButton);

    QPushButton *exitButton = new QPushButton("Exit"); // program Exit 기능 버튼
    QAbstractButton::connect(exitButton, &QPushButton::clicked, &app, QApplication::quit);  // 클릭시 app 종료
    layout->addWidget(exitButton);


    window->setLayout(layout);  // *window의 layout을 *layout으로 설정. *layout에 있는 위젯들이 *window에 깔리게 됨.
    window->show();             // user에게 *window를 표시함.

    return app.exec();  // app 실행
}
