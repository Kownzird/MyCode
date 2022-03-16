#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QObject>

class EventFilter : public QObject
{
    Q_OBJECT
public:
    EventFilter(QObject *watched, QObject *parent);

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QObject *m_watched;

};

#endif // EVENTFILTER_H
