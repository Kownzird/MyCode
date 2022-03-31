#include "mainwindow.h"
#include <QProcess>
#include <QSharedMemory>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QPixmap>
#include <QBuffer>
#include <QDebug>

//Qt 提供了四种进程间通信的方式：

//1.使用共享内存（shared memory）交互：这是 Qt 提供的一种各个平台均有支持的进程间交互的方式。

//2.TCP/IP：其基本思想就是将同一机器上面的两个进程一个当做服务器，
//一个当做客户端，二者通过网络协议进行交互。除了两个进程是在同一台机器上，
//这种交互方式与普通的 C/S 程序没有本质区别。Qt 提供了 QNetworkAccessManager 对此进行支持。

//3.D-Bus：freedesktop 组织开发的一种低开销、低延迟的 IPC 实现。Qt 提供了 QtDBus 模块，
//把信号槽机制扩展到进程级别（因此我们前面强调是“普通的”信号槽机制无法实现 IPC），
//使得开发者可以在一个进程中发出信号，由其它进程的槽函数响应信号。

//4.QCOP（Qt COmmunication Protocol）：QCOP 是 Qt 内部的一种通信协议，
//用于不同的客户端之间在同一地址空间内部或者不同的进程之间的通信。
//目前，这种机制只用于 Qt for Embedded Linux 版本。



//这个键就可以看做指针的名字。
//多个线程或进程使用同一个共享内存段时，该键值必须相同
const char *KEY_SHARED_MEMORY = "Shared";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), sharedMemory(new QSharedMemory(KEY_SHARED_MEMORY, this))
{
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);

    QPushButton *saveButton = new QPushButton(tr("Save"), this);
    mainLayout->addWidget(saveButton);
    QLabel *picLabel = new QLabel(this);
    mainLayout->addWidget(picLabel);
    QPushButton *loadButton = new QPushButton(tr("load"), this);
    mainLayout->addWidget(loadButton);

    connect(saveButton, &QPushButton::clicked, [=](){
        if(sharedMemory->isAttached()){
            sharedMemory->detach();
        }
        QString fileName = QFileDialog::getOpenFileName(this);
        QPixmap pixmap(fileName);
//        picLabel->setPixmap(pixmap); //测试图片显示

        //利用QBuffer将图片数据作为char *格式
        QBuffer buffer;
        QDataStream out(&buffer);
        buffer.open(QBuffer::ReadWrite);
        out << pixmap;

        int size = buffer.size();
        //请求系统创建一个共享内存段
        if(!sharedMemory->create(size)){
            qDebug() << tr("Create Error") << sharedMemory->errorString();
        }else{
            sharedMemory->lock();
            char *to = static_cast<char *>(sharedMemory->data());
            const char *from = buffer.data().constData();
            memcpy(to, from, qMin(size, sharedMemory->size()));
            sharedMemory->unlock();

            qDebug() << "Save image done!";
        }
    });

    connect(loadButton, &QPushButton::clicked, [=](){
        if(!sharedMemory->isAttached()){
            qDebug() << tr("Attach Error") << sharedMemory->errorString();
        }else{
            //QBuffer读取二进制数据
            QBuffer buffer;
            QDataStream in(&buffer);
            QPixmap pixmap;
            sharedMemory->lock();
            buffer.setData(static_cast<const char *>(sharedMemory->constData()), sharedMemory->size());
            buffer.open(QBuffer::ReadWrite);
            in >> pixmap;
            sharedMemory->unlock();
            sharedMemory->detach();
            picLabel->setPixmap(pixmap);
        }
    });
}

MainWindow::~MainWindow()
{
}

