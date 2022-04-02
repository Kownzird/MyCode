#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QObject>
#include <QThread>

class WorkThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread(QObject *parent = nullptr);

protected:
    void run();

signals:
    void done();

};

#endif // WORKTHREAD_H
