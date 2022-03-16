
#include <QApplication>
#include <QFile>
#include <QDataStream>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file("file.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        QTextStream out(&file);
        out << "The answer is " << 42;
    }

    file.close();


    QFile data("file.txt");
    if(data.open(QIODevice::ReadOnly)){
        QTextStream in(&data);
        in.setCodec("UTF-8");
        QString str;
        int ans = 0;
//        in >> str >> ans;  //数字已转成字符串，重定向会以空白字符作为分隔符
        str = in.readLine();
        qDebug() << str;
        qDebug() << ans;
    }

    data.close();

    return a.exec();
}
