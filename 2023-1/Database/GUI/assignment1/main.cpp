#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QInputDialog>

void fileLoad(QTextEdit *textEdit);
void filePrint(QTextEdit *textEdit);
void fileUpdate(QTextEdit *textEdit);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    QTextEdit *textEdit = new QTextEdit();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(textEdit);

    QPushButton *loadButton = new QPushButton("File Load");
    QAbstractButton::connect(loadButton, &QPushButton::clicked, [textEdit]() { fileLoad(textEdit); });
    layout->addWidget(loadButton);

    QPushButton *printButton = new QPushButton("File Print");
    QAbstractButton::connect(printButton, &QPushButton::clicked, [textEdit]() { filePrint(textEdit); });
    layout->addWidget(printButton);

    QPushButton *updateButton = new QPushButton("File Update");
    QAbstractButton::connect(updateButton, &QPushButton::clicked, [textEdit]() { fileUpdate(textEdit); });
    layout->addWidget(updateButton);

    window->setLayout(layout);
    window->show();

    return app.exec();
}
void fileLoad(QTextEdit *textEdit)
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open File", "", "Text Files (*.txt)");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Could not open file.");
        return;
    }

    QTextStream in(&file);
    textEdit->setText(in.readAll());
}

void filePrint(QTextEdit *textEdit)
{
    QString text = textEdit->toPlainText();
    QMessageBox::information(nullptr, "File Contents", text);
}

void fileUpdate(QTextEdit *textEdit)
{
    QString target = QInputDialog::getText(nullptr, "Target", "");
    if (target.isEmpty()) {
        return;
    }

    QString replace = QInputDialog::getText(nullptr, "Replace", "");
    if (replace.isNull()) {
        return;
    }

    QString contents = textEdit->toPlainText();
    contents.replace(target, replace);

    QTextCursor cursor = textEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.removeSelectedText();
    cursor.insertText(contents);

    QMessageBox::information(nullptr, "Success", "File updated successfully.");
}

