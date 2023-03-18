#include "header.h"

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
    QString contents = text->toPlainText();
    QTextEdit *print = new QTextEdit();

    print->setWindowTitle("Print File Contents");
    print->setPlainText(contents);
    print->resize(500,300);     // QMessageBox::information 출력시 세로로 길게 출력되는 점을 텍스트 편집기를 새로 열어 보여줌으로 filePrint 기능 개선
    print->show();
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
    contents.remove(del);   //contents에서 del을 제거
    text->setText(contents);
}
void fileFind(QTextEdit *text){
    QString contents = text->toPlainText();
    QString find = QInputDialog::getText(nullptr, "Find", "");   // 찾을 단어
    if(find.isEmpty())
            return;

    QTextEdit *findList = new QTextEdit();  // find가 포함된 문장을 findList라는 텍스트 창에 추가
    QString results;

    QRegularExpression re(find, QRegularExpression::CaseInsensitiveOption);
    QTextStream textStream(&contents);

    while (!textStream.atEnd()) {
        QString line = textStream.readLine();
        QRegularExpressionMatch match = re.match(line);
        if (match.hasMatch()) {
            results.append("FOUND : " + line + "\n\n");     //find가 있으면 line을 QString에 append
        }
    }
    findList->setWindowTitle("File Contents Find");
    findList->setPlainText(results);    // QString을 텍스트 편집기 findList에 옮겨옴
    findList->resize(500, 300);
    findList->show();
}
void fileSave(QTextEdit *text)
{
    QString newFile = QFileDialog::getSaveFileName(nullptr, "Save File", "", "Text files (*.txt)"); // 새로 저장할 file

    if (newFile.isEmpty())
        return;

    QFile file(newFile);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "~ FAIL", "File Save");
        return;
    }

    QTextStream out(&file);
    out << text->toPlainText();

    file.close();

    QMessageBox::information(nullptr, "~ SUCCESS", "File Save !");
}
void fileInsert(QTextEdit *text){
    QString insert = QInputDialog::getText(nullptr, "Insert", "");
    QString contents = text->toPlainText();
    if(insert.isEmpty()){
        return;
    }
    contents.append("\n" + insert); // insert를 contents에 줄바꿈하여 append
    text->setText(contents);
}
