#include <QApplication>
#include "mylistview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyListView w;
    w.show();

    return a.exec();
}
