#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton button("Hello World!");
    button.setToolTip("Click me!");

    button.resize(200, 50);
    button.move(50, 50);

    button.show();

    return app.exec();
}
