
#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString data = "data";

    //用魔术数字判断二进制文件是否合法
    QFile file("file.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);

    //写入魔术数字和版本
    out << (qint32)0xA0B0C0D0;
    out << (qint32)123;
    out.setVersion(QDataStream::Qt_5_9);

    //写入数据
    out << data;

    file.close();



    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    //检查魔术数字
    qint32 magic;
    in >> magic;
    if(magic != 0xA0B0C0D0){
        qDebug() << "Bad file format";
    }

    //检查版本
    qint32 version;
    in >> version;
    if(version < 100){
        qDebug() << "Bad file too old";
    }

    if(version > 123){
        qDebug() << "Bad file too new";
    }

    if(version < 110){
        in.setVersion(QDataStream::Qt_4_0);
    }else {
        in.setVersion(QDataStream::Qt_5_9);
    }

    QString recv;
    in >> recv;
    qDebug() << recv;

    return a.exec();
}
