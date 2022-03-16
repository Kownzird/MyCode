#include "widget.h"

#include <QApplication>
#include "newspaper.h"
#include "reader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QDate d1(2022, 2, 1);

    Newspaper newspaper("Newspaper_A",d1);
    Reader reader;

    //Newspaper类中有重载信号，可使用函数指针来指明具体是哪一个信号
//    void (Newspaper::*newPaperNameDate)(const QString &, const QDate &) = &Newspaper::newPaper;
//    QObject::connect(&newspaper, newPaperNameDate, &reader, &Reader::receiveNewspaper);

    QObject::connect(&newspaper,
                     static_cast<void (Newspaper:: *)(const QString &, const QDate &)>(&Newspaper::newPaper),
                     &reader,
                     &Reader::receiveNewspaper);
    newspaper.send();

    Widget w;
    w.show();

    return a.exec();
}
