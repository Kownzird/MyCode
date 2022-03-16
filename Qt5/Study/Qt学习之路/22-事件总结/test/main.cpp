#include "label.h"
#include "eventfilter.h"

#include <QApplication>

//全局事件过滤器被第一个调用，
//之后是该对象上面的事件过滤器，
//其次是event()函数，
//最后是特定的事件处理函数。

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Label label;
    label.show();
    a.installEventFilter(new EventFilter(&label, &label));
    return a.exec();
}
