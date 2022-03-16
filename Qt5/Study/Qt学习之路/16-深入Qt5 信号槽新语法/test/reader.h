#ifndef READER_H
#define READER_H

#include <QObject>
#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT
public:
    Reader(){}

    void receiveNewspaper(const QString& name)
    {
        qDebug() << "Receive Newspaper "<< name;
    }

    void receiveNewspaperDate(const QString& name, const QString& date)
    {
        qDebug() << "Receive Newspaper "<< name;
        qDebug() << "Date:" << date;
    }

signals:

};

#endif // READER_H
