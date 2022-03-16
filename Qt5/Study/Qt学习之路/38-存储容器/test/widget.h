#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDate>

struct QMovie{
    int id;
    QString title;
    QDate releaseDate;

    friend QDataStream& operator <<(QDataStream& out, const QMovie& movie);
    friend QDataStream& operator >>(QDataStream& in, const QMovie& movie);
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
