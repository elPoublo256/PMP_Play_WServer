#include "mainwindow.h"
#include <QApplication>
#include <myserver.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyServer w(2323);
    w.show();

    return a.exec();
}
