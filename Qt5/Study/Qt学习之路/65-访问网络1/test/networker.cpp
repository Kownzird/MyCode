#include "networker.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>

//辅助类是私有的，用户不能使用它，
//所以针对这个辅助类的修改不会影响到外部类，从而保证了二进制兼容
class NetWorker::Private
{
public:
    //NetWorker::Private需要其被辅助的类NetWorker的指针，
    //目的是作为QNetworkAccessManager的 parent，
    //以便NetWorker析构时能够自动将QNetworkAccessManager析构
    Private(NetWorker *q) : manager(new QNetworkAccessManager(q)){}

    QNetworkAccessManager *manager;
};



NetWorker *NetWorker::instance(){
    static NetWorker netWorker;
    return &netWorker;
}



NetWorker::NetWorker(QObject *parent) : QObject(parent), d(new NetWorker::Private(this)){
    connect(d->manager, &QNetworkAccessManager::finished,this, &NetWorker::finished);
}

//NetWorker::Private是在堆上创建的，并且没有继承QObject，
//所以我们必须手动调用delete运算符
NetWorker::~NetWorker(){
    delete d;
    d = 0;
}


//直接将用户提供的 URL 字符串提供给底层的QNetworkAccessManager，
//实际上是将操作委托给底层QNetworkAccessManager进行
void NetWorker::get(const QString &url){
    d->manager->get(QNetworkRequest(QUrl(url)));
}
