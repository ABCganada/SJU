#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

void fileLoad(QTextEdit *textEdit);
void filePrint(QTextEdit *textEdit);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget *window = new QWidget();
    QTextEdit *textEdit = new QTextEdit();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(textEdit);

    QPushButton *loadButton = new QPushButton("Load File");
    QAbstractButton::connect(loadButton, &QPushButton::clicked, [textEdit]() { fileLoad(textEdit); });
    layout->addWidget(loadButton);

    QPushButton *printButton = new QPushButton("Print File");
    QAbstractButton::connect(printButton, &QPushButton::clicked, [textEdit]() { filePrint(textEdit); });
    layout->addWidget(printButton);

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
