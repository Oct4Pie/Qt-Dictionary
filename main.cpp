#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QFile qss(":/style");
    if(!qss.open(QIODevice::ReadOnly)) {
        qDebug() << "error: " << qss.errorString();
    }
    w.setStyleSheet( qss.readAll());
    w.show();
    return a.exec();
}
