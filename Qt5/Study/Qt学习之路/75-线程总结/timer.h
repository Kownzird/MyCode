

// 最错误的代码
while (condition) {
    doWork();
    sleep(1); // C 库里面的 sleep(3) 函数
}


// 错误的代码
class Thread : public QThread {
protected:
    void run() {
        while (condition) {
            // 注意，如果我们要在别的线程修改 condition，那么它也需要加锁
            doWork();
            sleep(1); // 这次是 QThread::sleep()
        }
    }
};


//最好最简单的实现是使用定时器，比如QTimer，设置 1s 超时，然后将doWork()作为槽：
class Worker : public QObject
{
Q_OBJECT
public:
    Worker()
    {
        connect(&timer, SIGNAL(timeout()), this, SLOT(doWork()));
        timer.start(1000);
    }
private slots:
    void doWork()
    {
        /* ... */
    }
private:
    QTimer timer;
};