#ifndef HEADER_H
#define HEADER_H

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

#endif // HEADER_H
