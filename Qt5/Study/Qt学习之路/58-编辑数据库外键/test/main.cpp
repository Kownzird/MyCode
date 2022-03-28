#include "sqldatabase.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SqlDatabase sdb;
    sdb.show();

    return a.exec();
}
