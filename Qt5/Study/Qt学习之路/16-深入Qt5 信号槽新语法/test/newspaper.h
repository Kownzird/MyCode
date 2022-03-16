#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include <QObject>
#include <QDate>

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString& name):m_name(name){}
    Newspaper(const QString& name, const QDate& date):m_name(name),m_date(date)
    {

    }

    void send()
    {
        //选择发送的是哪个信号
        emit newPaper(m_name,m_date);
    }

signals:
    //有重载信号
    void newPaper(const QString& name);
    void newPaper(const QString& name, const QDate& date);

private:
    QString m_name;
    QDate m_date;

};

#endif // NEWSPAPER_H
