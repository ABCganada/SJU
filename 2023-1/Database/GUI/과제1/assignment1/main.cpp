#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void fileLoad(QTextEdit *text);     // file Load 함수
void filePrint(QTextEdit *text);    // file Print 함수
void fileUpdate(QTextEdit *text);   // file Update 함수
void fileDelete(QTextEdit *text);   // file Delete 함수
void fileFind(QTextEdit *text);     // file Find 함수
void fileSave(QTextEdit *textEdit);     // file Save 함수
void fileInsert(QTextEdit *text);   // file Insert 함수

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

void fileLoad(QTextEdit *text){
    // QFileDialog : 파일을 선택하는 GUI Interface를 제공
    // getOpenFileName() -> nullptr : 부모 위젯 없음. 2,3번째 argument : 메세지. 4번째 : 텍스트 파일을 가져올 거임.
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt)");
    if (fileName.isEmpty()) {   // fileName을 가져오지 못 했으면 그냥 리턴. 함수 종료.
        return;
    }

    // QFile : 파일을 읽고 쓰기 위한 Interface.
    QFile file(fileName);   // fileName을 Qfile 이용해 open한다.
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {    // 텍스트 파일을 읽을 수 없을 경우 에러 경고.
        QMessageBox::warning(nullptr, "~ FAIL", "File Load !");
        return;
    }

    // QTextStream : 텍스트를 읽고 쓰기 위한 Interface 제공
    QTextStream in(&file); // 성공적으로 파일을 로드하면 QFile의 file을 QTextStream in에 저장.
    text->setText(in.readAll());    // QTextEdit의 textEdit 위젯에 QTextStream의 in의 콘텐츠 전체를 세팅.
    QMessageBox::information(nullptr, "~ SUCCESS", "File Load !");
}
void filePrint(QTextEdit *text){
    // toPlainText() : TextEdit의 글자들을 가져옴.
    QString contents = text->toPlainText(); // toPlainText() 메서드를 사용해 QTextEdit 위젯의 텍스트 내용을 가져와 contents에 저장.
    QMessageBox::information(nullptr, "~ SUCCESS : File Print", contents);   // 메세지 박스를 열어 contents를 표시함.
}
void fileUpdate(QTextEdit *text){
    // QInputDialog : User로부터 text, 정수 등을 입력 받음.
    // getText() : text를 받겠다.
    QString target = QInputDialog::getText(nullptr, "Target", "");  // 타겟 string 입력
    if (target.isEmpty()) {
        return;
    }

    QString replace = QInputDialog::getText(nullptr, "Replace", "");    // 타겟을 대체할 string 입력
    if (replace.isEmpty()) {
        return;
    }

    QString contents = text->toPlainText(); // 함수 파라미터 textEdit의 텍스트 내용을 contents에 저장.
    contents.replace(target, replace);  // contents 속 target을 replace로 대체

    // QTextCursor : QTextDocuments에 액세스하고 수정할 수 있는 API 제공.
    QTextCursor cursor = text->textCursor();    // cursor가 현재 textEdit에 액세스함.
    cursor.select(QTextCursor::Document);   // 현재 Document를 select함.
    cursor.removeSelectedText();    // seleced text를 지움.
    cursor.insertText(contents);    // 대체된 contents를 cursor에 넣어 수정함.

    QMessageBox::information(nullptr, "~ SUCCESS", "File Update!");
}
void fileDelete(QTextEdit *text){
    QString del = QInputDialog::getText(nullptr, "Delete", "");
    QString contents = text->toPlainText();
    if(del.isEmpty()){
        return;
    }
    contents.remove(del);
    text->setText(contents);
}
void fileFind(QTextEdit *text){
    QString contents = text->toPlainText();
    QString find = QInputDialog::getText(nullptr, "Find", "");   // 찾을 단어
    QStringList results;

    QRegularExpression re(find, QRegularExpression::CaseInsensitiveOption);
    QTextStream textStream(&contents);

    while (!textStream.atEnd()) {
        QString line = textStream.readLine();
        QRegularExpressionMatch match = re.match(line);
        if (match.hasMatch()) {
            results.append("FOUND : " + line);
        }
    }

    if (results.isEmpty())
        QMessageBox::information(nullptr, "~ FAIL", "File Find");
    else
        QMessageBox::information(nullptr, "~ SUCCESS", results.join("\n"));
}
void fileSave(QTextEdit *text)
{
    QString newFile = QFileDialog::getSaveFileName(nullptr, "Save File", "", "Text files (*.txt)");

    if (newFile.isEmpty())
        return;

    QFile file(newFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Failed to save file.");
        return;
    }

    QTextStream out(&file);
    out << text->toPlainText();

    file.close();

    QMessageBox::information(nullptr, "File Saved", "The file has been saved.");
}
void fileInsert(QTextEdit *text){
    QString insert = QInputDialog::getText(nullptr, "Insert; append text", "");
    QString contents = text->toPlainText();
    if(insert.isEmpty()){
        return;
    }
    contents.append("\n" + insert);
    text->setText(contents);
}
