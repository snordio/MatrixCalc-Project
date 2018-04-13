#include <QApplication>
#include <QIcon>
#include "MVC/header/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mv;
    mv.setWindowTitle("Matrix Calculator");
    mv.setWindowIcon(QIcon(QPixmap(":/icon")));
    mv.show();
    return a.exec();
}
