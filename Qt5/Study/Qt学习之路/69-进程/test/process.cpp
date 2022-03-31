#include "process.h"
#include <QProcess>
#include <QTextCodec>
#include <QDebug>

//QProcess提供了同步函数：

//waitForStarted()：阻塞到进程开始；
//waitForReadyRead()：阻塞到可以从进程的当前读通道读取新的数据；
//waitForBytesWritten()：阻塞到数据写入进程；
//waitForFinished()：阻塞到进程结束；

//QProcess继承自QIODevice，因此QProcess也可以作为QXmlReader的输入
//或者直接使用QNetworkAccessManager将其生成的数据上传到网络


Process::Process(QWidget *parent)
    : QWidget(parent)
{
    QString program = "C:/Windows/System32/cmd.exe";
    QStringList arguments;
    arguments << "/c" << "dir" << "C:\\";
    QProcess *cmdProcess = new QProcess;
    connect(cmdProcess, &QProcess::readyRead, [=](){
        //Windows 控制台的默认编码是 GBK，
        //为了避免出现乱码，我们必须设置文本的编码方式。
        QTextCodec *codec = QTextCodec::codecForName("GBK");
        QString dir = codec->toUnicode(cmdProcess->readAll());
        qDebug() << dir;
    });

    cmdProcess->start(program, arguments);
}

Process::~Process()
{
}

