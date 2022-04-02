#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

//class QScopedPointer;
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(QObject *parent = nullptr);

signals:
    void aSignal();

protected:
    void run();

private:
    //obj、otherObj和yetAnotherObj的线程依附性:
    //是调用了MyThread构造函数的线程创建了它们。
    //因此，这些对象不在MyThread所表示的线程，而是在创建了MyThread的那个线程中

    //QObject的线程依附性是可以改变的，方法是调用QObject::moveToThread()函数。
    //由于QObject不是线程安全的，所以我们只能在该对象所在线程上调用这个函数
    QObject obj;
    QObject *otherObj;
//    QScopedPointer yetAnotherObj;

};

#endif // MYTHREAD_H
