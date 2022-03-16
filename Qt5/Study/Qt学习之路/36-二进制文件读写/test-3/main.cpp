
#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("file.dat");
    file.open(QIODevice::ReadWrite);

    QDataStream stream(&file);
    QString str = "The answer is 42";
    QString strout;

    //流的游标会随着输出向后移动。
    //当使用<<操作符输出之后，流的游标已经到了最后，
    //此时再去读，不能读取到内容
//    stream << str;
//    file.flush();
//    stream >> strout;

    stream << str;
    stream.device()->seek(0);
    stream >> strout;

    qDebug() << strout;

    file.close();

    return a.exec();
}
