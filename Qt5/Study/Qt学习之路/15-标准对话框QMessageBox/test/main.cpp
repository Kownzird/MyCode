#include "mainwindow.h"

#include <QApplication>

#include <QSpinBox>
#include <QSlider>
#include <QBoxLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
