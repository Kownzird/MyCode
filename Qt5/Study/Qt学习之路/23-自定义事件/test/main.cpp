#include "qtcustomevent.h"
#include "customevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QtCustomEvent qce(&a);
    qce.show();

    return a.exec();
}
