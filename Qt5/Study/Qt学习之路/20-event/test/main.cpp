#include "customwidget.h"
#include "customtextedit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    CustomWidget cw;
//    cw.show();

    CustomTextEdit cted;
    cted.show();


    return a.exec();
}
