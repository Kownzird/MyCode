#include "showtableform.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ShowTableForm w;
    w.show();
    return a.exec();
}
