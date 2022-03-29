#ifndef NETWORKER_H
#define NETWORKER_H

#include <QObject>

class QNetworkReply;
class NetWorker : public QObject
{
    Q_OBJECT
public:
    //instance()函数用来获得这唯一的实例
    static NetWorker * instance();
    ~NetWorker();

    //执行 HTTP GET 操作
    void get(const QString &url);

signals:
    void finished(QNetworkReply *reply);

private:
    //内部类（辅助类）
    class Private;
    friend class Private;
    Private *d;

    //单例模式，要求构造函数、拷贝构造函数和赋值运算符都是私有的
    //将它所修饰的函数声明为 deleted（这是 C++11 的新特性）。
    //如果编译器支持= delete语法，则这个宏将会展开为= delete，否则则展开为空
    explicit NetWorker(QObject *parent = 0);
    NetWorker(const NetWorker &) Q_DECL_EQ_DELETE;
    NetWorker& operator=(NetWorker rhs) Q_DECL_EQ_DELETE;
};



#endif // NETWORKER_H
