#include "widget.h"
#include<iostream>
#include<QFile>
#include<QDebug>

using namespace std;
QDataStream& operator <<(QDataStream& out, const QMovie& movie)
{
    out << movie.id << movie.title << movie.releaseDate;
    return out;
}

QDataStream& operator >>(QDataStream& in, QMovie& movie)
{
    in >> movie.id >> movie.title >> movie.releaseDate;
    return in;
}

QString onlyLetters(const QString& in)
{
    QString out;
    for(int j=0; j<in.size(); j++){
        if(in[j].isLetter()){
            out += in[j];
        }
    }
    return out;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //e.g.1
    QList<QMovie> movs;

    QMovie m1;
    QMovie getm1;
    m1.id = 99;
    m1.title = "Movie Title";
    m1.releaseDate = QDate::currentDate();

    movs.append(m1);
    qDebug() << movs[0].id << movs[0].title << movs[0].releaseDate;

    QFile file("File.txt");
    file.open(QIODevice::ReadWrite);
    QDataStream stream(&file);

    stream << m1;
    stream.device()->seek(0);
    stream >> getm1;
    qDebug() << getm1.id << getm1.title << getm1.releaseDate;

    file.close();

    //e.g.2
    QString src = "A1B2C3D4E5";
    QString des = onlyLetters(src);
    qDebug() << des;


}

Widget::~Widget()
{
}


