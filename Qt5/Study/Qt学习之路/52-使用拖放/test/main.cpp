#include "mainwindow.h"
#include "projectlistwidget.h"
#include "widget.h"
#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow m;
//    m.show();

    Widget w;
    w.show();

    return a.exec();
}
