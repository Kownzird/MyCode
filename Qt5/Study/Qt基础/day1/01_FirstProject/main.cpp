#include "mywidget.h"

#include <QApplication> //包含一个应用程序类的头文件

int main(int argc, char *argv[])
{
    //a应用程序对象，在Qt中，应用程序对象有且仅有一个
    QApplication a(argc, argv);

    //窗口对象,myWidget父类 --> QWidget
    myWidget w;
    //窗口对象默认不会显示，必须要调用show方法显示窗口
    w.show();

    //让应用程序对象a进入消息循环
    //让代码阻塞到这行
    return a.exec();
}
