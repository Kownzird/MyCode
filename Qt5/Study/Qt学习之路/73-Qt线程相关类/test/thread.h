#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);

protected:
    void run();

};

#endif // THREAD_H
