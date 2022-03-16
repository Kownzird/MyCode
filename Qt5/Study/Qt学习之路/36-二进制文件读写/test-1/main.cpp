
#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>

//用于二进制的流QDataStream
//用于文本流的QTextStream
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);
    out << QString("The answer is");
    out << (qint32)42;

//    file.flush();
    file.close();



    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    QString str;
    qint32 num;
    in >> str >> num;  //须按照写入的顺序，将数据读取出来
    qDebug() << "str=" << str;
    qDebug() << "num=" << num;

    file.close();


    return a.exec();
}
